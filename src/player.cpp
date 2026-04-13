#include "player.hpp"

#include <QPixmap>
#include <QtMath>

Player::Player(const QVector<QRectF>& platformRects, QGraphicsItem* parent)
    : QObject(),
      QGraphicsPixmapItem(parent),
      velocityY(0),
      onGround(false),
      gameOver(false),
      platforms(platformRects) {
  QPixmap pixmap("../assets/player.png");
  setPixmap(pixmap.scaled(30, 60, Qt::IgnoreAspectRatio, Qt::FastTransformation));
  setPos(150, 100);

  setFlag(QGraphicsItem::ItemIsFocusable);
  setFocus();
}

void Player::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Left) {
    moveBy(-25, 0);
  }
  if (event->key() == Qt::Key_Right) {
    moveBy(25, 0);
  }
  if (event->key() == Qt::Key_Space && onGround) {
    velocityY = -15;
  }
}

void Player::updateState() {
  if (gameOver) {
    return;
  }

  qreal playerWidth = boundingRect().width();
  qreal playerHeight = boundingRect().height();
  qreal playerX = x();
  qreal playerY = y();
  qreal playerBottom = playerY + playerHeight;

  bool supported = false;

  for (const QRectF& platform : platforms) {
    bool horizontallyOverlapping =
        playerX + playerWidth > platform.left() &&
        playerX < platform.right();

    bool standingOnTop =
        qAbs(playerBottom - platform.top()) <= 2;

    if (horizontallyOverlapping && standingOnTop && velocityY >= 0) {
      setY(platform.top() - playerHeight);
      velocityY = 0;
      onGround = true;
      supported = true;
      break;
    }
  }

  if (!supported) {
    onGround = false;
    velocityY += 1;
    moveBy(0, velocityY);

    qreal newX = x();
    qreal newY = y();
    qreal newBottom = newY + playerHeight;

    for (const QRectF& platform : platforms) {
      bool horizontallyOverlapping =
          newX + playerWidth > platform.left() &&
          newX < platform.right();

      bool landedOnTop =
          velocityY >= 0 &&
          playerBottom <= platform.top() + 15 &&
          newBottom >= platform.top();

      if (horizontallyOverlapping && landedOnTop) {
        setY(platform.top() - playerHeight);
        velocityY = 0;
        onGround = true;
        supported = true;
        break;
      }
    }
  }

  if (y() > 400) {
    gameOver = true;
    emit playerLost();
  }
}
