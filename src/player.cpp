#include "player.hpp"
#include <QBrush>
std::array<bool, 2> isBeingHeld = {0, 0};

Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent), velocityY(0), onGround(false) {
  setPixmap(QPixmap("assets/player.png"));
  setPos(300, 0);
 
  setFlag(QGraphicsItem::ItemIsFocusable);
  setFocus();
}

void Player::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Left) {
    isBeingHeld[(int) Direction::Left] = true;
  }
  if (event->key() == Qt::Key_Right) {
    isBeingHeld[(int) Direction::Right] = true;
  }
  if (event->key() == Qt::Key_Space && onGround) {
    velocityY = -15;
  }
}

void Player::keyReleaseEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Left) isBeingHeld[(int) Direction::Left] = false;
    if (event->key() == Qt::Key_Right) isBeingHeld[(int) Direction::Right] = false;
}

void Player::updateState() {

  // This means that if the player is not touching anything, these 3 lines of code will repeat over and over
  // Hence, the player will accelerate downwards, giving a gravitational effect.
  
    if (isBeingHeld[(int)Direction::Left])
      velocityX = -5;
    else if (isBeingHeld[(int)Direction::Right])
      velocityX = 5;
    else
      velocityX = 0;

  velocityY += 1;
  onGround = false;
  moveBy(velocityX, velocityY);


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
