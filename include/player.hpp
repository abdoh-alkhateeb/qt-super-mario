#pragma once

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>

class Player : public QObject, public QGraphicsRectItem {
  Q_OBJECT

 public:
  Player(QGraphicsItem* parent = nullptr);

 public slots:
  void updateState();

 protected:
  void keyPressEvent(QKeyEvent* event) override;

 private:
  int velocityY;
  int velocityX;
  bool onGround;
  bool gameover;
};
