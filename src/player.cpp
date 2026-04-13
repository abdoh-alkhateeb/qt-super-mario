#include "player.hpp"
#include <QMessageBox>
#include <QApplication>
#include <QBrush>

Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsRectItem(parent), velocityY(0), onGround(false) {
  setRect(0, 0, 30, 60);
  setBrush(Qt::red);
  setPos(300, 0);

  setFlag(QGraphicsItem::ItemIsFocusable);
  setFocus();
}

void Player::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Left) {
    moveBy(-10, 0);
  }
  if (event->key() == Qt::Key_Right) {
    moveBy(10, 0);
  }
  if (event->key() == Qt::Key_Space && onGround) {
    velocityY = -15;
  }
}

void Player::updateState() {
  velocityY += 1;
  onGround = false;

  qreal previousY = y();

  moveBy(0, velocityY);

  if (y() > 400) {
    QMessageBox::information(nullptr, "Game Over", "You lost!");
    QApplication::quit();
    return;
  }

  QList<QGraphicsItem*> items = collidingItems();

  for (QGraphicsItem* item : items) {
    if (velocityY > 0 &&
        previousY + boundingRect().height() <= item->y()) {

      setY(item->y() - boundingRect().height());
      velocityY = 0;
      onGround = true;
    }
  }
}
