#ifndef GUZIK_H
#define GUZIK_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Guzik:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Guzik(QString name, QGraphicsItem* parent=NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void setFont(QFont font);
signals:
    void wcisniety();

private:
    QGraphicsTextItem* tekst;
};

#endif // GUZIK_H
