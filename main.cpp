#include "mainwindow.h"

#include <QApplication>

int main(int argc, char * argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling, false);
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Round);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
