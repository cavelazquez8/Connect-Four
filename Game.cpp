#include "Game.h"

/****************************************************************\
* playGame1                                                      *
* This function runs the Connect 4 game in 2 player mode         *
* Precondition: None                                             *
* Postcondition: A running game                                  *   
\****************************************************************/
void Game:: twoPlayer()
{
    //display an empty board
    board.displayBoard();
    
    while(true)
    {   
        int input; // User input
        //Have Player 1 make a move and update the board.
        board.updateBoard(board.drop(one), one);
        //Display the updated board
        board.displayBoard();
        //Check if Player 1 has won
        if(board.winner(one))
        {
            //If Player 1 wins,
            //Insert Player 1's symbol into the trackWinner queue.
            trackWinner.push(one.getSymbol());
            
            cout << one.playerName << " wins!"<< endl<<endl;
            cout <<"Location of Connect 4:"<< endl << endl;
            cout << "(row, column): symbol" << endl;
            //Display where Player 1 has won.
            board.displayWinningCombo();
            cout << endl;
           
            cout << "Would you like to restart?"<< endl;
            cout << "1. Yes"<< endl;
            cout << "2. No"<< endl;
            cout << "Enter number: ";
            cin >> input;
            isInt(input);
            checkNum(input, 1, 2);
            cout << endl;
            //If the Players choose to restart,
            //Empty the board and display it
            if(input == 1)
            {
                board = Board();
                board.displayBoard();
            }
            //If the players choose to not restart
            //show how many wins each player had 
            //and which player had the most wins.
            else
            {
                finalResult();
                cout << "Thanks for playing!" << endl;
                break;
            }
        }
        //Let Player 2 make a move and update the board 
        board.updateBoard(board.drop(two), two);
        //Display the updated board
        board.displayBoard();
        //Check if Player 2 has won
        if(board.winner(two))
        {
            //Insert Player 2's symbol into the trackWinner queue
            trackWinner.push(two.getSymbol());
            
            cout << two.playerName << " wins!"<< endl<<endl;
            cout <<"Location of Connect 4:"<< endl << endl;
            cout << "(row, column): symbol" << endl;
            //Display where Player 2 has won
            board.displayWinningCombo();
            cout << endl;
            
            //Ask player's if they want to restart
            cout << "Would you like to restart?"<< endl;
            cout << "1. Yes"<< endl;
            cout << "2. No"<< endl;
            cout << "Enter number: ";
            cin >> input;
            isInt(input);
            checkNum(input, 1, 2); 
            cout << endl;
            //If they player's choose to restart
            //Reset the board and display it
            if(input == 1)
            {
                board = Board();
                board.displayBoard();
            }
            //If the player's choose not to restart
            //show the final results
            else
            {
                //Show the number of wins each player had
                //Show which player had the most wins
                finalResult();
                cout << "Thanks for playing!" << endl;
                break;
            }
                    
        }
        //Check for a tie
        if(board.checkDraw()){
            cout<< "There's a draw!" << endl;
            cout << "The game will restart" << endl;
            //Reset the board
            board = Board();
            //Dispaly empty board
            board.displayBoard();
        }
    }

}
/****************************************************************\
* computerMode                                                   *
* This function runs the Connect 4 game in computer mode         *
* Precondition: None                                             *         
* Postcondition: A running Game against the computer             *   
\****************************************************************/
void Game::computerMode()
{
    //Display empty board
    board.displayBoard();
    while(true)
    {   int input; // User input
        //Have Player 1 make a move and update the board.
        board.updateBoard(board.drop(one), one);
        //Display updated board
        board.displayBoard();
        //Check if Player 1 has won
        if(board.winner(one))
        {
            //Insert Player 1's symbol into the trackWinner queue
            trackWinner.push(one.getSymbol());
            
            cout << one.playerName << " wins!"<< endl <<endl;
            cout <<"Location of Connect 4:"<< endl << endl;
            cout << "(row, column): symbol" << endl;
            //Display where Player 1 has won
            board.displayWinningCombo();
            cout << endl;
            
            cout << "Would you like to restart?"<< endl;
            cout << "1. Yes"<< endl;
            cout << "2. No"<< endl;
            cout << "Enter number: ";
            cin >> input;
            isInt(input);
            checkNum(input, 1, 2);
            cout << endl;
            
            //If Player 1 chooses to restart
            if(input == 1)
            {
                //Reset Board
                board = Board();
                //Display empty board
                board.displayBoard();
            }
            //If Player 1 chooses to not restart
            else
            {
                //Show the final results
                //Show the number of wins each player had
                //Show which player had the most wins
                finalResult();
                cout << "Thanks for playing!" << endl;
                break;
            }
        }
    
        //The computer's move
        int computerMove = board.computerDrop(two)+1;
        cout << "Computer Chooses: " << computerMove << endl << endl;
        
        //Update board
        board.updateBoard(computerMove-1, two);
        //Display board
        board.displayBoard();
        //If the computer wins
        if(board.winner(two))
        {
            //Insert the computer's symbol into the trackWinner queue
            trackWinner.push(two.getSymbol());
            
            cout << two.playerName << " wins!"<< endl << endl;
            cout <<"Location of Connect 4:"<< endl << endl;
            cout << "(row, column): symbol" << endl;
            //Display where the computer has won
            board.displayWinningCombo();
            cout << endl;
            
            cout << "Would you like to restart?"<< endl;
            cout << "1. Yes"<< endl;
            cout << "2. No"<< endl;
            cout << "Enter number: ";
            cin >> input;
            isInt(input);
            checkNum(input, 1, 2); 
            cout << endl;
            //If player 1 chooses to restart
            if(input == 1)
            {   
                //Reset Board
                board = Board();
                //Display empty board
                board.displayBoard();
            }
            else
            {
                //Show how many players each player had
                //Show which player had the most wins
                finalResult();
                cout << "Thanks for playing!" << endl;
                break;
            }
                    
        }
        //If there's a draw
        if(board.checkDraw())
        {
            cout<< "There's a draw!" << endl;
            cout << "The game will restart" << endl;
            //Reset board
            board = Board();
            //Display board
            board.displayBoard();
        }
    }
}
/****************************************************************\
* playGame1                                                      *
* This displays which player has the most wins                   *
*                                                                *   
\****************************************************************/
void Game::finalResult()
{
    //Counter for Player 1's wins
    int count1 = 0;
    //Counter for Player 2's wins
    int count2 = 0;
    //Count the number of wins
    while (!trackWinner.empty()) {
        if(trackWinner.front() == one.getSymbol())
        {
            count1++;
        }
        else
        {
            count2++;
        }
        trackWinner.pop();
    }
  
    priority_queue<int> overallWinner;
    //Push Player 1's and 2's wins into overallWinner
    overallWinner.push(count1);
    overallWinner.push(count2);
    cout << "Number of wins for " << one.playerName << ": "<< count1 << endl;
    cout << "Number of wins for " << two.playerName << ": "<< count2<< endl;
    //If player 1 has the most wins
    if(overallWinner.top() == count1)
    {
        cout << one.playerName << " has the most wins!" << endl;
    }
    //If player 2 has the most wins
    else if(overallWinner.top() == count2)
    {
        cout << two.playerName << " has the most wins!" << endl;
    }
    //If there's a tie
    else
    {
        cout << "It's a tie!" << endl;
    }
    cout << endl;
}
    
