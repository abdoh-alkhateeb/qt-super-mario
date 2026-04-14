#include "player.hpp"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QPixmap>

Player::Player(QGraphicsItem* parent)
    : QObject(),
      QGraphicsPixmapItem(parent),
      velocityY(0),
      onGround(false),
      gameOver(false),
      moveLeft(false),
      moveRight(false) {
  setPixmap(QPixmap("assets/player.png"));
  setPos(300, 0);

  setFlag(QGraphicsItem::ItemIsFocusable);
  setFocus();
}

void Player::keyPressEvent(QKeyEvent* event) {
  if (gameOver) {
    return;
  }

  if (event->isAutoRepeat()) {
    return;
  }

  if (event->key() == Qt::Key_Left) {
    moveLeft = true;
  }

  if (event->key() == Qt::Key_Right) {
    moveRight = true;
  }

  if (event->key() == Qt::Key_Space && onGround) {
    velocityY = -18;
    onGround = false;
  }
}

void Player::keyReleaseEvent(QKeyEvent* event) {
  if (event->isAutoRepeat()) {
    return;
  }

  if (event->key() == Qt::Key_Left) {
    moveLeft = false;
  }

  if (event->key() == Qt::Key_Right) {
    moveRight = false;
  }
}

void Player::updateState() {
  if (gameOver || !scene()) {
    return;
  }

  if (moveLeft) {
    moveBy(-7, 0);
  }

  if (moveRight) {
    moveBy(7, 0);
  }

  qreal previousBottom = y() + boundingRect().height();

  velocityY += 1;
  if (velocityY > 16) {
    velocityY = 16;
  }

  moveBy(0, velocityY);
  onGround = false;

  QList<QGraphicsItem*> items = collidingItems();

  for (QGraphicsItem* item : items) {
    qreal itemTop = item->sceneBoundingRect().top();
    qreal currentBottom = y() + boundingRect().height();

    if (velocityY >= 0 && previousBottom <= itemTop && currentBottom >= itemTop) {
      setY(itemTop - boundingRect().height());
      velocityY = 0;
      onGround = true;
      break;
    }
  }

  if (y() > scene()->sceneRect().bottom()) {
    gameOver = true;

    QWidget* parentWidget = nullptr;
    if (!scene()->views().isEmpty()) {
      parentWidget = scene()->views().first();
    }

    QMessageBox::information(parentWidget, "Game Over", "You lost!");
    QApplication::quit();
  }
}
