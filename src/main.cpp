#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>
#include <QTimer>

#include "player.hpp"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QGraphicsScene scene;
  scene.setSceneRect(0, 0, 6000, 400);
  scene.setBackgroundBrush(QColor(135, 205, 235));

  Player player;
  scene.addItem(&player);

  std::vector<QGraphicsRectItem*> platforms = {
    new QGraphicsRectItem(0, 0, 300, 30),
    new QGraphicsRectItem(360, 0, 300, 30),
    new QGraphicsRectItem(700, 0, 300, 30)
  };

  for (auto platform : platforms) {
    platform->setBrush(Qt::darkGreen);
    platform->setPos(100, 250);
    scene.addItem(platform);
  }

  QGraphicsView view(&scene);
  view.setWindowTitle("Qt Super Mario");
  view.resize(640, 480);
  view.show();

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout, [&]() { player.updateState(view); });
  timer.start(33);

  return app.exec();
}
