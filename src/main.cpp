#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QTimer>
#include <QVector>
#include <QRectF>

#include "player.hpp"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QGraphicsScene scene;
  scene.setSceneRect(0, 0, 2000, 400);
  scene.setBackgroundBrush(QColor(135, 205, 235));

  QVector<QRectF> platformRects = {
      QRectF(100, 250, 300, 30),
      QRectF(500, 200, 300, 30),
      QRectF(900, 150, 300, 30)
  };

  Player player(platformRects);
  scene.addItem(&player);

  for (const QRectF& rect : platformRects) {
    QGraphicsRectItem* platform = scene.addRect(rect, QPen(Qt::NoPen), QBrush(Qt::darkGreen));
    Q_UNUSED(platform);
  }

  QGraphicsView view(&scene);
  view.setWindowTitle("Qt Super Mario");
  view.setFixedSize(640, 480);
  view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
  view.show();

  view.setFocus();
  scene.setFocusItem(&player);
  player.setFocus();

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout, &player, &Player::updateState);
  QObject::connect(&timer, &QTimer::timeout,
                   [&view, &player]() { view.centerOn(&player); });

  QObject::connect(&player, &Player::playerLost, [&timer]() {
    timer.stop();
    QMessageBox::information(nullptr, "Game Over", "You lost!");
  });

  timer.start(33);

  return app.exec();
}
