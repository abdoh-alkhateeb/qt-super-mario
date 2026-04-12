#include "player.hpp"

#include <QMessageBox>
#include <QCoreApplication>
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

  QList<QGraphicsItem*> items = collidingItems();

  if (items.size() != 0 && velocityY > 0) {
    QGraphicsItem* item = items[0];
    setY(item->y() - boundingRect().height());

    velocityY = 0;
    onGround = true;
  }

  if (y() > 480) {
   auto reply = QMessageBox::information(nullptr, "Game Over", "You Lost",QMessageBox::Retry|QMessageBox::Close);
   if (reply == QMessageBox::Retry){
	this->setPos(300,0);
	}
   else if (reply == QMessageBox::Close) {
	QCoreApplication::exit(0);
	}
  }
  else if (x() >= 900 && y() <= 150 && velocityY == 0){
       auto reply2 = QMessageBox::information(nullptr, "Winner", "You Win",QMessageBox::Retry|QMessageBox::Close);
   if (reply2 == QMessageBox::Retry){
        this->setPos(300,0);
        }
   else if (reply2 == QMessageBox::Close) {
        QCoreApplication::exit(0);
        }
  }
}
