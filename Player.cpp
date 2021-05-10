#include "Player.h"

/****************************************************************\
* Player constructor                                             *
* Initializes the Player class member variables using user input *
* Precondition: Player number                                    *
* Postcondition: playerName and playerSymbol are initialized     *   
\****************************************************************/
 Player:: Player(int num)
 {
    //For holding user input
    string name;
    char symbol;
    cout << "Enter Player " << num << " Name: ";
    cin.ignore();
    getline(cin, name);
    playerName = name;
    cout << "Enter Player " << num << " Symbol: ";
    cin >> symbol;
    playerSymbol = symbol;
    cout << endl;
}
/****************************************************************\
* checkSymbol                                                    *
* Ensures that the second player doesn't have the same symbol    *
* as the first player.                                           *
* Precondition: The symbols of both players                      *
* Postcondition: Players have different symbols                  *   
\****************************************************************/
void Player :: checkSymbol(char one, char two)
{
        //Makes sure both players don't have the same symbol
        while(one == two){
            cout <<"ERROR:Both players can't have the same symbol" << endl;
            cout <<"Try a different symbol: " ;
            cin >> two;
        }
        playerSymbol = two;
}
