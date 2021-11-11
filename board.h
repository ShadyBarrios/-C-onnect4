#pragma once
#include <iostream>
#include <cctype>

static const int numberOfColumns = 7;
static const int numberOfSlots = 7;

class board;

void dropping(int, int);
void charVerification(char &);
int toInt(char);
bool verify(const int, const int, board *);
void initializeBoard(board *);
void initializeColumn(board &, const int);
void displayBoard(board *, int);
void startingRow(){std::cout << "-------------\nA B C D E F G" << std::endl;}

class board{
private:
    

    struct column{
        struct column *next; // points to next slot in column
        int value; // value of one slot
    };

    column *head;

public:

    board(){head = nullptr;}

    void insert(int value){
        column *nodePtr;
        column *previous;
        column *newSlot;

        newSlot = new column;
        newSlot->value = value;
        newSlot->next = nullptr;

        if(!head)
            head = newSlot;
        else{
            nodePtr = head;

            while(nodePtr){
                previous = nodePtr;
                nodePtr = nodePtr->next;
            }   

            nodePtr = newSlot;
            previous->next = newSlot;
        }
    }

    void displayColumn(){
        column *nodePtr;

        if(!head)
            std::cout << "List is empty\n";
        else{
            nodePtr = head;

            while(nodePtr){
                std::cout << nodePtr->value << std::endl;
                nodePtr = nodePtr->next;
            }
        }
    }

    void displayByPosition(int position){
        column *nodePtr;
        int current = 0; 

        if(!head)
            std::cout << "List is empty\n";
        else{
            nodePtr = head;

            for(int count = 0; count < position; count++)
                nodePtr = nodePtr->next;
            
            std::cout << nodePtr->value << " ";
        }
    }

    bool insertNewCoin(int player){
        bool retry;

        column *nodePtr;
        column *next;
        column *previous;
        column *newCoin;
        newCoin = new column;
        newCoin->value = player;
        newCoin->next = nullptr;

        if(!head)
            std::cout << "List is empty\n";
        else if(head->value == 0)
            head->value = player;
        else{ // error in here
            nodePtr = head->next;

            while(nodePtr && nodePtr->value != 0){ // skips loop
                previous = nodePtr;
                nodePtr = nodePtr->next;
            }
            
            if(!nodePtr){
                std::cout << "The column is full\n";
                return true;
            }
            else
                nodePtr->value = player;   
        } 
        return false;
    }

    int coinAtPosition(int row, int currentColumn){
        column *nodePtr;

        if(row < 0 || row > 6)
            return 0;

        if(currentColumn < 0 || currentColumn > 6)
            return 0;

        nodePtr = head;

        for(int count = 0; count < row; count++)
            nodePtr = nodePtr->next;
        
        return nodePtr->value;
    }
    
    // gets row of most recent coin
    int getRow(){
        int counter = -1; // starts at first column
        column *nodePtr;
        column *previous;

        nodePtr = head;

        while(nodePtr && nodePtr->value != 0){
            previous = nodePtr;
            nodePtr = nodePtr->next;

            if(nodePtr)
                counter++;
        }

        return counter;
    }
};

void initializeBoard(board *column){
    for(int count = 0; count < numberOfColumns; count++)
        initializeColumn(column[count], 0);
}

void initializeColumn(board &column, const int initializerValue){
    for(int count = 0; count < numberOfSlots; count++)
        column.insert(initializerValue);
}

void displayBoard(board *column){
    int row = (numberOfSlots - 1);

    for(row; row >= 0; row--){
        for(int index = 0; index < numberOfColumns; index++)
            column[index].displayByPosition(row);
        std::cout << std::endl;
    }
    startingRow();
    std::cout << std::endl;
}

// std::cout << column[referenceColumn - 2].coinAtPosition(referenceRow) << std::endl;

// only one possible win for vertical
bool verticalCheck(board *column, int referenceValue, int referenceColumn, int referenceRow){
    if(column[referenceColumn].coinAtPosition(referenceRow - 1,referenceColumn) == referenceValue && 
       column[referenceColumn].coinAtPosition(referenceRow - 2,referenceColumn) == referenceValue &&
       column[referenceColumn].coinAtPosition(referenceRow - 3,referenceColumn) == referenceValue)
        return true;
    else
        return false;
}

bool horizontalCheck1(board *column, int referenceValue, int referenceColumn, int referenceRow){
    if(column[referenceColumn + 1].coinAtPosition(referenceRow,(referenceColumn + 1)) == referenceValue && 
       column[referenceColumn + 2].coinAtPosition(referenceRow,(referenceColumn + 2)) == referenceValue &&
       column[referenceColumn + 3].coinAtPosition(referenceRow,(referenceColumn + 3)) == referenceValue)
        return true;
    else
        return false;
} 

bool horizontalCheck2(board *column, int referenceValue, int referenceColumn, int referenceRow){
    if(column[referenceColumn - 1].coinAtPosition(referenceRow,(referenceColumn - 1)) == referenceValue &&
       column[referenceColumn + 1].coinAtPosition(referenceRow,(referenceColumn + 1)) == referenceValue &&
       column[referenceColumn + 2].coinAtPosition(referenceRow,(referenceColumn + 2)) == referenceValue)
        return true;
    else
        return false;
} 

bool horizontalCheck3(board *column, int referenceValue, int referenceColumn, int referenceRow){
    if(column[referenceColumn - 2].coinAtPosition(referenceRow,(referenceColumn - 2)) == referenceValue &&
       column[referenceColumn - 1].coinAtPosition(referenceRow,(referenceColumn - 1)) == referenceValue &&
       column[referenceColumn + 1].coinAtPosition(referenceRow,(referenceColumn + 1)) == referenceValue)
        return true;
    else
        return false;
} 

bool horizontalCheck4(board *column, int referenceValue, int referenceColumn, int referenceRow){
    if(column[referenceColumn - 3].coinAtPosition(referenceRow,(referenceColumn - 3)) == referenceValue &&
       column[referenceColumn - 2].coinAtPosition(referenceRow,(referenceColumn - 2)) == referenceValue &&
       column[referenceColumn - 1].coinAtPosition(referenceRow,(referenceColumn - 1)) == referenceValue)
        return true;
    else
        return false;
} 

bool rDiagonalCheck1(board *column, int referenceValue, int referenceColumn, int referenceRow){
    if(column[referenceColumn + 1].coinAtPosition(referenceRow + 1,(referenceColumn + 1)) == referenceValue &&
       column[referenceColumn + 2].coinAtPosition(referenceRow + 2,(referenceColumn + 2)) == referenceValue &&
       column[referenceColumn + 3].coinAtPosition(referenceRow + 3,(referenceColumn + 3)) == referenceValue)
        return true;
    else
        return false;
} 

bool rDiagonalCheck2(board *column, int referenceValue, int referenceColumn, int referenceRow){
    if(column[referenceColumn - 1].coinAtPosition(referenceRow - 1,(referenceColumn - 1)) == referenceValue &&
       column[referenceColumn + 1].coinAtPosition(referenceRow + 1,(referenceColumn + 1)) == referenceValue &&
       column[referenceColumn + 2].coinAtPosition(referenceRow + 2,(referenceColumn + 2)) == referenceValue)
        return true;
    else
        return false;
} 

bool rDiagonalCheck3(board *column, int referenceValue, int referenceColumn, int referenceRow){
    if(column[referenceColumn - 2].coinAtPosition(referenceRow - 2,(referenceColumn - 2)) == referenceValue &&
       column[referenceColumn - 1].coinAtPosition(referenceRow - 1,(referenceColumn - 1)) == referenceValue &&
       column[referenceColumn + 1].coinAtPosition(referenceRow + 1,(referenceColumn + 1)) == referenceValue)
        return true;
    else
        return false;
} 

bool rDiagonalCheck4(board *column, int referenceValue, int referenceColumn, int referenceRow){
    if(column[referenceColumn - 3].coinAtPosition(referenceRow - 3,(referenceColumn - 3)) == referenceValue &&
       column[referenceColumn - 2].coinAtPosition(referenceRow - 2,(referenceColumn - 2)) == referenceValue &&
       column[referenceColumn - 1].coinAtPosition(referenceRow - 1,(referenceColumn - 1)) == referenceValue)
        return true;
    else
        return false;
} 

bool lDiagonalCheck1(board *column, int referenceValue, int referenceColumn, int referenceRow){
    if(column[referenceColumn - 3].coinAtPosition(referenceRow + 3,(referenceColumn - 3)) == referenceValue &&
       column[referenceColumn - 2].coinAtPosition(referenceRow + 2,(referenceColumn - 2)) == referenceValue &&
       column[referenceColumn - 1].coinAtPosition(referenceRow + 1,(referenceColumn - 1)) == referenceValue)
        return true;
    else
        return false;
} 

bool lDiagonalCheck2(board *column, int referenceValue, int referenceColumn, int referenceRow){
    if(column[referenceColumn - 2].coinAtPosition(referenceRow + 2,(referenceColumn - 2)) == referenceValue &&
       column[referenceColumn - 1].coinAtPosition(referenceRow + 1,(referenceColumn - 1)) == referenceValue &&
       column[referenceColumn + 1].coinAtPosition(referenceRow - 1,(referenceColumn + 1)) == referenceValue)
        return true;
    else
        return false;
} 

bool lDiagonalCheck3(board *column, int referenceValue, int referenceColumn, int referenceRow){
    if(column[referenceColumn - 1].coinAtPosition(referenceRow + 1,(referenceColumn - 1)) == referenceValue &&
       column[referenceColumn + 1].coinAtPosition(referenceRow - 1,(referenceColumn + 1)) == referenceValue &&
       column[referenceColumn + 2].coinAtPosition(referenceRow - 2,(referenceColumn + 2)) == referenceValue)
        return true;
    else
        return false;
} 

bool lDiagonalCheck4(board *column, int referenceValue, int referenceColumn, int referenceRow){
    if(column[referenceColumn + 1].coinAtPosition(referenceRow - 1,(referenceColumn + 1)) == referenceValue &&
       column[referenceColumn + 2].coinAtPosition(referenceRow - 2,(referenceColumn + 2)) == referenceValue &&
       column[referenceColumn + 3].coinAtPosition(referenceRow - 3,(referenceColumn + 3)) == referenceValue)
        return true;
    else
        return false;
} 

void dropping(int col, int play){
    std::cout << "Dropping " << play << " into column " << col << std::endl;
}

int toInt(char choice){
    // No need for breaks as return exits function
    switch(choice){
        case 'A': return 0;
        case 'B': return 1;
        case 'C': return 2;
        case 'D': return 3;
        case 'E': return 4;
        case 'F': return 5;
        case 'G': return 6;
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
            ch = toupper(ch);
        }
    }while(flag);
    
}

bool verify(const int referenceRow, const int referenceColumn, board *columnPtr){
    if(verticalCheck(columnPtr, columnPtr[referenceColumn].coinAtPosition(referenceRow, referenceColumn), referenceColumn, referenceRow))
        return true;
    else if(horizontalCheck1(columnPtr, columnPtr[referenceColumn].coinAtPosition(referenceRow, referenceColumn), referenceColumn, referenceRow))
        return true;
    else if(horizontalCheck2(columnPtr, columnPtr[referenceColumn].coinAtPosition(referenceRow, referenceColumn), referenceColumn, referenceRow))
        return true;
    else if(horizontalCheck3(columnPtr, columnPtr[referenceColumn].coinAtPosition(referenceRow, referenceColumn), referenceColumn, referenceRow))
        return true;
    else if(horizontalCheck4(columnPtr, columnPtr[referenceColumn].coinAtPosition(referenceRow, referenceColumn), referenceColumn, referenceRow))
        return true;
    else if(rDiagonalCheck1(columnPtr, columnPtr[referenceColumn].coinAtPosition(referenceRow, referenceColumn), referenceColumn, referenceRow))
        return true;
    else if(rDiagonalCheck2(columnPtr, columnPtr[referenceColumn].coinAtPosition(referenceRow, referenceColumn), referenceColumn, referenceRow))
        return true;
    else if(rDiagonalCheck3(columnPtr, columnPtr[referenceColumn].coinAtPosition(referenceRow, referenceColumn), referenceColumn, referenceRow))
        return true;
    else if(rDiagonalCheck4(columnPtr, columnPtr[referenceColumn].coinAtPosition(referenceRow, referenceColumn), referenceColumn, referenceRow))
        return true;
    else if(lDiagonalCheck1(columnPtr, columnPtr[referenceColumn].coinAtPosition(referenceRow, referenceColumn), referenceColumn, referenceRow))
        return true;
    else if(lDiagonalCheck2(columnPtr, columnPtr[referenceColumn].coinAtPosition(referenceRow, referenceColumn), referenceColumn, referenceRow))
        return true;
    else if(lDiagonalCheck3(columnPtr, columnPtr[referenceColumn].coinAtPosition(referenceRow, referenceColumn), referenceColumn, referenceRow))
        return true;
    else if(lDiagonalCheck4(columnPtr, columnPtr[referenceColumn].coinAtPosition(referenceRow, referenceColumn), referenceColumn, referenceRow))
        return true;

    return false;
}
