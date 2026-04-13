#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include<QMessageBox>

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
    QGraphicsRectItem platform(0,0,100,20);
    QGraphicsRectItem platform2(0,0,90,30);
    QMessageBox message;
    ground.setBrush(Qt::darkGreen);
    platform.setBrush(Qt::yellow);
    platform2.setBrush(Qt::blue);
    ground.setPos(100, 250);
    platform.setPos(510,250);
    platform2.setPos(10,150);
    scene.addItem(&ground);
    scene.addItem(&platform);
        scene.addItem(&platform2);

    QGraphicsView view(&scene);
    view.setWindowTitle("Qt Super Mario");
    view.setFixedSize(640, 480);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.show();

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &player, &Player::updateState);
    QObject::connect(&timer, &QTimer::timeout, [&view, &player]() { view.centerOn(&player); });
    timer.start(33);

    return app.exec();
}
