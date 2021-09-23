//
//          Klasa do Gry W Zycie obslugujaca konsole (.h)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 29.02.2020
//
//

#ifndef GAMECONSOLE_H_
#define GAMECONSOLE_H_

#include "game.h"

namespace KrawczykS {

    class GameConsole : public Game {
    public:

        GameConsole(unsigned short = 0, unsigned short = 0);
        GameConsole(const GameConsole&) = delete;
        GameConsole& operator=(const GameConsole&) = delete;
        virtual ~GameConsole();

        virtual void view() const;

    };
}

#endif