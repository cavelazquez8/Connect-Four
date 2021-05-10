#include "InputValidation.h"
/*
 *File: Board.h
 *Author:Carlos Velazquez
 *Created: April 26, 2020
 *Created for the purpose of input validation
 */

/****************************************************************\
* isInt                                                          *
* This function ensures the user enters an integer when it       *
* is required                                                    *
* Precondition: User input                                       *
* Postcondition: User input as integer                           *   
\****************************************************************/
void isInt(int &n){
    while (!cin) {
            cout << "Error: that wasn't a number" << endl;
            cout << "Please try again: " ;
            cin.clear();
            cin.ignore();
            cin >> n;
        }
    cout << endl;
}

/****************************************************************\
* checkNum                                                       *
* This function ensures an integer within the range is entered   *
* Precondition: User input, lower bound, and higher bound        *
* Postcondition: User input within the range                     *   
\****************************************************************/
void checkNum(int &n, int lowBound, int highBound)
{
    set<int> playerOptions;
    typedef set<int>::iterator it;
    it iter = playerOptions.end();
     
    //Fill the set
    for(int i = lowBound; i <= highBound; i++)
    {
        playerOptions.insert(i);
    }
    
    //If the user's input isn't in the set
    //have the user enter new input
    while(playerOptions.find(n) == iter )
    {
        cout << "Error: Invalid Input" << endl;
        cout << "Please try again: ";
        cin >> n;
        isInt(n);
        cout << endl;
    }
}
