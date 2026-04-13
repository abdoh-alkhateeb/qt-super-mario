#include "player.hpp"


Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent), velocityY(0), onGround(false) {
  setPixmap(QPixmap("assets/player.png"));
  setPos(400, 0);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    fellbelowBoundary=false;
}

void Player::keyPressEvent(QKeyEvent *event)
{
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

void Player::updateState()
{
    velocityY += 1;
    onGround = false;
    moveBy(0, velocityY);

    QList<QGraphicsItem *> items = collidingItems();

    if (items.size() != 0) {
        QGraphicsItem *item = items[0];
        setY(item->y() - boundingRect().height());

        velocityY = 0;
        onGround = true;
    }
    Player::CheckBoundary(); //every frame check for the boundary

 }

void Player::CheckBoundary()
{



        if(this->pos().y()>=400.0&&!fellbelowBoundary)
        {
        fellbelowBoundary=true; //so that the loop does not run every second
            emit PlayerLost();

            this->setPos(40,30); //teleport the player to a platform
        }

        if ( this->pos().y()<400.0) //enables the condition again
        {
            fellbelowBoundary = false;
        }


}
