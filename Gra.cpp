#include "Gra.h"
#include "BoksPlansza.h"
#include "BoksPlansza2.h"
#include "Guzik.h"
#include "Shoot.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>
#include <QPixmap>
#include <QPen>

#include <QDebug>
Gra::Gra(QWidget *parent){

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    scena = new QGraphicsScene();
    scena -> setSceneRect(0,0,1024,768);
    setBackgroundBrush(QBrush(QImage(":/backg.jpg")));
    setScene(scena);

    statekDoPost = NULL;

}

void Gra::start(){
    scena -> clear();

    boksPlansza = new BoksPlansza();
    boksPlansza -> placeBoksy(100,100,5,5);
    rysGUI();
    createInitialStatki();


    boksPlansza2 = new BoksPlansza2();
    boksPlansza2 -> placeBoksy2(740,100,5,5);
    rysGUI2();
    createInitialStatki2();

    Shoot* playShoot = new Shoot(QString("STRZEL"));
    int gxPoz = this -> width()/2 - playShoot -> boundingRect().width()/2;
    int gyPoz = 230;
    playShoot -> setPos(gxPoz, gyPoz);
    connect(playShoot,SIGNAL(clicked()),this,SLOT(start()));
    scena -> addItem(playShoot);
}

void Gra::rysPanel(int x, int y, int width, int height, QColor color, double opacity){

    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel -> setBrush(brush);
    panel -> setOpacity(opacity);

    scena -> addItem(panel);

}

void Gra::rysGUI(){
    //lewy
    QColor grayColor(192, 192, 192, 128);
    rysPanel(0,500,400,270, grayColor,1);

    //gracz1
    QGraphicsTextItem* g1 = new QGraphicsTextItem("Statki gracza 1: ");
    QFont font1("BlackPearl", 10);
    g1 -> setDefaultTextColor(Qt::white);
    g1 -> setFont(font1);
    QGraphicsTextItem* g11 = new QGraphicsTextItem(QString("Statki gracza 1: "));
    QFont font2("BlackPearl", 10);
    g11 -> setDefaultTextColor(Qt::black);
    g11 -> setFont(font2);
    g1 -> setPos((this -> width() - g1 -> boundingRect().width()) / 7, 510);
    g11 -> setPos(g1 -> pos().x() - 1, g1 -> pos().y() - 1);
    QPen whitePen(Qt::white);
    whitePen.setWidth(1);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);


    scena -> addItem(g11);
    scena -> addItem(g1);

    //kogo tura
    kogoTuraTekst = new QGraphicsTextItem();
    setKogoTura(QString("Gracz1")) ;
    kogoTuraTekst -> setPos(475,500);
    scena -> addItem(kogoTuraTekst);
}

void Gra::stworzStatki(QString gracz){

    Boks* statek = new Boks();
    statek -> setOwner(gracz);
    statek -> setIsPlaced(false);

    if(gracz == QString("Gracz1")){
        statkiGracz1.append(statek);
    }

    rysStatki();
}

void Gra::createInitialStatki(){

    for(size_t i=0, n=5; i<n; i++){
        stworzStatki(QString("Gracz1"));
    }

    rysStatki();
}

void Gra::rysStatki(){


    for(size_t i=0, n=statkiGracz1.size(); i<n; i++){
    scena -> removeItem(statkiGracz1[i]);
    }

    for(size_t i=0, n=statkiGracz1.size(); i<n; i++){
        Boks* statek = statkiGracz1[i];
        statek -> setPos(20,540+37*i);
        scena -> addItem(statek);
    }
}


void Gra::stworzStatki2(QString gracz2){

    Boks2* statek2 = new Boks2();
    statek2 -> setOwner2(gracz2);
    statek2 -> setIsPlaced2(false);

    if(gracz2 == QString("Gracz2")){
        statkiGracz2.append(statek2);
    }

    rysStatki2();
}

void Gra::createInitialStatki2()
{
    for(size_t i=0, n=5; i<n; i++){
        stworzStatki2(QString("Gracz2"));
    }

    rysStatki2();
}

void Gra::rysStatki2()
{

    for(size_t i=0, n=statkiGracz2.size(); i<n; i++){
        scena -> removeItem(statkiGracz2[i]);
    }

    for(size_t i=0, n=statkiGracz2.size(); i<n; i++){
        Boks2* statek2 = statkiGracz2[i];
        statek2 -> setPos(640,540+37*i);
        scena -> addItem(statek2);
    }
}

void Gra::rysGUI2()
{
    //prawy
    QColor grayColor(192, 192, 192, 128);
    rysPanel(624, 500, 400, 270, grayColor, 1);
    //gracz2
    QGraphicsTextItem* g2 = new QGraphicsTextItem("Statki gracza 2: ");
    QFont font1("BlackPearl", 10);
    g2 -> setDefaultTextColor(Qt::white);
    g2 -> setFont(font1);
    QGraphicsTextItem* g22 = new QGraphicsTextItem(QString("Statki gracza 2: "));
    QFont font2("BlackPearl", 10);
    g22 -> setDefaultTextColor(Qt::black);
    g22 -> setFont(font2);
    g2 -> setPos((this -> width() - g2 -> boundingRect().width()) / 1.15, 510);
    g22 -> setPos(g2 -> pos().x() - 1, g2 -> pos().y() - 1);
    QPen whitePen(Qt::white);
    whitePen.setWidth(1);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);


    scena -> addItem(g22);
    scena -> addItem(g2);
}


void Gra::poczatkoweMenu(){

    QGraphicsTextItem* tytul1 = new QGraphicsTextItem(QString("Gra w statki"));
    QFont font1("BlackPearl", 50);
    tytul1 -> setDefaultTextColor(Qt::white);
    tytul1 -> setFont(font1);
    QGraphicsTextItem* tytul2 = new QGraphicsTextItem(QString("Gra w statki"));
    QFont font2("BlackPearl", 50);
    tytul2 -> setDefaultTextColor(Qt::black);
    tytul2 -> setFont(font2);
    tytul1 -> setPos((this -> width() - tytul1 -> boundingRect().width()) / 2, 150);
    tytul2 -> setPos(tytul1 -> pos().x() - 2, tytul1 -> pos().y() - 2);
    QPen whitePen(Qt::white);
    whitePen.setWidth(1);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);
    scena -> addItem(tytul2);
    scena -> addItem(tytul1);

    Guzik* playGuzik = new Guzik(QString("Graj"));
    int gxPoz = this -> width()/2 - playGuzik -> boundingRect().width()/2;
    int gyPoz = 275;
    playGuzik -> setPos(gxPoz, gyPoz);
    connect(playGuzik,SIGNAL(wcisniety()),this,SLOT(start()));
    scena -> addItem(playGuzik);

    Guzik* exitGuzik = new Guzik(QString("Wyjdź"));
    int exPoz = this -> width()/2 - exitGuzik -> boundingRect().width()/2;
    int eyPoz = 350;
    exitGuzik -> setPos(exPoz, eyPoz);
    connect(exitGuzik, SIGNAL(wcisniety()), this, SLOT(close()));
    scena -> addItem(exitGuzik);

}

QString Gra::getKogoTura(){
    return kogoTura_;
}

void Gra::setKogoTura(QString gracz){

    kogoTura_ = gracz;

    kogoTuraTekst -> setPlainText(QString("Ruch po stronie: \n       ") + gracz);
}

void Gra::pickUpStatek(Boks *statek){
    if(statek -> getOwner() == getKogoTura() && statekDoPost == NULL){
        statekDoPost = statek;
        originalPos = statek -> pos();
        statekPrzeciwnika = statek;
        return;
    }
}

void Gra::placeStatek(Boks *boksDoZmiany){

    statekDoPost->setPos(boksDoZmiany->pos());
    boksPlansza->getBoksy().removeAll(boksDoZmiany);
    boksPlansza->getBoksy().append(statekDoPost);
    scena->removeItem(boksDoZmiany);
    statekDoPost->setIsPlaced(true);
    usunZeStolu(statekDoPost,getKogoTura());
    statekDoPost = NULL;
    sprawdzCzyTrafil(statekPrzeciwnika);
    zmianaTury();
}

void Gra::pickUpStatek2(Boks2 *statek){

    if(statek -> getOwner2() == getKogoTura() && statekDoPost == NULL){
        statekDoPost2 = statek;
        originalPos = statek -> pos();
        return;
    }
}

void Gra::placeStatek2(Boks2 *boksDoZmiany2)
{
    statekDoPost2->setPos(boksDoZmiany2->pos());
    boksPlansza2->getBoksy2().removeAll(boksDoZmiany2);
    boksPlansza2->getBoksy2().append(statekDoPost2);
    scena->removeItem(boksDoZmiany2);
    statekDoPost2->setIsPlaced2(true);
    usunZeStolu2(statekDoPost2,getKogoTura());
    statekDoPost2 = NULL;

    zmianaTury();
}



void Gra::zmianaTury(){

    if(getKogoTura() == QString("Gracz1")){
        setKogoTura(QString("Gracz2"));
          BoksPlansza2();
    }

    else{
        setKogoTura(QString("Gracz1"));
    }

}

void Gra::usunZeStolu(Boks *statek, QString gracz){

    if(gracz == QString("Gracz1")){
        statkiGracz1.removeAll(statek);
    }
}

void Gra::usunZeStolu2(Boks2 *statek, QString gracz)
{
    if(gracz == QString("Gracz2")){
        statkiGracz2.removeAll(statek);
    }
}

void Gra::mouseMoveEvent(QMouseEvent *event){

    if(statekDoPost){
        statekDoPost -> setPos(event -> pos());
    }

    QGraphicsView::mouseMoveEvent(event);

}

void Gra::mousePressEvent(QMouseEvent *event){

    if(event -> button() == Qt::RightButton){
        if(statekDoPost){
            statekDoPost -> setPos(originalPos);
            statekDoPost = NULL;
            return;
        }
    }

    QGraphicsView::mousePressEvent(event);
}

void Gra::oddajStrzal(){
    // tutaj dodaj kod, który będzie obsługiwał oddany strzał
}


void Gra::sprawdzCzyTrafil(Boks* statek){
    if (statek->getOwner() == QString("NOONE")) {
        statek->setOwner(QString("Gracz2"));
        statek->setBrush(QBrush(Qt::red));
    } else if (statek->getOwner() == QString("Gracz1")) {
        statek->setBrush(QBrush(Qt::yellow));
        statek->setOwner(QString("ZATOPIONY"));
        // TODO: zaznacz, że statek przeciwnika został zatopiony
    }
}
