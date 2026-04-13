#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "../include/player.hpp"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QGraphicsScene scene;
  scene.setSceneRect(0, 0, 2000, 400);
  scene.setBackgroundBrush(QColor(135, 205, 235));

  Player player;
  scene.addItem(&player);

  QGraphicsRectItem ground(0, 0, 300, 30);
  ground.setBrush(Qt::darkGreen);
  ground.setPos(100, 250);
  scene.addItem(&ground);

  QGraphicsRectItem Platform1(360, 0, 300, 30);
  Platform1.setBrush(Qt::blue);
  Platform1.setPos(100, 250);
  scene.addItem(&Platform1);

  QGraphicsRectItem Platform2(720, 0, 300, 30);
  Platform2.setBrush(Qt::yellow);
  Platform2.setPos(100, 250);
  scene.addItem(&Platform2);

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
