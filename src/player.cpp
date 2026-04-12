#include "player.hpp"
#include <QMessageBox>
#include <QBrush>
#include <QGraphicsScene>
#include <QApplication>
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

  for (QGraphicsItem* item : items) {
    if (velocityY > 0) {
      if (y() + boundingRect().height() <= item->y() + velocityY) {
        setY(item->y() - boundingRect().height());
        velocityY = 0;
        onGround = true;
      }
    }
  
}if (y() > scene()->height()) {
    // Show the box and catch the user's action
    int result = QMessageBox::information(nullptr, "game is over", "You lost!");
    
    // If they click the button (which is the default 'Ok' for information boxes)
    if (result == QMessageBox::Ok) {
        QApplication::quit(); 
    }
}}
