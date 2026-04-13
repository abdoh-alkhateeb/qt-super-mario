#include "player.hpp"

#include <QApplication>
#include <QBrush>
#include <QGraphicsScene>
#include <QMessageBox>

Player::Player(QGraphicsItem* parent)
    : QObject(),
      QGraphicsRectItem(parent),
      velocityY(0),
      onGround(false),
      hasLost(false) {
  setRect(0, 0, 30, 60);
  setBrush(Qt::red);
Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent), velocityY(0), onGround(false) {
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
  if (event->key() == Qt::Key_Space && onGround) {
    velocityY = -15;
  }
}

void Player::updateState() {
  if (hasLost) {
    return;
  }

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

  if (scene() && sceneBoundingRect().top() > scene()->sceneRect().bottom()) {
    hasLost = true;
    QMessageBox::information(nullptr, "Qt Super Mario", "You lost!");
    QApplication::quit();
  }
}
