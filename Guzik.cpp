#include "Guzik.h"
#include <QBrush>
#include <QGraphicsTextItem>


Guzik::Guzik(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){

    setRect(0,0,150,40);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

    tekst = new QGraphicsTextItem(name, this);
    int xPoz = rect().width()/2 - tekst -> boundingRect().width()/2;
    int yPoz = rect().height()/2 - tekst -> boundingRect().height()/2;
    tekst -> setPos(xPoz, yPoz);

    setAcceptHoverEvents(true);
}

void Guzik::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit wcisniety();
}

void Guzik::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGreen);
    setBrush(brush);
}

void Guzik::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);
}
