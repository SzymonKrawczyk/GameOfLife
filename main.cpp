//
//          Program uruchamiajacy Gre W Zycie
//
//      Autor: Szymon Krawczyk
//
//      Data utworzenia: 29.02.2020
//


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>    // Sleep(ms)
#include <stdlib.h>     // exit(EXIT_FAILURE)

#include "game.h";
#include "gameConsole.h";
//#include "gameAPI.h";


using std::cin;
using std::cout;
using std::clog;
using std::ifstream;
using std::vector;

using KrawczykS::Game;
using KrawczykS::GameConsole;
//using KrawczykS::GameAPI;


int main() {


    unsigned short gameMode = 1;
    unsigned short FPS = 2;
    unsigned short gameWidth = 10, gameHeight = 10;
    vector<unsigned short> startingPosX;
    vector<unsigned short> startingPosY;
    vector<unsigned short> aliveRules;
    vector<unsigned short> deadRules;
    Game* mainGame = nullptr;

    // Game setup
    try {

        ifstream fileIn;
        fileIn.open("gameSetup.ini");
        if (!fileIn.is_open()) {
            throw std::string("\nNieudane otworzenie pliku \"gameSetup.ini\"\n");
        }
        fileIn >> gameMode;
        fileIn >> FPS;
        fileIn >> gameWidth >> gameHeight;

        unsigned short temp = 0;
        while (fileIn.peek() != '|') {
            fileIn >> temp;
            aliveRules.push_back(temp);
        }
        fileIn.get();
        while (fileIn.peek() != '|') {
            fileIn >> temp;
            deadRules.push_back(temp);
        }
        fileIn.get();
        fileIn.close();

        switch (gameMode) {
            case 1: 
                mainGame = new GameConsole(gameWidth, gameHeight);
                break;
            case 2:
                //mainGame = new GameAPI(gameWidth, gameHeight);
                break;
            default:
                throw std::string("\nNieznany tryb gry!\n");
                break;
        }

        mainGame->setAliveRules(aliveRules);
        mainGame->setDeadRules(deadRules);

        fileIn.open("cellStartingPositions.ini");
        if (!fileIn.is_open()) {
            throw std::string("\nNieudane otworzenie pliku \"cellStartingPositions.ini\"\n");
        }
        unsigned int tempX = 0, tempY = 0;
        while (fileIn >> tempX >> tempY) {

            if (tempX >= gameWidth || tempY >= gameHeight) {
               throw std::string("\nNiepoprawna pozycja komorki!\n");
            }
            startingPosX.push_back(tempX);
            startingPosY.push_back(tempY);
        }
        fileIn.close();
        mainGame->setStartingPositions(startingPosX, startingPosY);
    }
    catch (std::string err) {

        clog << "\n" << err << "\n";
        cin.get();
        exit(EXIT_FAILURE);
    }
    //

    // Game
        while (true) {
            mainGame->play();
            //cin.get();
            Sleep(1000 / FPS);
        }
    //

    delete mainGame;

    return 0;
}