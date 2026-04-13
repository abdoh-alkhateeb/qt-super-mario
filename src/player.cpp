#include "player.hpp"
#include <QApplication>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QPixmap>

Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent), velocityY(0), onGround(false) {
  QPixmap pixmap(30, 60);
  pixmap.fill(Qt::red);
  setPixmap(pixmap);
  setPos(130, 240);
  setFlag(QGraphicsItem::ItemIsFocusable, true);
  setFlag(QGraphicsItem::ItemIsMovable, false);
  setAcceptedMouseButtons(Qt::AllButtons);
  setFocus();
}

void Player::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Left:
      moveBy(-10, 0);
      break;
    case Qt::Key_Right:
      moveBy(10, 0);
      break;
    case Qt::Key_Space:
      if (onGround) {
        velocityY = -15;
        onGround = false;
      }
      break;
    default:
      QGraphicsPixmapItem::keyPressEvent(event);
      break;
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

  if (scene() && y() > scene()->sceneRect().bottom() + 50) {
    QMessageBox::information(nullptr, "Game Over", "You lost!");
    QApplication::quit();
  }
}
