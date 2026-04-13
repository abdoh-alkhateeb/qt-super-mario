#include "player.hpp"

#include <QApplication>
#include <QBrush>
#include <QMessageBox>
#include <QPixmap>

Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent), velocityY(0), onGround(false), gameOver(false) {
  QPixmap pixmap(":/images/player.png");

  if (!pixmap.isNull()) {
    setPixmap(pixmap);
  } else {
    QPixmap fallback(30, 60);
    fallback.fill(Qt::red);
    setPixmap(fallback);
  }

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
  if (gameOver) {
    return;
  }

  velocityY += 1;
  onGround = false;
  moveBy(0, velocityY);

  QList<QGraphicsItem*> items = collidingItems();

  for (QGraphicsItem* item : items) {
    if (y() + boundingRect().height() <= item->y() + velocityY + 1) {
      setY(item->y() - boundingRect().height());
      velocityY = 0;
      onGround = true;
      break;
    }
  }

  if (y() > 400) {
    gameOver = true;
    QMessageBox::information(nullptr, "Game Over", "You lost!");
    QApplication::quit();
  }
}
