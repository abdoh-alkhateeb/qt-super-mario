#include "player.hpp"

Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent), velocityY(0), velocityX(0), onGround(false) {
  setPixmap(QPixmap("assets/player.png"));
  setPos(300, 0);

  setFlag(QGraphicsItem::ItemIsFocusable);
  setFocus();
}

void Player::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Left) {
    velocityX=-10;
    moveBy(velocityX, 0);
  }
  if (event->key() == Qt::Key_Right) {
    velocityX=10;
    moveBy(velocityX, 0);
  }
  if (event->key() == Qt::Key_Space && onGround) {
    velocityY = -15;
  }
}

void Player::updateState() {
  velocityY += 1;
  onGround = false;
  moveBy(velocityX, velocityY);

  QList<QGraphicsItem*> items = collidingItems();

  if (items.size() != 0) {
    QGraphicsItem* item = items[0];
    setY(item->y() - boundingRect().height());
    velocityX = 0;
    velocityY = 0;
    onGround = true;
  }
  Message();
}
void Player::Message(){
  if(pos().y() >400){
    QMessageBox* message = new QMessageBox;
    QPushButton* restart = new QPushButton("Restart");
    message->setText("You Lost");
    message->addButton(restart, QMessageBox::ActionRole);
    message->exec();
    if(message->clickedButton() == restart){
        setPos(-250,0);
        velocityX=0;
        velocityY=0;
    }
  }
}