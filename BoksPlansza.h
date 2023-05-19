#ifndef BOKSPLANSZA_H
#define BOKSPLANSZA_H

#include <QList>
#include "Boks.h"

class BoksPlansza{
public:
    BoksPlansza();

    QList<Boks*> getBoksy();

    void placeBoksy(int x, int y, int kol, int rzad);

private:
    void createBoksColumn(int x, int y, int ilosc);
    QList<Boks*> boksy;
};

#endif // BOKSPLANSZA_H
