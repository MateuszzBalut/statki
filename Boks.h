#ifndef BOKS_H
#define BOKS_H

#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>

class Boks: public QGraphicsPolygonItem{
public:

    Boks(QGraphicsItem* parent=NULL);

    bool getIsPlaced();
    QString getOwner();

    void mousePressEvent(QGraphicsSceneMouseEvent* event);


    void setOwner(QString gracz);
    void setIsPlaced(bool b);

private:
    bool isPlaced;
    QString posiadacz;
    int statek1;
    int statek2;
    int statek3;
    int statek4;
};

#endif // BOKS_H
