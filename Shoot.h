#ifndef SHOOT_H
#define SHOOT_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Shoot:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Shoot(QString name, QGraphicsItem* parent=NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void changeColor();

signals:
    void clicked();

private:
    QGraphicsTextItem* text;
};
#endif // SHOOT_H
