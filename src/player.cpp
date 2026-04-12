#include "player.hpp"

#include <QBrush>
#include <QDebug>
#include <QMessageBox>
#include <QGraphicsScene>

Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent), velocityY(0), onGround(false) {
  QPixmap pix("/mnt/c/Users/moael/Programming/mario/assets/player.png");
  if (pix.isNull()) {
    qDebug() << "Warning: player.png failed to load!";
  } else {
    qDebug() << "Player image loaded:" << pix.size();
  }
  setPixmap(pix);
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

  // Lose condition
  if (y() > scene()->sceneRect().height()) {
    QMessageBox msgBox;
    msgBox.setText("You lost!");
    msgBox.exec();

    setPos(300, 0);
    velocityY = 0;
    return;
  }

  QList<QGraphicsItem*> items = collidingItems();

  for (QGraphicsItem* item : items) {
    if (velocityY > 0 && y() + boundingRect().height() <= item->y() + 10) {
      setY(item->y() - boundingRect().height());
      velocityY = 0;
      onGround = true;
      break;
    }
  }
}