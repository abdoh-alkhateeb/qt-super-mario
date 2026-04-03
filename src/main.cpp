#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QColor>
#include "player.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 600, 400);
    scene.setBackgroundBrush(QColor(135, 205, 235));

    Player player;
    scene.addItem(&player);

    QGraphicsRectItem ground(0, 0, 300, 30);
    ground.setBrush(Qt::darkGreen);
    ground.setPos(100, 250);
    scene.addItem(&ground);

    QGraphicsRectItem platform1(0, 0, 120, 20);
    platform1.setBrush(Qt::darkGreen);
    platform1.setPos(420, 200);
    scene.addItem(&platform1);

    QGraphicsRectItem platform2(0, 0, 120, 20);
    platform2.setBrush(Qt::darkGreen);
    platform2.setPos(260, 150);
    scene.addItem(&platform2);

    QGraphicsView view(&scene);
    view.setWindowTitle("Qt Super Mario");
    view.resize(640, 480);
    view.show();

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &player, &Player::updateState);
    timer.start(33);

    return app.exec();
}
