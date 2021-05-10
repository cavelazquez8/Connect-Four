/*
 *File: Board.h
 *Author:Carlos Velazquez
 *Created: April 25, 2020
 * 
 */

#include "Board.h"
    /*****************************************************************************\
    * displayBoard                                                                *
    * This functions displays the Connect 4 board                                 *
    * using a for loop with three for loop inside                                 *                                                                                                                          *
    \*****************************************************************************/
    void Board :: displayBoard()
    {
        //Columns
	cout<<"  1      2      3      4      5      6      7\n";
        //First loop 
        //Traverses the rows
	for(row = board.begin(); row != board.end(); row++)
        {
            //Second loop
            //Traverses each element in each row using iterators
            //Prints the top half the of squares 
            for(col = row->begin(); col != row->end(); col++)
            {
                cout<<"┌─┐ ";
            }
            
            cout<<'\n';
            
            //Third loop
            //Traverses each element in each row
            //Prints the sides of the squares with the 
            //player's move inside
            for(col = row->begin(); col != row->end(); col++)
            {
                cout<<"│ "<<*col<<"│ " ;
            }
            //Fourth loop
            //Traverses each element in each row
            //Prints the bottom half of the squares
            cout<<'\n';
            for(col = row->begin(); col != row->end(); col++) 
            {
                cout <<"└─┘ ";
            }
            cout<<'\n';
        }
    }
    /*****************************************************************************\
    * drop                                                                        *
    * This function is for the player's move, a column of choice.                 *
    * The function validates the move and returns the column selected             *
    * Precondition: None                                                          *
    * Postcondition: User's column of choice                                      *                                                *                                                                           *
    \*****************************************************************************/
    int Board :: drop(Player player) 
    {
        int columnSelected;
        cout << player.playerName << "'s Turn " << endl;
        cout << "Enter a number from 1 to 7: ";
        cin >> columnSelected;
        //Input validation
        isInt(columnSelected);
        checkNum(columnSelected, 1, 7);
        cout << endl;
        //Input validation
        //Checks if the user chose a column
        //that is full by checking if the top-most row is 
        //not empty
        while (board[0][columnSelected-1] != ' ') 
        {
            cout << "ERROR: Full Column " << endl;
            cout << "Choose a different column: ";
            cin >> columnSelected;
            //Input validation
            isInt(columnSelected);
            checkNum(columnSelected, 1, 7);
            cout<< endl;
        }
      
      
        return columnSelected-1;
}
    /*****************************************************************************\
    * computerDrop                                                                *
    * This function is for the computer's move                                    *
    * The function validates the move and returns the column selected             *
    * Precondition: None                                                          *
    * Postcondition: User's column of choice                                      *                                                                                                                     *
    \*****************************************************************************/
    int Board :: computerDrop(Player computer) 
    {
        srand(static_cast<unsigned int>(time(0)));
        int columnSelected = rand()%7 + 1;
        int temp;
        cout << computer.playerName << "'s Turn " << endl;
        
        //Input validation
        //Checks if the computer chose a column
        //that is full by checking if the top-most row is 
        //not empty
        while (board[0][columnSelected] != ' ') 
        {
            temp = rand()%7 + 1;
            swap(temp, columnSelected);
            
        }
        return columnSelected-1;
    }
    
    /*****************************************************************************\
    * updateBoard                                                                 *
    * This function performs the player's move and updates the board for display  *                                                                                                                               
    * Precondition: columnSelected, the players' move.                             *
    *               player, the player who made the move.                         *                                
    * Postcondition: The board will be update to include the player's move        *
    * and will be ready for display                                 *                                                                                                                        
    \*****************************************************************************/
    void Board::updateBoard(int columnSelected, Player player)
    {
        //Declares r for row index
        //Declares turn for do while loop
        int r, turn;
        //Bottom-most row
	r = 5;
	turn = 0;

	do 
	{   
            //Checks which row of the selected column has an empty space
            //Starts with the bottom-most row
            if ( board[r][columnSelected] == ' ')
            {
                board[r][columnSelected] = player.getSymbol();
                turn = 1;
            }
            //Moves up a row if there's no empty space in the previous row
            else
            {
                r--;
            }
	}while (turn != 1 );
    }
    
    /*****************************************************************************\
    * checkDiag                                                                   *
    * This function checks there's a connect 4 along the diagonals                *                                                                                                                                                                         
    * Postcondition: Information about the player who made the most recent move   *
    * and will be ready for display   
    * Precondition: Function returns true and the player wins.                                                                                                                                                               
    \*****************************************************************************/
    bool Board::checkDiag(Player player){
        char symb = player.getSymbol();
        //the  Checks for connect 4 along diagonals 
        //going from South East to North West
        //Works for North West to South East
        //The loop starts at the last row and last column
        for( int r = 5; r >= 3; r-- )
        {
            for( int c = 6; c >= 3; c-- )
            {
                if( board[r][c] == symb &&
                    board[r-1][c-1] == symb&&
                    board[r-2][c-2] == symb &&
                    board[r-3][c-3] == symb)
                {
                     winningSpots[{r, c}] = symb;
                    winningSpots[{r-1,c-1}] = symb;
                    winningSpots[{r-2,c-2}] = symb;
                    winningSpots[{r-3,c-3}] = symb;
                    return true;
                }
                    
            }
            //Checks for connect 4 along diagonals 
            //going from South West to North East
            //Works for North East to South West
             for( int c = 0; c <= 3; c++)
             {
                if( board[r][c] == symb &&
                    board[r-1][c+1] == symb&&
                    board[r-2][c+2] == symb &&
                    board[r-3][c+3] == symb)
                {
                     winningSpots[{r, c}] = symb;
                    winningSpots[{r-1,c+1}] = symb;
                    winningSpots[{r-2,c+2}] = symb;
                    winningSpots[{r-3,c+3}] = symb;
                    return true;
                }     
            } 
        }
        return false;
    }
    /*****************************************************************************\
    * checkHoriz                                                                  *
    * This function checks there's a connect 4 along the horizontals              *                                                                                                                               
    * Precondition: Information of player who made the most recent move           *                                                        
    * Postcondition: If the function returns true, the player wins                *                                                                                                                        
    \*****************************************************************************/
    bool Board::checkHoriz(Player player)
    {
        char symb = player.getSymbol();
        //Traverses through each row
        for( int r = 5; r >= 0; r-- )
        {
            //Checks for Connect 4 along horizontal going from right to left
            for( int c = 6; c >= 3; c--)
            {
                //Condition: starting from the rth row and cth column, check
                //if the player's symbol appears continously four times from right to left
                if( board[r][c] == symb &&
                    board[r][c-1] == symb&&
                    board[r][c-2] == symb &&
                    board[r][c-3] == symb)
                {
                    winningSpots[{r,c}] = symb;
                    winningSpots[{r,c-1}] = symb;
                    winningSpots[{r,c-2}] = symb;
                    winningSpots[{r,c-3}] = symb;
                    return true;
                }           
            }
            
            for( int c =0;c <= 3;c++){
                //Condition: starting from the rth row and cth column, check
                //if the player's symbol appears continously four times from left to right
                if( board[r][c] == symb &&
                    board[r][c+1] == symb&&
                    board[r][c+2] == symb &&
                    board[r][c+3] == symb)
                {
                    winningSpots[{r,c}] = symb;
                    winningSpots[{r,c+1}] = symb;
                    winningSpots[{r,c+2}] = symb;
                    winningSpots[{r,c+3}] = symb;
                    return true;
                }           
            }
        }
        return false;
    }
    /*****************************************************************************\
    * checkVert                                                                   *
    * This function checks there's a connect 4 along the verticals                *                                                                                                                               
    * Precondition: Information of player who made the most recent move           *                                                        
    * Postcondition: If the function returns true, the player wins                *                                                                                                                        
    \*****************************************************************************/
    bool Board::checkVert(Player player)
    { 
        char symb = player.getSymbol();
        //Traverses through each row
        for( int c = 0; c <= 6; c++ )
        {
            //Checks for Connect 4 along vertical going from bottom to top
            for( int r = 5; r <= 3; r--)
            {
                //Condition: starting from the rth row and cth column,
                //if the player's symbol appears continously four times from bottom to top
                //return true
                if( board[r][c] == symb &&
                    board[r-1][c] == symb&&
                    board[r-2][c] == symb &&
                    board[r-3][c] == symb)
                {
                    winningSpots[{r, c}] = symb;
                    winningSpots[{r-1, c}] = symb;
                    winningSpots[{r-2,c}] = symb;
                    winningSpots[{r-3, c}] = symb;
                    return true;
                }           
            }
            //Condition: starting from the rth row and cth column,
            //if the player's symbol appears continously four times from top to bottom
            //return true
            for( int r =0;r <= 2;r++)
            {
                if( board[r][c] == symb &&
                    board[r+1][c] == symb&&
                    board[r+2][c] == symb &&
                    board[r+3][c] == symb)
                {
                    winningSpots[{r, c}] = symb;
                    winningSpots[{r+1, c}] = symb;
                    winningSpots[{r+2,c}] = symb;
                    winningSpots[{r+3, c}] = symb;
                    return true;
                }           
            }
        }
        return false;
    }
    /*****************************************************************************\
    * checkDraw                                                                   *
    * This function checks for a draw                                             *                                                                                                                               
    * Precondition: Board with both player's moves                                *                                                        
    * Postcondition: If the function returns true, there's a draw                 *                                                                                                                         
    \*****************************************************************************/
    bool Board::checkDraw()
    {
        //Iterator for the first row
        row = board.begin();
        //Set col equal to find() which returns an iterator
        col = find(row->begin(), row->end(), ' ');
        if(col == row->end())
        {
            return true;
        }
        return false;
                  
                   
    }
    /*****************************************************************************\
    * winner                                                                      *
    * This function checks if the player who made the most recent move has won    *                                                                                                                               
    * Precondition: Information of player who made the most recent move           *                                                        
    * Postcondition: If the function returns true, the player wins                *                                                                                                                        
    \*****************************************************************************/
    bool Board::winner(Player player)
    {
        vector <bool> bit_vector;
        
        bit_vector.push_back(checkDiag(player));
        bit_vector.push_back(checkHoriz(player));
        bit_vector.push_back(checkVert(player));
        sort(bit_vector.begin(), bit_vector.end());
        if(find(bit_vector.begin(), bit_vector.end(), true) != bit_vector.end())
        {
            return true;
        }
        return false;
        
    }
     void Board:: displayWinningCombo()
     {
        vector<vector<char>> winningCombo(6 ,vector<char>(7, ' '));
        for ( map<pair<int,int>,char>::iterator it = winningSpots.begin(); it != winningSpots.end(); ++it ) 
        {
            winningCombo[it->first.first][it->first.second] = it->second;
            cout << "( " << (it->first.first)+1 << ", " 
            << (it->first.second)+1
            << " ): "
            << it->second
            << endl;
        }
         
        //Columns
	cout<<"  1      2      3      4      5      6      7\n";
        //First loop 
        //Traverses the rows
	for(row = winningCombo.begin(); row != winningCombo.end(); row++)
        {
            //Second loop
            //Traverses each element in each row using iterators
            //Prints the top half the of squares 
            for(col = row->begin(); col != row->end(); col++)
            {
                cout<<"┌─┐ ";
            }
            
            cout<<'\n';
            
            //Third loop
            //Traverses each element in each row
            //Prints the sides of the squares with the 
            //player's move inside
            for(col = row->begin(); col != row->end(); col++)
            {
                cout<<"│ "<<*col<<"│ " ;
            }
            //Fourth loop
            //Traverses each element in each row
            //Prints the bottom half of the squares
            cout<<'\n';
            for(col = row->begin(); col != row->end(); col++) 
            {
                cout <<"└─┘ ";
            }
            cout<<'\n';
        }
         
         
         
     }
    
  
  