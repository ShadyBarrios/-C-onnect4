#include <iostream>
#include "board.h"

// check formula
// (column, column[currentColumn].coinAtPosition(column[currentColumn].getRow()), currentColumn, column[currentColumn].getRow())

void dropping(int, int);

int main(){
    int playerOne = 1;
    int playerTwo = 2;
    bool noWinner;
    int winner;

    board *column = new board[numberOfColumns];
    initializeBoard(column);

    displayBoard(column);

    column[1].insertNewCoin(playerOne);
    column[2].insertNewCoin(playerTwo);
    column[2].insertNewCoin(playerOne);
    
    column[3].insertNewCoin(playerTwo);
    column[3].insertNewCoin(playerTwo);
    column[3].insertNewCoin(playerOne);
    
    column[4].insertNewCoin(playerTwo);
    column[4].insertNewCoin(playerTwo);
    column[4].insertNewCoin(playerTwo);
    column[4].insertNewCoin(playerOne);

    displayBoard(column);

    if(rDiagonalCheck1(column, column[1].coinAtPosition(column[1].getRow()), 1, column[1].getRow()))
        std::cout << "The system is accurate" << std::endl;

    return 0;
}

void dropping(int col, int play){
    std::cout << "Dropping " << play << " into column " << col << std::endl;
}