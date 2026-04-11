#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <iostream>
#include <QMessageBox>
#include <QAbstractButton>

#include "player.hpp"


  // I tried making the object jump while moving towards the right or left at the same time
  // I tried my very best doing this alone, I made the isBeingHeld array as well as the enum class Direction
  // But, after about half an hour of trying several methods, I kept on failing :(
  // After giving up, I asked ChatGPT, and the method turned out to be very simple :/
  // As for the tasks relevant to the assignment itself, no AI tool was used.
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

  QGraphicsRectItem ground2(0,0, 300, 30);
  ground2.setPos(500, 250);
  ground2.setBrush(Qt::darkMagenta);
  scene.addItem(&ground2);

  std::cout << ground2.y() << std::endl;

  QGraphicsRectItem ground3(0, 0, 300, 30);
  ground3.setPos(800, 150);
  ground3.setBrush(Qt::cyan);
  scene.addItem(&ground3);

  QGraphicsView view(&scene);
  view.setWindowTitle("Qt Super Mario");
  view.setFixedSize(640, 480);
  view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view.show();
  QMessageBox* msg = new QMessageBox;
  msg->setText("You Lost!");

  QTimer timer;
  // Every 33 ms, the state of the player is updated.
  QObject::connect(&timer, &QTimer::timeout, &player, &Player::updateState);

  // This helps center the player for the user.
  QObject::connect(&timer, &QTimer::timeout,[&view, &player, &msg]() { 
    view.centerOn(&player); 
    if (player.y() > 480) msg->show();
  });

  QObject::connect(msg, &QMessageBox::buttonClicked, [] {
    exit(0);
  });

  timer.start(33);

  return app.exec();
}
