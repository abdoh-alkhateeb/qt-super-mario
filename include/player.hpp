#pragma once

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>

class Player : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT

 public:
  Player(QGraphicsItem* parent = nullptr);

 public slots:
  void updateState();
     void CheckBoundary();
 public:
  signals:
     void PlayerLost();
 protected:
  void keyPressEvent(QKeyEvent* event) override;

 private:
  int velocityY;
  bool onGround;
  bool fellbelowBoundary; //variable to check boundaries
};
