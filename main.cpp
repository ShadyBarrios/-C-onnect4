#include <iostream>
#include "board.h"
#include <cctype>

// check formula
// (column, column[currentColumn].coinAtPosition(column[currentColumn].getRow()), currentColumn, column[currentColumn].getRow())

int main(){
    bool invalidPlacement;
    int playerOne = 1;
    int playerTwo = 2;
    bool noWinner;
    bool winner;
    int currentColumn;
    int currentPlayer = 0;
    char charSelection; 
    int intSelection;
    int setOfVerifies; // decides which verification methods to use

    board *column = new board[numberOfColumns];
    initializeBoard(column);
    displayBoard(column);

    do{
        try{
            if(currentPlayer == 0)
                currentPlayer = 1;
            else if(currentPlayer == 1)
                currentPlayer = 2;
            else if(currentPlayer == 2)
                currentPlayer = 1;

            

            std::cout << "Player " << currentPlayer << ", it is your turn...\n";

            do{
                std::cout << "Select a column: ";
                std::cin >> charSelection;
                charSelection = toupper(charSelection);
                charVerification(charSelection);
                intSelection = toInt(charSelection);
                invalidPlacement = column[intSelection].insertNewCoin(currentPlayer);

                if(invalidPlacement)
                    std::cout << "Column " << charSelection << " is full. Try again\n";
            }while(invalidPlacement);

            winner = verify(column[intSelection].getRow(), intSelection, column);

            displayBoard(column);

            if(winner)
                throw(currentPlayer);

            winner = false;
        }
        catch(int daWinner){
            std::cout << "DING DING DING WE HAVE A WINNER!\n";
            std::cout << "Winner: ";
            if(daWinner == 1)
                std::cout << "Player 1" << std::endl;
            else
                std::cout << "Player 2" << std::endl;

            winner = true;
        }
    }while(winner == false);

    std::cout << "Thanks for playing! " << std::endl;

    return 0;
}
