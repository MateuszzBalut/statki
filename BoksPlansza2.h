#ifndef BOKSPLANSZA2_H
#define BOKSPLANSZA2_H

#include <QList>
#include "Boks2.h"

class BoksPlansza2{
public:
    BoksPlansza2();

    QList<Boks2*> getBoksy2();

    void placeBoksy2(int x2, int y2, int kol2, int rzad2);

private:
    void createBoksColumn2(int x2, int y2, int ilosc2);
    QList<Boks2*> boksy2;
};

#endif // BOKSPLANSZA2_H
