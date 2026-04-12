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
  bool outOfScreen();
 protected:
  void keyPressEvent(QKeyEvent* event) override;
  void keyReleaseEvent(QKeyEvent* event) override;
 private:
  int velocityY;
  bool onGround;
  bool movingr=0;
  bool movingl=0;
};
