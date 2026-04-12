#include "player.hpp"

#include <QBrush>

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

  if (items.size() != 0 && velocityY > 0) {// make sure that the rectangle is going donw ( positive y velocity)
    QGraphicsItem* item = items[0];
    setY(item->y() - boundingRect().height());
    velocityY = 0;
    onGround = true;
  }

  if (!gameOver  && y() > scene()->sceneRect().bottom()) {// :D check if the y coordinate of the rectangle is out of the scence bottom y coordinate
    gameOver = true;
    QMessageBox* messagebox = new QMessageBox();
    messagebox->setWindowTitle(":(");
    messagebox->setText("You lost!");
    messagebox->setFixedSize(200, 100);
    messagebox->show();
  }
}