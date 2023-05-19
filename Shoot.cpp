#include "Shoot.h"
#include <QBrush>
#include <QGraphicsTextItem>
#include "Gra.h"


Shoot::Shoot(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){

    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

    text = new QGraphicsTextItem(name, this);
    int xPoz = rect().width()/2 - text -> boundingRect().width()/2;
    int yPoz = rect().height()/2 - text -> boundingRect().height()/2;
    text -> setPos(xPoz, yPoz);

    setAcceptHoverEvents(true);
}

void Shoot::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (brush().color() == Qt::yellow || brush().color() == Qt::green) {
        changeColor();
    }

    emit clicked();
}

void Shoot::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

void Shoot::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);
}
void Shoot::changeColor()
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    // Sprawdź aktualny kolor prostokąta
    if (brush.color() == Qt::blue) {
        // Jeśli aktualny kolor to niebieski, ustaw kolor na szary
        brush.setColor(Qt::gray);
    } else if (brush.color() == Qt::yellow) {
        // Jeśli aktualny kolor to żółty, ustaw kolor na czerwony
        brush.setColor(Qt::red);
    } else if (brush.color() == Qt::green) {
        // Jeśli aktualny kolor to zielony, ustaw kolor na czerwony
        brush.setColor(Qt::red);
    }

    setBrush(brush);
}
