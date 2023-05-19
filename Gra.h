#ifndef GRA_H
#define GRA_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "BoksPlansza.h"
#include "BoksPlansza2.h"
#include <QMouseEvent>
#include <QList>

class Gra: public QGraphicsView{
    Q_OBJECT
public:

    Gra(QWidget* parent=NULL);

    void oddajStrzal();
    void poczatkoweMenu();
    QString getKogoTura();
    void setKogoTura(QString gracz);

    void pickUpStatek(Boks* statek);
    void placeStatek(Boks* boksDoZmiany);
    void zmianaTury();
    void usunZeStolu(Boks* statek, QString gracz);

    void pickUpStatek2(Boks2* statek2);
    void placeStatek2(Boks2* boksDoZmiany);
    void usunZeStolu2(Boks2* statek2, QString gracz2);

    void sprawdzCzyTrafil(Boks* statek);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent* event);


    QGraphicsScene* scena;
    BoksPlansza* boksPlansza;
    Boks* statekDoPost;
    Boks* statekPrzeciwnika;

    BoksPlansza2* boksPlansza2;
    Boks2* statekDoPost2;
    QPointF originalPos;

public slots:
    void start();

private:

    void rysPanel(int x, int y, int width, int height, QColor color, double opacity);
    void rysGUI();
    void stworzStatki(QString gracz);
    void createInitialStatki();
    void rysStatki();

    void rysGUI2();
    void stworzStatki2(QString gracz);
    void createInitialStatki2();
    void rysStatki2();


    QString kogoTura_;
    QGraphicsTextItem* kogoTuraTekst;
    QList<Boks* > statkiGracz1;
    QList<Boks2* > statkiGracz2;
};

#endif // GRA_H
