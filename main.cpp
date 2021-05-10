/* 
 * File:   main.cpp
 * Author: Carlos Velazquez
 * Created on April 25th, 2021
 * Purpose:  Connect 4 game
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <map>


#include "InputValidation.h"
#include "Player.h"
#include "Board.h"
#include "Game.h"

using namespace std;

int modeMenu();

int main(int argc, char** argv) {
    Board board;
    
    int mode = modeMenu();
    
    if(mode == 1)
    {
        Player one(1);
        Player computer("Computer", 'C');
        Game game(board,one,computer);
        game.computerMode();
    }
    else if( mode == 2)
    {
        Player one(1);
        Player two(2);
        two.checkSymbol(one.getSymbol(), two.getSymbol());
        Game game(board,one,two);
        game.twoPlayer();
    }
    
    return 0;
}
int modeMenu()
{
    int mode;
    cout << "CONNECT 4" << endl<< endl;
    cout << "Mode Selection" << endl;
    cout << "1. Computer" << endl;
    cout << "2. 2 players" << endl;
    cout << "Enter Number: ";
    cin >> mode;
    isInt(mode);
    checkNum(mode, 1, 2);
    cout << endl;
    return mode;
}






