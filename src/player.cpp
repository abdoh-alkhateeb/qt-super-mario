#include "player.hpp"
#include <QMessageBox>
Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent), velocityX(0), velocityY(0), onGround(false), gameover(false) {
  setPixmap(QPixmap("assets/player.png"));


  setPos(300, 0);

  setFlag(QGraphicsItem::ItemIsFocusable);
  setFocus();
}

void Player::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Left) {
    velocityX = -10;
  }
  if (event->key() == Qt::Key_Right) {
    velocityX = 10;
  }
  if (event->key() == Qt::Key_Space && onGround) {
    velocityY = -15;
  }
}

void Player::updateState() {
	if(gameover) return;

  velocityY += 1;
  onGround = false;
  moveBy(velocityX, velocityY);

	if (pos().y() > 400) {
		gameover = true;

    		QMessageBox msgBox;
		msgBox.setWindowTitle("Game Over");
		msgBox.setText("<h1>You Lost! 😢</h1>");
		msgBox.setInformativeText("Better luck next time!");
		msgBox.setStyleSheet("QMessageBox { background-color: #2c2c2c; color: white; }"
                "QLabel { color: white; font-size: 14px; }"
                 "QPushButton { background-color: red; color: white; padding: 5px 20px; }");
msgBox.exec();
	}
  QList<QGraphicsItem*> items = collidingItems();

  if (items.size() != 0) {
    QGraphicsItem* item = items[0];
    setY(item->y() - boundingRect().height());

    velocityY = 0;
    onGround = true;
    velocityX = 0;
  }
if (pos().x() > 2200 && onGround && !gameover) {
    gameover = true;
    QMessageBox msgBox;
    msgBox.setWindowTitle("You Won!");
    msgBox.setText("<h1>You Won! 🎉</h1>");
    msgBox.setInformativeText("Congratulations!");
    msgBox.setStyleSheet("QMessageBox { background-color: #2c2c2c; }"
                         "QLabel { color: white; font-size: 14px; }"
                         "QPushButton { background-color: green; color: white; padding: 5px 20px; }");
    msgBox.exec();
    return;
}
}
