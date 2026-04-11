#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsTextItem>

#include "player.hpp"

int main(int argc, char *argv[])
{
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

  QGraphicsRectItem ground2(0, 0, 300, 30);
  ground2.setBrush(Qt::darkGreen);
  ground2.setPos(450, 250);
  scene.addItem(&ground2);

  QGraphicsRectItem ground3(0, 0, 300, 30);
  ground3.setBrush(Qt::darkGreen);
  ground3.setPos(800, 250);
  scene.addItem(&ground3);

  QGraphicsTextItem *deathText = new QGraphicsTextItem("You lost!");
  QFont deathFont("Verdana", 50, QFont::Bold);
  deathText->setFont(deathFont);
  deathText->setDefaultTextColor(Qt::white);
  deathText->hide();
  scene.addItem(deathText);

  QGraphicsView view(&scene);
  view.setWindowTitle("Qt Super Mario");
  view.setFixedSize(640, 480);
  view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view.show();

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout, &player, &Player::updateState);
  QObject::connect(&timer, &QTimer::timeout,
                   [&view, &player]()
                   { view.centerOn(&player); });
  timer.start(33);
  QObject::connect(&player, &Player::playerDied,
                   [&scene, &ground1, &ground2, &ground3, &deathText, &player, &app]()
                   {
                     scene.setBackgroundBrush(Qt::red);
                     ground1.hide();
                     ground2.hide();
                     ground3.hide();
                     player.hide();
                     // because the player moves so the scene is not static i made the death text
                     // place based on your death pos
                     deathText->setPos(player.x() - 120, 150);
                     deathText->show();
                     // i close app 3 seconds after u die
                     QTimer::singleShot(3000, &app, &QApplication::quit);
                   });

  return app.exec();
}
