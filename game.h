//
//          Klasa abstrakcyjna do Gry W Zycie (.h)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 29.02.2020
//
//      Modyfikacje:
//          07.03.2020, Szymon Krawczyk - Umieszczenie obliczania zywych sasiadow w osobnej metodzie
//

#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "cellArray.h"

namespace KrawczykS {

    class Game {
    private:

        std::vector<unsigned short> _aliveRules;
        std::vector<unsigned short> _deadRules;

    protected:

        CellArray _gameCellStorage;

    public:

        Game(unsigned short = 0, unsigned short = 0);
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;
        virtual ~Game();

        void setStartingPositions(std::vector<unsigned short>, std::vector<unsigned short>);
        void setAliveRules(std::vector<unsigned short>);
        void setDeadRules (std::vector<unsigned short>);

        unsigned short howManyAliveNeighbors(unsigned short, unsigned short);
        void analyse();
        void play();

        virtual void view() const = 0;

    };
}

#endif