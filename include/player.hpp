#pragma once

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QMessageBox>
#include <QPushButton>

class Player : public QObject, public QGraphicsRectItem {
  Q_OBJECT

 public:
  Player(QGraphicsItem* parent = nullptr);
  void Message();

 public slots:
  void updateState();

 protected:
  void keyPressEvent(QKeyEvent* event) override;

 private:
  int velocityY;
  int velocityX;
  int velocityXJump;
  bool onGround;
};
