#ifndef BOKS2_H
#define BOKS2_H

#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>

class Boks2: public QGraphicsPolygonItem{
public:

    Boks2(QGraphicsItem* parent=NULL);

    bool getIsPlaced2();
    QString getOwner2();

    void mousePressEvent(QGraphicsSceneMouseEvent* event);


    void setOwner2(QString gracz2);
    void setIsPlaced2(bool b2);

private:
    bool isPlaced2;
    QString posiadacz2;
    int statek1;
    int statek2;
    int statek3;
    int statek4;
};

#endif // BOKS2_H
