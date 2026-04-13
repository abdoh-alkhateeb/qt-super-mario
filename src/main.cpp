#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QWindow>

#include "player.hpp"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QGraphicsScene scene;
  scene.setSceneRect(0, 0, 2000, 400);
  scene.setBackgroundBrush(QColor(135, 205, 235));

  Player player;
  scene.addItem(&player);

  QGraphicsRectItem ground(0, 0, 100, 30);
  ground.setBrush(Qt::darkGreen);
  ground.setPos(100, 250);
  scene.addItem(&ground);

  QGraphicsRectItem ground2(0, 0, 100, 30);
  ground2.setBrush(Qt::darkGreen);
  ground2.setPos(250, 250);
  scene.addItem(&ground2);

  QGraphicsRectItem ground3(0, 0, 100, 30);
  ground3.setBrush(Qt::darkGreen);
  ground3.setPos(400, 250);
  scene.addItem(&ground3);

  QGraphicsView view(&scene);
  view.setWindowTitle("Qt Super Mario");
  view.setFixedSize(640, 480);
  view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view.show();

  
  if (player.x > 640 || player.x < 0 || player.y > 480 || player.y < 0) {

    QWidget* window = new QWidget;
    window->setWindowTitle("Popup");

    QLabel* label = new QLabel("You died!");
    label->setAlignment(Qt::AlignCenter);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(label);

    window->setLayout(layout);
    window->resize(300, 150);
    window->show();
      
  }

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout, &player, &Player::updateState);
  QObject::connect(&timer, &QTimer::timeout,
                   [&view, &player]() { view.centerOn(&player); });
  timer.start(33);

  return app.exec();
}
