#include "BoksPlansza.h"
#include "Gra.h"

extern Gra* gra;

BoksPlansza::BoksPlansza(){

}

QList<Boks *> BoksPlansza::getBoksy(){
    return boksy;
}

void BoksPlansza::placeBoksy(int x, int y, int kol, int rzad){
    int X_SHIFT = 27;

    for(size_t i=0, n=kol; i<n; i++){
        createBoksColumn(x+X_SHIFT*i,y,rzad);
    }
}

void BoksPlansza::createBoksColumn(int x, int y, int ilosc){
    for(size_t i=0, n=ilosc; i<n; i++){
        Boks* boks = new Boks();
        boks -> setPos(x,y+27*i);
        boksy.append(boks);
        gra -> scena -> addItem(boks);

        boks -> setOwner(QString("NOONE"));
        boks -> setIsPlaced(true);
    }
}
