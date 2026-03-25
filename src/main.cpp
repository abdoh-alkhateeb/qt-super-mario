#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "player.hpp"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QGraphicsScene scene;
  scene.setSceneRect(0, 0, 600, 400);
  scene.setBackgroundBrush(QColor(135, 205, 235));

  Player player;
  scene.addItem(&player);

  QGraphicsRectItem ground(0, 0, 300, 30);
  ground.setBrush(Qt::darkGreen);
  ground.setPos(100, 250);
  scene.addItem(&ground);

  QGraphicsRectItem ground2(0, 0, 200, 30);
  ground2.setBrush(Qt::darkGreen);
  ground2.setPos(300, 200);
  scene.addItem(&ground2);

  QGraphicsRectItem ground3(0, 0, 150, 30);
  ground3.setBrush(Qt::darkGreen);
  ground3.setPos(450, 150);
  scene.addItem(&ground3);


  QGraphicsView view(&scene);
  view.setWindowTitle("Qt Super Mario");
  view.resize(640, 480);
  view.show();

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout, &player, &Player::updateState);
  timer.start(33);

  return app.exec();
}
