#include "player.hpp"
#include <QBrush>
#include <QMessageBox>

Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsRectItem(parent), velocityY(0), onGround(false), gameOver(false) {
  setRect(0, 0, 30, 60);
  setBrush(Qt::red);
  setPos(130, 180);
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
  if (gameOver) return;

  velocityY += 1;
  onGround = false;
  moveBy(0, velocityY);

  QList<QGraphicsItem*> items = collidingItems();
  if (items.size() != 0) {
    QGraphicsItem* item = items[0];
    setY(item->y() - boundingRect().height());
    velocityY = 0;
    onGround = true;
  }

  if (pos().y() > scene()->sceneRect().height()) {
    gameOver = true;
    QMessageBox::information(nullptr, "Game Over", "You lost!");
  }
}
