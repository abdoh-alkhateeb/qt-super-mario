#include "player.hpp"

#include <QApplication>

#include <QMessageBox>

#include <QGraphicsScene>

#include <QPixmap>

Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent), velocityY(0), velocityX(0), onGround(false) {
  setPixmap(QPixmap("assets/player.png"));
  setPos(300, 0);

  setFlag(QGraphicsItem::ItemIsFocusable);
  setFocus();
}

void Player::keyPressEvent(QKeyEvent* event) {
  keysHeld.insert(event->key());
  if (event->key() == Qt::Key_Space && onGround) {
    velocityY = -15;
  }
}

void Player::keyReleaseEvent(QKeyEvent* event) {
  keysHeld.remove(event->key());
}

void Player::updateState() {

  // Horizontal input
  if (keysHeld.contains(Qt::Key_Left))  velocityX = -10;
  if (keysHeld.contains(Qt::Key_Right)) velocityX = 10;

  // Deceleration when no horizontal key held
  if (!keysHeld.contains(Qt::Key_Left) && !keysHeld.contains(Qt::Key_Right)) {
    if (velocityX > 0) velocityX -= 1;
    else if (velocityX < 0) velocityX += 1;
  }


  velocityY += 1;
  onGround = false;
  moveBy(velocityX, velocityY);  // ← horizontal + vertical together

  // Check if player fell off screen
  if (y() > scene()->sceneRect().height()) {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Game Over");
    msgBox.setText("You lost!");
    msgBox.exec();
    QApplication::quit();   // or reset position — depends on preference
    return;
  }

  QList<QGraphicsItem*> items = collidingItems();

for (QGraphicsItem* item : items) {
    // Make sure we land on top, not clip through sides
    if (y() + boundingRect().height() <= item->y() + item->boundingRect().height()) {
      setY(item->y() - boundingRect().height());
      velocityY = 0;
      onGround = true;
      break;
    }
  }
}
