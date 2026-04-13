#include "player.hpp"

#include <QBrush>
#include <QGraphicsScene>

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
  const qreal previousBottom = sceneBoundingRect().bottom();

  velocityY += 1;
  onGround = false;
  moveBy(0, velocityY);

  QList<QGraphicsItem*> items = collidingItems();

  for (QGraphicsItem* item : items) {
    const QRectF itemRect = item->sceneBoundingRect();
    const QRectF playerRect = sceneBoundingRect();

    if (velocityY >= 0 &&
        previousBottom <= itemRect.top() + 5 &&
        playerRect.bottom() >= itemRect.top()) {
      setY(itemRect.top() - rect().height());
      velocityY = 0;
      onGround = true;
      break;
    }
  }
}
