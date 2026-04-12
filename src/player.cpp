#include "player.hpp"
#include <QDebug>
#include <QBrush>

Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsRectItem(parent), velocityY(0), onGround(false), onPlatform(false) {
  setRect(0, 0, 30, 60);
  setBrush(Qt::red);
  setPixmap(QPixmap("assets/player.png"));
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
  if (event->key() == Qt::Key_Space && (onGround || onPlatform)) {
    velocityY = -15;
    onGround = false;
    onPlatform = false;
  }
}

void Player::updateState() {
  velocityY += 1;
  if (velocityY > 15) 
    velocityY = 15;
  moveBy(0, velocityY);
  onGround = false;
  onPlatform = false;

  QList<QGraphicsItem*> items = collidingItems();
    
  for (QGraphicsItem* item : items) {
    if (item->type() == QGraphicsRectItem::Type) {
      setY(item->y() - boundingRect().height());
      velocityY = 0;
      
      if (item->y() >= 250) {
        onGround = true;
      } else {
        onPlatform = true;
      }
      break;
    }
  }
}