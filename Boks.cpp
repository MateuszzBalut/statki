#include "Boks.h"
#include <QPointF>
#include <QPolygonF>
#include <QVector>
#include <QBrush>
#include "Gra.h"

extern Gra* gra;

#include <QDebug>
Boks::Boks(QGraphicsItem *parent){

    QVector<QPointF> boksPunkt;
    boksPunkt << QPointF(1,1) << QPointF(2,1) << QPointF(2,2) << QPointF(1,2);


    int SCALE_BY = 25;
    for (size_t i=0, n=boksPunkt.size(); i<n; i++){
        boksPunkt[i] = boksPunkt[i] * SCALE_BY;
    }

    QPolygonF kwadrat(boksPunkt);


    setPolygon(kwadrat);



}

bool Boks::getIsPlaced(){
    return isPlaced;
}

QString Boks::getOwner(){
    return posiadacz;
}

void Boks::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(getIsPlaced() == false){
        gra -> pickUpStatek(this);
    }
    else{
         if(gra->statekDoPost != NULL){
            gra -> placeStatek(this);
         }
    }
}

void Boks::setOwner(QString gracz){

    posiadacz = gracz;

    if(gracz == QString("NOONE")){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkBlue);
        setBrush(brush);
    }

    if(gracz == QString("Gracz1")){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::yellow);
        setBrush(brush);
    }

}

void Boks::setIsPlaced(bool b){
    isPlaced = b;
}
