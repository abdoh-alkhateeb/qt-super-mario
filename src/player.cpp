#include "player.hpp"
<<<<<<< HEAD
#include <QBrush>
#include <QMessageBox>
#include <QApplication>
=======
>>>>>>> origin/feature/add-player-image

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

for (auto item : items) {
        if (velocityY > 0) {
            setY(item->y() - boundingRect().height());
            velocityY = 0;
            onGround = true;
        }
}
}
if (y() > 400) {
        QMessageBox::information(nullptr, "You lost","you lost");
        QApplication::quit();
    }
}
