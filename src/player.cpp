#include "player.hpp"
#include <QMessageBox>
#include <QBrush>

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

  if(y() > 400 && !gameOver){

    gameOver = true;
    QMessageBox* messageBox = new QMessageBox;
    messageBox->setWindowTitle("Game Over");
    messageBox->setText("You lost!");
    messageBox->exec();
}
  QList<QGraphicsItem*> items = collidingItems();

  if (items.size() != 0) {
    QGraphicsItem* item = items[0];
    setY(item->y() - boundingRect().height());

    velocityY = 0;
    onGround = true;
  }
}
