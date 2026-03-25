#include "player.hpp"

#include <QBrush>

#include<QMessageBox>

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

  QList<QGraphicsItem*> items = collidingItems();

for(auto item : items){
  if (dynamic_cast<QGraphicsRectItem*>(item)) {
    setY(item->y() - boundingRect().height());

    velocityY = 0;
    onGround = true;
  }
}
if (y() > 400) {
QMessageBox::information(nullptr, "YOU LOST HUMAN", "BUBAY");

}

}
