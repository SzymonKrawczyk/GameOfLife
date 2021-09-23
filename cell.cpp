//
//          Klasa opisujaca komorke z dwoma stanami - zywa/ martwa (.cpp)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 29.02.2020
//
//

#include "cell.h"

namespace KrawczykS {

    Cell::Cell(bool alive_) 
        :
        _alive(alive_)
    {}

    Cell::Cell(const Cell& copy_)
        :
        _alive(copy_._alive)
    {}

    Cell& Cell::operator=(const Cell& copy_) {
        if (this != &copy_) {
            _alive = copy_._alive;
        }
        return *this;
    }

    Cell::~Cell() {}


    void Cell::setAlive(bool input_) {

        _alive = input_;
    }

    bool Cell::isAlive() const {

        return _alive;
    }

}