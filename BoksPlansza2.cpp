#include "BoksPlansza2.h"
#include "Gra.h"

extern Gra* gra;

BoksPlansza2::BoksPlansza2(){

}

QList<Boks2 *> BoksPlansza2::getBoksy2(){
    return boksy2;
}

void BoksPlansza2::placeBoksy2(int x2 ,int y2, int kol2, int rzad2){
    int X_SHIFT = 27;

    for(size_t i=0, n=kol2; i<n; i++){
        createBoksColumn2(x2+X_SHIFT*i,y2,rzad2);
    }
}

void BoksPlansza2::createBoksColumn2(int x2, int y2, int ilosc2){
    for(size_t i=0, n=ilosc2; i<n; i++){
        Boks2* boks2 = new Boks2();
        boks2 -> setPos(x2,y2+27*i);
        boksy2.append(boks2);
        gra -> scena -> addItem(boks2);

        boks2 -> setOwner2(QString("NOONE"));
        boks2 -> setIsPlaced2(true);
    }
}
