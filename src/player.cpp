#include "player.hpp"

#include <QApplication>

#include <QMessageBox>

#include <QGraphicsScene>

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
  moveBy(0, velocityY);

  // Check if player fell off screen
  if (y() > scene()->sceneRect().height()) {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Game Over");
    msgBox.setText("You lost!");
    msgBox.exec();
    QApplication::quit();   // or reset position — depends on preference
    return;
  }

  QList<QGraphicsItem*> items = collidingItems();

for (QGraphicsItem* item : items) {
    // Make sure we land on top, not clip through sides
    if (y() + boundingRect().height() <= item->y() + item->boundingRect().height()) {
      setY(item->y() - boundingRect().height());
      velocityY = 0;
      onGround = true;
      break;
    }
  }
}
