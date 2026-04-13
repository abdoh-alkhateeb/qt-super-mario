#include "player.hpp"
#include <QMessageBox>
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
  if (gameOver) return;  
  velocityY += 1;
  onGround = false;
  moveBy(0, velocityY);

  QList<QGraphicsItem*> items = collidingItems();

  for (QGraphicsItem* item : items){
	QGraphicsRectItem* platform = dynamic_cast<QGraphicsRectItem*>(item);
	if(!platform) continue;

	QRectF playerRect = sceneBoundingRect();
	QRectF platformRect = platform->sceneBoundingRect();

	if(velocityY > 0 && playerRect.bottom() >= platformRect.top() && playerRect.bottom() <= platformRect.top() +20){

		setY(platformRect.top() - boundingRect().height());
		velocityY = 0;
		onGround = true;
		break;}
}
  if(sceneBoundingRect().y() > 400 && onGround == false){ 
	gameOver= true;
	velocityY=0;
	QMessageBox::information(nullptr, "GAME OVER", "You lost, loser! XD");
	scene()->clear();
	return;
}
}

