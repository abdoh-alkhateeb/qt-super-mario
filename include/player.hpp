#pragma once

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>

class Player : public QObject, public QGraphicsRectItem {
  Q_OBJECT

 public:
  Player(QGraphicsItem* parent = nullptr);
  void spawnPosition(); //get the origin spawn position
 public slots:
  void updateState();
 signals:
  void playerOutOfView();

 protected:
  void keyPressEvent(QKeyEvent* event) override;

 private:
  int velocityY;
  bool onGround;
  bool collisionBlock; //To block motion when colliding with a platform
};
