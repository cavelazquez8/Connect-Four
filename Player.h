/*
 *File: Player.h
 *Author:Carlos Velazquez
 *Created: April 25, 2020
 *Purpose: Created to represent the players
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream> //Input output stream in C++
#include <cstdlib> //Stands for c standard library
using namespace std; 

/****************************************************************\
* Player class                                                   *
* This class is designed for representing the players            *
* participating.                                                 *
* A player is by their name and symbol of choice                 *                                                   
\****************************************************************/
class Player{
private:
    char playerSymbol;
    
public:  
    string playerName;
    Player(){}//Default constructor
    Player(int); //For Player 1 and 2
    //For computer
    Player(string name, char symbol )
    {
        playerName = name;
        playerSymbol = symbol;
    } 
    void checkSymbol(char one, char two); //Check if both player's have the same symbol
    char getSymbol() const { return playerSymbol;}//Return symbol of Player
};

#endif /* PLAYER_H */

