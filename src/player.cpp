#include "player.hpp"
#include <QBrush>
#include <QMessageBox>

Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent), velocityY(0), onGround(false) {
  setPixmap(QPixmap("assets/player.png"));
  spawnPosition();
  setFlag(QGraphicsItem::ItemIsFocusable);
  setFocus();
}

void Player::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Left && !collisionBlock) {
    moveBy(-10, 0);
  }
  if (event->key() == Qt::Key_Right && !collisionBlock) {
    moveBy(10, 0);
  }
  if (event->key() == Qt::Key_Space && onGround) {
    velocityY = -16;
  }
}

void Player::spawnPosition(){ setPos(250, 190); }

void Player::updateState() {
  velocityY += 1;
  onGround = false;
  collisionBlock = false;
  moveBy(0, velocityY);

  QList<QGraphicsItem*> items = collidingItems();

  if (items.size() != 0) {
    QGraphicsItem* item = items[0];
    if(y() + boundingRect().height()/2 <= item->y())
    {
        setY(item->y() - boundingRect().height());
        velocityY = 0;
        onGround = true; 
    }
    else
    {
      collisionBlock = true;
      if(velocityY < 0)
      {
        velocityY = 0;
        onGround = false; 
      }
    }
  }
  if (y() > 480 || y() < -100)
  {
    emit playerOutOfView();
    spawnPosition();
    velocityY = 0;
    onGround = true;
  }
}
