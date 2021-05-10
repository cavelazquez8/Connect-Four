/*
 *File: Board.h
 *Author:Carlos Velazquez
 *Created: April 2020
 * 
 * Purpose: Represent a Connect Four board
 */

#ifndef BOARD_H
#define BOARD_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <map>

#include "Player.h"
#include "InputValidation.h" //For isInt and checkNum

/****************************************************************\
* Board                                                          *
* This class is designed to hold the attributes of the game board*
* and the functions to modify those attributes                   *                                                   *
\****************************************************************/
class Board{
private:
    //Board is 6 by 7
    //Vector of Vectors
    vector<vector<char>> board;
    //Iterator for vector of vectors
    vector< vector<char> >::iterator row;
    //Iterator for vectors inside vector of vectors
    vector<char>::iterator col;
    //For recording and printing where the Connect 4 occured
    map<pair<int, int>, char> winningSpots;
    
public:
    //The default constructor initiates the board vector to empty chars
    Board():board(6 ,vector<char>(7, ' ')){};
    void displayBoard();//displays board
    void displayWinningCombo();//Displays where the player won
    void updateBoard(int, Player);//Performs the user's move and updates board
    int computerDrop(Player computer);//Performs the computer's drop
    int drop(Player player);//Validates and returns the user's move
    bool checkDiag(Player);//Checks for a connect 4 along the diagonals
    bool checkHoriz(Player);//Checks for a connect 4 along the horizontals
    bool checkVert(Player);//Checks for a connect 4 along the verticals
    bool checkDraw();//Checks if the board is full
    bool winner(Player);//Checks if the player who made the most recent move has won
    
};

#endif /* BOARD_H */

