//
//          Klasa przechoiwujaca komorki w tablicy 2-wymiarowej (.h)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 29.02.2020
//
//      Modyfikacje:
//          01.03.2020, Szymon Krawczyk - Zmiana sposobu pobierania komorek
//

#ifndef CELLARRAY_H_
#define CELLARRAY_H_

#include "cell.h";

namespace KrawczykS {

    class CellArray {
    private:

        unsigned short _width;
        unsigned short _height;

        Cell** _cellStorage;

    protected:

        void deleteCellStorage();
        void createCellStorage(unsigned short, unsigned short);

    public:

        CellArray(unsigned short, unsigned short);
        CellArray(const CellArray&);
        CellArray& operator=(const CellArray&);
        virtual ~CellArray();

              Cell& getCellRef (unsigned short, unsigned short);
        const Cell& getCellCRef(unsigned short, unsigned short) const;

        unsigned short getWidth()  const;
        unsigned short getHeight() const;

    };
}

#endif