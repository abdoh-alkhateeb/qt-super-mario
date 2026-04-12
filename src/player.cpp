#include "player.hpp"

Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent), velocityY(0), onGround(false) {
  setPixmap(QPixmap("assets/player.png"));
  setPos(300, 0);

  setFlag(QGraphicsItem::ItemIsFocusable);
  setFocus();
}

void Player::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Left) {
    movingl = true;
  }
  if (event->key() == Qt::Key_Right) {
    movingr = true; 
  }
  if (event->key() == Qt::Key_Space && onGround) {
    velocityY = -15;
  }
}

void Player::keyReleaseEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Left)
        movingl  = false;

    if (event->key() == Qt::Key_Right)
        movingr = false;
}

bool Player::outOfScreen(){
    if (y() >  1000) return true; 
    else return false;
}

void Player::updateState() {
  if(movingr) moveBy(10,0);
  if(movingl) moveBy(-10,0);

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
}
