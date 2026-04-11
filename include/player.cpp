#include "player.hpp"
#include <QMessageBox>
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

  
  QList<QGraphicsItem*> items = collidingItems();
  if (!items.isEmpty()) {
    QGraphicsItem* item = items[0]; 

    qreal platformTop = item->sceneBoundingRect().top();
    qreal playerBottom = sceneBoundingRect().bottom();

  
    if (velocityY > 0 && playerBottom <= platformTop + velocityY + 10) {
      setY(platformTop - boundingRect().height());
      velocityY = 0;
      onGround = true;
    }
  }


  if (y() > 480) {
    setPos(300, 0);
    velocityY = 0;
    QMessageBox::information(nullptr, "Game Over", "You lost!");
  }
}
