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
    int currentColumn;

    board *column = new board[numberOfColumns];
    initializeBoard(column);

    displayBoard(column);

    column[4].insertNewCoin(playerOne);

    column[3].insertNewCoin(playerTwo);
    column[3].insertNewCoin(playerOne);
    
    column[2].insertNewCoin(playerTwo);
    column[2].insertNewCoin(playerTwo);
    column[2].insertNewCoin(playerOne);
    
    column[1].insertNewCoin(playerTwo);
    column[1].insertNewCoin(playerTwo);
    column[1].insertNewCoin(playerTwo);
    column[1].insertNewCoin(playerOne);

    displayBoard(column);

    currentColumn = 1;

    if(lDiagonalCheck4(column, column[currentColumn].coinAtPosition(column[currentColumn].getRow()), currentColumn, column[currentColumn].getRow()))
        std::cout << "The system is accurate" << std::endl;

    return 0;
}

void dropping(int col, int play){
    std::cout << "Dropping " << play << " into column " << col << std::endl;
}