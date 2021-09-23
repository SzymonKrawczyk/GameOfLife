//
//          Klasa do Gry W Zycie obslugujaca konsole (.cpp)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 29.02.2020
//
//      Modyfikacje:
//          01.03.2020, Szymon Krawczyk - Zmiana sposobu pobierania danych z tablicy komorek
//

#include <iostream>
#include "gameConsole.h"

namespace KrawczykS {

    GameConsole::GameConsole(unsigned short width_, unsigned short height_)
        :
            Game(width_, height_)
    {}

    GameConsole::~GameConsole() {}

    void GameConsole::view() const {

        unsigned short tempW = _gameCellStorage.getWidth();
        unsigned short tempH = _gameCellStorage.getHeight();
        system("CLS");

        for (unsigned short height = 0; height < tempH; height++) {
            for (unsigned short width = 0; width < tempW; width++) {

                if (_gameCellStorage.getCellCRef(width, height).isAlive()) {
                    std::cout << 'o';
                }
                else {
                    std::cout << ' ';
                }
            }
            std::cout << '\n';
        }
    }

}