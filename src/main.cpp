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

  QGraphicsRectItem ground(0, 0, 300,30);
  ground.setBrush(Qt::darkGreen);
  ground.setPos(100, 250);
  scene.addItem(&ground);

  QGraphicsRectItem plat1(0, 0, 200,30);
  plat1.setBrush(Qt::darkGreen);
  plat1.setPos(615, 180);
  scene.addItem(&plat1);

  QGraphicsRectItem plat2(0, 0, 200,30);
  plat2.setBrush(Qt::darkGreen);
  plat2.setPos(980, 105);
  scene.addItem(&plat2);

  QGraphicsView view(&scene);
  view.setWindowTitle("Qt Super Mario");
  view.setFixedSize(640, 480);
  view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view.show();
 
  QMessageBox loser;
  loser.setWindowTitle("Hard Luck! :(");
  loser.setText("You Lost!");

  bool gameOver = false;

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout, &player, &Player::updateState);
  QObject::connect(&timer, &QTimer::timeout,
                   [&view, &player]() { view.centerOn(&player); });
  QObject::connect(&timer, &QTimer::timeout, [&](){
		   if(!gameOver && player.outOfScreen()){
			gameOver = true;
			loser.exec();
		   }
  });

  timer.start(33);

  return app.exec();
}
