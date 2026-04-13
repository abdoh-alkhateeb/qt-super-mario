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

  QGraphicsRectItem ground1(0, 0, 300, 30);
  ground1.setBrush(Qt::darkGreen);
  ground1.setPos(100, 250);
  scene.addItem(&ground1);

  QGraphicsRectItem ground2(0, 0, 220, 30);
  ground2.setBrush(Qt::darkGreen);
  ground2.setPos(470, 190);
  scene.addItem(&ground2);

  QGraphicsRectItem ground3(0, 0, 220, 30);
  ground3.setBrush(Qt::darkGreen);
  ground3.setPos(760, 140);
  scene.addItem(&ground3);

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
