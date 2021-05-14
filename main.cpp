#include <iostream>
#include "board.h"

// check formula
// (column, column[currentColumn].coinAtPosition(column[currentColumn].getRow()), currentColumn, column[currentColumn].getRow())

void dropping(int, int);
void charVerification(char &);
int toInt(char);

int main(){
    int playerOne = 1;
    int playerTwo = 2;
    bool noWinner;
    int winner;
    int currentColumn;
    int currentPlayer = 0;

    board *column = new board[numberOfColumns];
    initializeBoard(column);

    do{
        try{
            if(currentPlayer == 0)
                currentPlayer = 1;
            else if(currentPlayer == 1)
                currentPlayer = 2;
            else if(currentPlayer == 2)
                currentPlayer = 1;

            displayBoard(column);

            std::cout << "Player " << currentPlayer << ", it is your turn...\n";


            noWinner = false;
        }
        catch(int winner){
            std::cout << "DING DING DING WE HAVE A WINNER!\n";
            std::cout << "Winner: ";
            if(winner == 1)
                std::cout << "Player 1" << std::endl;
            else
                std::cout << "Player 2" << std::endl;

            noWinner = false;
        }
    }while(noWinner);

    std::cout << "Thanks for playing! " << std::endl;

    return 0;
}

void dropping(int col, int play){
    std::cout << "Dropping " << play << " into column " << col << std::endl;
}

int toInt(char choice){
    switch(choice){
        case 'A':
            return 0;
            break;
        case 'B':
            return 1;
            break;
        case 'C':
            return 2;
            break;
        case 'D':
            return 3;
            break;
        case 'E':
            return 4;
            break;
        case 'F':
            return 5;
            break;
        case 'G':
            return 6;
            break;
    }
}

void charVerification(char &ch){
    bool flag;
    do{
        flag = true;
        if(ch == 'A' || ch == 'B' || ch == 'C' || ch == 'D' || ch == 'E' || ch == 'F' || ch == 'G')
            flag = false;
        else{
            std::cout << "That is an invalid row... Try again: ";
            std::cin >> ch;
        }
    }while(flag);
    
}