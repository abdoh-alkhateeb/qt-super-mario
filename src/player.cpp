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
  for (QGraphicsItem* item : items) {
    if (velocityY >= 0 && y() + boundingRect().height() <= item->y() + item->boundingRect().height()) {
      setY(item->y() - boundingRect().height());
      velocityY = 0;
      onGround = true;
      break;
    }
  }
  if (items.size() != 0) {
    QGraphicsItem* item = items[0];
    setY(item->y() - boundingRect().height());

    velocityY = 0;
    onGround = true;
  }
  if (scene() && y() > scene()->height()) {
    QMessageBox::information(nullptr, "Game Over", "You lost!");
    QApplication::quit();
  }
}
