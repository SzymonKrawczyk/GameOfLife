//
//          Klasa przechoiwujaca komorki w tablicy 2-wymiarowej (.cpp)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 29.02.2020
//
//      Modyfikacje:
//          01.03.2020, Szymon Krawczyk - Zmiana sposobu pobierania komorek
//

#include "cellArray.h"

namespace KrawczykS {

    void CellArray::deleteCellStorage() {

        for (int i = 0; i < _width; i++) {

            delete[] _cellStorage[i];
        }
        delete[] _cellStorage;
    }

    void CellArray::createCellStorage(unsigned short width_, unsigned short height_) {

        _cellStorage = new Cell * [_width];

        for (int i = 0; i < _width; i++) {

            _cellStorage[i] = new Cell[_height];
        }
    }

    CellArray::CellArray(unsigned short width_, unsigned short height_)
        :
            _width(width_)
        ,   _height(height_)
        ,   _cellStorage(nullptr)
    {
        createCellStorage(_width, _height);
    }

    CellArray::CellArray(const CellArray& copy_)
        :
            _width(copy_._width)
        ,   _height(copy_._height)
        ,   _cellStorage(nullptr)
    {
        createCellStorage(_width, _height);

        for (int i = 0; i < _width; i++) {
            for (int j = 0; j < _height; j++) {
                _cellStorage[i][j] = copy_._cellStorage[i][j];
            }
        }
    }

    CellArray& CellArray::operator=(const CellArray& copy_) {

        if (this != &copy_) {

            deleteCellStorage();

            _width = copy_._width;
            _height = copy_._height;
            createCellStorage(_width, _height);

            for (int i = 0; i < _width; i++) {
                for (int j = 0; j < _height; j++) {
                    _cellStorage[i][j] = copy_._cellStorage[i][j];
                }
            }
        }
        return *this;
    }

    CellArray::~CellArray() {

        deleteCellStorage();
    }


    Cell& CellArray::getCellRef(unsigned short PosX_, unsigned short PosY_) {

        return _cellStorage[PosX_][PosY_];
    }

    const Cell& CellArray::getCellCRef(unsigned short PosX_, unsigned short PosY_) const {

        return _cellStorage[PosX_][PosY_];
    }

    unsigned short CellArray::getWidth() const {

        return _width;
    }

    unsigned short CellArray::getHeight() const {

        return _height;
    }
}