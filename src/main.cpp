#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "player.hpp"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QGraphicsScene scene;
  scene.setSceneRect(0, 0, 2000, 400);
  scene.setBackgroundBrush(QColor(135, 205, 235));

  Player player;
  scene.addItem(&player);

  // First platform
  QGraphicsRectItem ground(0, 0, 300, 30);
  ground.setBrush(Qt::darkGreen);
  ground.setPos(100, 250);
  scene.addItem(&ground);

  // Second platform
  QGraphicsRectItem* platform1 = new QGraphicsRectItem(0, 0, 250, 30);
  platform1->setBrush(Qt::darkGreen);
  platform1->setPos(450, 200);
  scene.addItem(platform1);

  // Third platform
  QGraphicsRectItem* platform2 = new QGraphicsRectItem(0, 0, 250, 30);
  platform2->setBrush(Qt::darkGreen);
  platform2->setPos(750, 150);
  scene.addItem(platform2);

  // Fourth platform
  QGraphicsRectItem* platform3 = new QGraphicsRectItem(0, 0, 200, 30);
  platform3->setBrush(Qt::darkGreen);
  platform3->setPos(1100, 220);
  scene.addItem(platform3);

  // Fifth platform
  QGraphicsRectItem* platform4 = new QGraphicsRectItem(0, 0, 200, 30);
  platform4->setBrush(Qt::darkGreen);
  platform4->setPos(1400, 180);
  scene.addItem(platform4);

  QGraphicsView view(&scene);
  view.setWindowTitle("Qt Super Mario");
  view.setFixedSize(640, 480);
  view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view.show();

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout, &player, &Player::updateState);
  QObject::connect(&timer, &QTimer::timeout,
                   [&view, &player]() { view.centerOn(&player); });
  timer.start(33);

  return app.exec();
}