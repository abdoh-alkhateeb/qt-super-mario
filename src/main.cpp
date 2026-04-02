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

  QGraphicsRectItem ground(100, 330, 400, 50);
  ground.setBrush(Qt::darkGreen);
  scene.addItem(&ground);

  QGraphicsView view(&scene);
  view.setWindowTitle("Qt Super Mario");
  view.resize(640, 480);
  view.show();

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout, &player, &Player::update);
  timer->start(16);

  return app.exec();
}
