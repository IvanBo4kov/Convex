#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include "solve.h"
#include <QPainter>
#include <QMouseEvent>


class drawArea : public QWidget
{
    Q_OBJECT
public:
    explicit drawArea(QWidget *parent = nullptr);

    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent* pe);

signals:

};

#endif // DRAWAREA_H
