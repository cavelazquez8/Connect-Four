/*
 *File: Game.h
 *Author:Carlos Velazquez
 *Created: April 26, 2020
 * 
 * Purpose: Use Player and Board objects to run the Connect 4 game.
 */
#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#include <queue>

#include "Board.h"
#include "Player.h"
#include "InputValidation.h"

/****************************************************************\
* Game                                                           *
* This class is designed for holding and modifying the components*
* necessary for running the Connect 4 game and as a result will  *
* give the main a minimalistic look                              *                                                   
\****************************************************************/
class Game{
private:
    Board board;
    Player one;
    Player two;
    //Keeps track of all the winning symbols
    queue<char> trackWinner;
public:
    Game(Board aBoard, Player aOne,Player aTwo){
        board = aBoard;
        one = aOne;
        two = aTwo;
    }
    void twoPlayer();
    void computerMode();
    void finalResult();
};

#endif /* GAME_H */

