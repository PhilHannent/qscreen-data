#include "mainwindow.h"

#include <QLabel>
#include <QScreen>
#include <QFontDatabase>
#include <QDebug>

#include <cmath>

namespace
{
    QString l(const QString & s)
    {
        return s.leftJustified(28, ' ', true);
    }
    QString r(const QString & s)
    {
        return (s.isEmpty() ? QString(" ") : s).leftJustified(20, ' ', true);
    }
    QString st(const QSize & size, bool justify = true)
    {
        auto s = QString::number(size.width()) + "," + QString::number(size.height());
        return justify ? r(s) : s;
    }
    QString st(const QSizeF & size, bool justify = true)
    {
        auto s = QString::number(size.width()) + "," + QString::number(size.height());
        return justify ? r(s) : s;
    }
    QString st(const QRect & rect)
    {
        return r(QString::number(rect.x()) + "x" + QString::number(rect.y()) + "," +
                 QString::number(rect.width()) + "x" + QString::number(rect.height()));
    }
    QString st(qreal re, bool justify = true)
    {
        return justify ? r(QString::number(re)) : QString::number(re);
    }
}

MainWindow::MainWindow(QWidget * parent)
    : QMainWindow(parent)
{
    auto * s = this->screen();

    auto * lbl = new QLabel();
    lbl->setAlignment(Qt::AlignVCenter);
    lbl->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
    lbl->setMargin(50);

    QString str;

    const QString nl = "\n";

    const auto phySize = s->physicalSize();
    const auto hypSize = std::sqrt(phySize.width() * phySize.width() +
                                   phySize.height() * phySize.height());
    const auto inchSize = hypSize / 25.4;

    str += "Screen";
    str += nl + l("name: ") + r(s->name());
    str += nl + l("manufacturer: ") + r(s->manufacturer());
    str += nl + l("model: ") + r(s->model());
    str += nl + l("serialNumber: ") + r(s->serialNumber());
    str += nl + l("size: ") + st(s->size());
    str += nl + l("availableSize: ") + st(s->availableSize());
    str += nl + l("virtualSize: ") + st(s->virtualSize());
    str += nl + l("availableVirtualSize: ") + st(s->availableVirtualSize());
    str += nl + l("geometry: ") + st(s->geometry());
    str += nl + l("availableGeometry: ") + st(s->availableGeometry());
    str += nl + l("virtualGeometry: ") + st(s->virtualGeometry());
    str += nl + l("availableVirtualGeometry: ") + st(s->availableVirtualGeometry());
    str += nl + l("physicalSize: ") + r(st(s->physicalSize(), false) + " (mm)");
    str += nl + l("physicalSize (implicit): ") + r(st(inchSize, false) + "\"");
    str += nl + l("physicalDotsPerInchX: ") + st(s->physicalDotsPerInchX());
    str += nl + l("physicalDotsPerInchY: ") + st(s->physicalDotsPerInchY());
    str += nl + l("physicalDotsPerInch: ") + st(s->physicalDotsPerInch());
    str += nl + l("logicalDotsPerInchX: ") + st(s->logicalDotsPerInchX());
    str += nl + l("logicalDotsPerInchY: ") + st(s->logicalDotsPerInchY());
    str += nl + l("logicalDotsPerInch: ") + st(s->logicalDotsPerInch());
    str += nl + l("devicePixelRatio: ") + st(s->devicePixelRatio());
    str += nl + l("refreshRate: ") + st(s->refreshRate());

    qInfo() << qPrintable(str);

    lbl->setText(str);

    this->setCentralWidget(lbl);
}

MainWindow::~MainWindow()
{
}

