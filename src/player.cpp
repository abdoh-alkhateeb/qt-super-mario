#include "player.hpp"

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

  // This means that if the player is not touching anything, these 3 lines of code will repeat over and over
  // Hence, the player will accelerate downwards, giving a gravitational effect.
  velocityY += 1;
  onGround = false;
  moveBy(0, velocityY);

  // List of items the player is colliding with. Can include the platform
  QList<QGraphicsItem*> items = collidingItems();

  if (items.size() != 0) {

    // The item is pretty much the ground
    QGraphicsItem* item = items[0];

    // This makes it so that the player lands on the platform. BoundingRect() is the rectangular object encapsulating the player.
    setY(item->y() - boundingRect().height());

    velocityY = 0;
    onGround = true;
  }
}