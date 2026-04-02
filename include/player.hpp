#pragma once

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>

class Player : public QObject, public QGraphicsRectItem {
 public:
  Player();

 protected:
  void keyPressEvent(QKeyEvent* event) override;

 private slots:
  void update();

 private:
  int velocityY;
  bool onGround;
};
