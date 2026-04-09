#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>

#include "player.hpp"

int main(int argc, char *argv[])
{
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

   
    QGraphicsRectItem ground2(0, 0, 300, 30);
    ground2.setBrush(Qt::darkGreen);
    ground2.setPos(150, 150);
    scene.addItem(&ground2);

    
    QGraphicsRectItem ground3(0, 0, 300, 30);
    ground3.setBrush(Qt::darkGreen);
    ground3.setPos(500, 200);
    scene.addItem(&ground3);

    QGraphicsRectItem ground4(0, 0, 300, 30);
    ground4.setBrush(Qt::darkGreen);
    ground4.setPos(800, 120);
    scene.addItem(&ground4);

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
