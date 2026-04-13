#pragma once

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QRectF>
#include <QVector>

class Player : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT

 public:
  Player(const QVector<QRectF>& platforms, QGraphicsItem* parent = nullptr);

 public slots:
  void updateState();

 signals:
  void playerLost();

 protected:
  void keyPressEvent(QKeyEvent* event) override;

 private:
  int velocityY;
  bool onGround;
  bool gameOver;
  QVector<QRectF> platforms;
};
