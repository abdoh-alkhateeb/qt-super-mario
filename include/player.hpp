#pragma once

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>

enum class Direction : int {
  Left,
  Right
};


class Player : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT

 public:
  Player(QGraphicsItem* parent = nullptr);

 public slots:
  void updateState();

 protected:
  void keyPressEvent(QKeyEvent* event) override;
  void keyReleaseEvent(QKeyEvent* event) override;
 private:
  int velocityY;
  int velocityX;
  bool onGround;
};
