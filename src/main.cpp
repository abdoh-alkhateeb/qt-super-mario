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

   QGraphicsRectItem* ground = new QGraphicsRectItem(0, 0, 300, 20);
 ground->setBrush(Qt::darkGreen);
  ground->setPos(100, 300);
  scene.addItem(ground);

 
  QGraphicsRectItem* platform2 = new QGraphicsRectItem(0, 0, 200, 20);
  platform2->setBrush(Qt::darkGreen);
  platform2->setPos(450, 230);
  scene.addItem(platform2);

 
  QGraphicsRectItem* platform3 = new QGraphicsRectItem(0, 0, 200, 20);
  platform3->setBrush(Qt::darkGreen);
  platform3->setPos(720, 160);
  scene.addItem(platform3);

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
