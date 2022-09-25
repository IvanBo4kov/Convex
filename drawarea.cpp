#include "drawarea.h"

drawArea::drawArea(QWidget *parent)
    : QWidget{parent}
{

}

void drawArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    for (auto x : solve::getInstance().getAllPoints()) {
        painter.drawEllipse(int(x.x), int(x.y), 5, 5);
    }
    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    std::vector<Point> res = solve::getInstance().getConvexPoints();
    if (res.size() > 1) {
        for (int i = 0; i < res.size() - 1; ++i) {
            painter.drawLine(res[i].x, res[i].y, res[i + 1].x, res[i + 1].y);
        }
        painter.drawLine(res[0].x, res[0].y, res[res.size() - 1].x, res[res.size() - 1].y);
    }
}

void drawArea::mousePressEvent(QMouseEvent *pe)
{
    Point pt;
    pt.x = pe->position().x();
    pt.y = pe->position().y();
    solve::getInstance().setPoint(pt);
    this->repaint();
}
