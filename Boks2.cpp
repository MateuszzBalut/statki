#include "Boks2.h"
#include <QPointF>
#include <QPolygonF>
#include <QVector>
#include <QBrush>
#include "Gra.h"

extern Gra* gra;

#include <QDebug>
Boks2::Boks2(QGraphicsItem *parent){

    QVector<QPointF> boksPunkt2;
    boksPunkt2 << QPointF(1,1) << QPointF(2,1) << QPointF(2,2) << QPointF(1,2);


    int SCALE_BY = 25;
    for (size_t i=0, n=boksPunkt2.size(); i<n; i++){
        boksPunkt2[i] = boksPunkt2[i] * SCALE_BY;
    }

    QPolygonF kwadrat(boksPunkt2);


    setPolygon(kwadrat);



}

bool Boks2::getIsPlaced2(){
    return isPlaced2;
}

QString Boks2::getOwner2(){
    return posiadacz2;
}

void Boks2::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(getIsPlaced2() == false){
        gra -> pickUpStatek2(this);
    }
    else{
         if(gra->statekDoPost2 != NULL){
            gra -> placeStatek2(this);
         }
    }
}

void Boks2::setOwner2(QString gracz2){

    posiadacz2 = gracz2;

    if(gracz2 == QString("NOONE")){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkBlue);
        setBrush(brush);
    }

    if(gracz2 == QString("Gracz2")){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::green);
        setBrush(brush);
    }
}

void Boks2::setIsPlaced2(bool b2){
    isPlaced2 = b2;
}
