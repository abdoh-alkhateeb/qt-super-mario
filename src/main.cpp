#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "player.hpp"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QGraphicsScene scene;
  scene.setSceneRect(0, 0, 2500, 400);
  scene.setBackgroundBrush(QColor(135, 205, 235));

  Player player;
  scene.addItem(&player);

  QGraphicsRectItem ground(0, 0, 300, 30);
  ground.setBrush(Qt::darkGreen);
  ground.setPos(100, 250);
  scene.addItem(&ground);

  QGraphicsRectItem groundnew(0, 0, 300, 30);
  groundnew.setBrush(Qt::darkGreen);
  groundnew.setPos(500, 200);
  scene.addItem(&groundnew);

  QGraphicsRectItem groundverynew(0, 0, 300, 30);
  groundverynew.setBrush(Qt::darkGreen);
  groundverynew.setPos(850, 250);
  scene.addItem(&groundverynew);

  QGraphicsRectItem platform4(0, 0, 300, 30);
  platform4.setBrush(Qt::darkGreen);
  platform4.setPos(1200, 200);
  scene.addItem(&platform4);

  QGraphicsRectItem platform5(0, 0, 300, 30);
  platform5.setBrush(Qt::darkGreen);
  platform5.setPos(1550, 150);
  scene.addItem(&platform5);

  QGraphicsRectItem winningplatform(0, 0, 300, 30);
  winningplatform.setBrush(Qt::darkGreen);
  winningplatform.setPos(2000, 230);
  scene.addItem(&winningplatform);

  QGraphicsRectItem* pole = new QGraphicsRectItem(0, 0, 5, 100);
  pole->setBrush(Qt::gray);
  pole->setPos(2200, 0);
  scene.addItem(pole);

  QGraphicsRectItem* flag = new QGraphicsRectItem(0, 0, 40, 25);
  flag->setBrush(Qt::yellow);
  flag->setPos(2200, 0);
  scene.addItem(flag);


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
