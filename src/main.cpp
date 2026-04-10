#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMessageBox>

#include "player.hpp"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QGraphicsScene scene;
  scene.setSceneRect(0, 0, 2000, 400);
  scene.setBackgroundBrush(QColor(135, 205, 235));

  Player player;
  scene.addItem(&player);

  QGraphicsRectItem g1(0, 0, 300, 30);
  g1.setBrush(Qt::darkGreen);
  g1.setPos(100, 250);
  scene.addItem(&g1);

  QGraphicsRectItem g2(0, 0, 300, 30);
  g2.setBrush(Qt::darkGreen);
  g2.setPos(30, 130);
  scene.addItem(&g2);

  QGraphicsRectItem g3(0, 0, 300, 30);
  g3.setBrush(Qt::darkGreen);
  g3.setPos(190, 10);
  scene.addItem(&g3);

  QGraphicsView view(&scene);
  view.setWindowTitle("Qt Super Mario");
  view.setFixedSize(640, 480);
  view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view.show();

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout, &player, &Player::updateState);
  QObject::connect(&timer, &QTimer::timeout,
                   [&view, &player]() { view.centerOn(&player); });
  QObject::connect(&player, &Player::playerOutOfView, [&view] () {
    QMessageBox::information(&view, "Sorry...", "YOU LOST!");
  });
  timer.start(33);

  return app.exec();
}
