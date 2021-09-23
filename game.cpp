//
//          Klasa abstrakcyjna do Gry W Zycie (.cpp)
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 29.02.2020
//
//      Modyfikacje:
//          01.03.2020, Szymon Krawczyk - Zmiana sposobu pobierania danych z tablicy komorek
//          07.03.2020, Szymon Krawczyk - Umieszczenie obliczania zywych sasiadow w osobnej metodzie
//

#include "game.h"

namespace KrawczykS {

    Game::Game(unsigned short width_, unsigned short height_)
        :
            _gameCellStorage(width_, height_)
        ,   _aliveRules()
        ,   _deadRules()
    {}

    Game::~Game() {}

    void Game::setStartingPositions(std::vector<unsigned short>posX, std::vector<unsigned short>posY) {

        for (int i = 0; i < posX.size(); i++) {
            _gameCellStorage.getCellRef(posX[i], posY[i]).setAlive(true);
        }
    }

    void Game::setAliveRules(std::vector<unsigned short> input_) {

        _aliveRules = input_;
    }

    void Game::setDeadRules(std::vector<unsigned short> input_) {

        _deadRules = input_;
    }

    unsigned short Game::howManyAliveNeighbors(unsigned short width, unsigned short height) {

        unsigned short tempW = _gameCellStorage.getWidth();
        unsigned short tempH = _gameCellStorage.getHeight();
        unsigned short total = 0;

        // Calculate alive neighbors depending on position (corner - only 3 neighbors etc.)
        if (width > 0 && height > 0 && height < tempH - 1 && width < tempW - 1) {
            total += _gameCellStorage.getCellCRef(width - 1, height - 1).isAlive();
            total += _gameCellStorage.getCellCRef(width - 1, height).isAlive();
            total += _gameCellStorage.getCellCRef(width - 1, height + 1).isAlive();
            total += _gameCellStorage.getCellCRef(width, height - 1).isAlive();
            total += _gameCellStorage.getCellCRef(width, height + 1).isAlive();
            total += _gameCellStorage.getCellCRef(width + 1, height - 1).isAlive();
            total += _gameCellStorage.getCellCRef(width + 1, height).isAlive();
            total += _gameCellStorage.getCellCRef(width + 1, height + 1).isAlive();
        }
        else if (width == 0 && height > 0 && height < tempH - 1) {
            total += _gameCellStorage.getCellCRef(width, height - 1).isAlive();
            total += _gameCellStorage.getCellCRef(width, height + 1).isAlive();
            total += _gameCellStorage.getCellCRef(width + 1, height - 1).isAlive();
            total += _gameCellStorage.getCellCRef(width + 1, height).isAlive();
            total += _gameCellStorage.getCellCRef(width + 1, height + 1).isAlive();
        }
        else if (width > 0 && width < tempW - 1 && height == 0) {
            total += _gameCellStorage.getCellCRef(width - 1, height).isAlive();
            total += _gameCellStorage.getCellCRef(width + 1, height).isAlive();
            total += _gameCellStorage.getCellCRef(width - 1, height + 1).isAlive();
            total += _gameCellStorage.getCellCRef(width, height + 1).isAlive();
            total += _gameCellStorage.getCellCRef(width + 1, height + 1).isAlive();
        }
        else if (width == tempW - 1 && height > 0 && height < tempH - 1) {
            total += _gameCellStorage.getCellCRef(width, height - 1).isAlive();
            total += _gameCellStorage.getCellCRef(width, height + 1).isAlive();
            total += _gameCellStorage.getCellCRef(width - 1, height - 1).isAlive();
            total += _gameCellStorage.getCellCRef(width - 1, height).isAlive();
            total += _gameCellStorage.getCellCRef(width - 1, height + 1).isAlive();
        }
        else if (width > 0 && width < tempW - 1 && height == tempH - 1) {
            total += _gameCellStorage.getCellCRef(width - 1, height).isAlive();
            total += _gameCellStorage.getCellCRef(width + 1, height).isAlive();
            total += _gameCellStorage.getCellCRef(width - 1, height - 1).isAlive();
            total += _gameCellStorage.getCellCRef(width, height - 1).isAlive();
            total += _gameCellStorage.getCellCRef(width + 1, height - 1).isAlive();
        }
        else if (width == 0 && height == 0) {
            total += _gameCellStorage.getCellCRef(width, height + 1).isAlive();
            total += _gameCellStorage.getCellCRef(width + 1, height).isAlive();
            total += _gameCellStorage.getCellCRef(width + 1, height + 1).isAlive();
        }
        else if (width == tempW - 1 && height == 0) {
            total += _gameCellStorage.getCellCRef(width - 1, height).isAlive();
            total += _gameCellStorage.getCellCRef(width - 1, height + 1).isAlive();
            total += _gameCellStorage.getCellCRef(width, height + 1).isAlive();
        }
        else if (width == tempW - 1 && height == tempH - 1) {
            total += _gameCellStorage.getCellCRef(width - 1, height - 1).isAlive();
            total += _gameCellStorage.getCellCRef(width, height - 1).isAlive();
            total += _gameCellStorage.getCellCRef(width - 1, height).isAlive();
        }
        else if (width == 0 && height == tempH - 1) {
            total += _gameCellStorage.getCellCRef(width, height - 1).isAlive();
            total += _gameCellStorage.getCellCRef(width + 1, height - 1).isAlive();
            total += _gameCellStorage.getCellCRef(width + 1, height).isAlive();
        }

        return total;
    }

    void Game::analyse() {

        unsigned short tempW = _gameCellStorage.getWidth();
        unsigned short tempH = _gameCellStorage.getHeight();

        CellArray temp(tempW, tempH);

        for (int width = 0; width < tempW; width++) {
            for (int height = 0; height < tempH; height++) {

                int aliveNeighbors = howManyAliveNeighbors(width, height);
                
                
                // Change state of cell if needed
                if (_gameCellStorage.getCellCRef(width, height).isAlive()) {

                    temp.getCellRef(width, height).setAlive(false);
                    for (int i = 0; i < _aliveRules.size(); i++) {

                        if (aliveNeighbors == _aliveRules[i]) {

                            temp.getCellRef(width, height).setAlive(true);
                            break;
                        }
                    }
                }
                else {

                    temp.getCellRef(width, height).setAlive(false);
                    for (int i = 0; i < _deadRules.size(); i++) {

                        if (aliveNeighbors == _deadRules[i]) {

                            temp.getCellRef(width, height).setAlive(true);
                            break;
                        }
                    }
                }
            }
        }
        _gameCellStorage = temp;
    }

    void Game::play() {

        analyse();
        view();
    }

}