#include "player.hpp"
#include <QKeyEvent>
#include <QBrush>
#include <QMessageBox>

Player::Player(QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent), velocityY(0), onGround(false) {

    // Set the player image
    setPixmap(QPixmap("assets/player.png"));
    setPos(300, 0);

    // Make the player focusable
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

    if (items.size() != 0 && velocityY >= 0) {
        QGraphicsItem* item = items[0];
        setY(item->y() - boundingRect().height());
        velocityY = 0;
        onGround = true;
    }

    if (y() > 400) {
        QMessageBox::information(nullptr, "Game Over", "You lost!");
    }
}
