//
//          Klasa opisujaca komorke z dwoma stanami - zywa/ martwa (.h)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 29.02.2020
//
//

#ifndef CELL_H_
#define CELL_H_

namespace KrawczykS {

    class Cell {
    private:

        bool _alive;

    public:

        Cell(bool = false);
        Cell(const Cell&);
        Cell& operator=(const Cell&);
        virtual ~Cell();

        void setAlive(bool);
        bool isAlive() const;

    };
}

#endif