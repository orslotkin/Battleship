#include "HumanPlayer.hpp"
#include <iostream>

using namespace std;

HumanPlayer:: HumanPlayer(const char* name) :Player(name) {}
void HumanPlayer:: placeAllShips()
{
    int row, col;
    char orientation;
    for(int i=0; i<5; i++)
    {
        bool placed=false;
        while(!placed)
        {
            displayGrid();
            cout << " Placing ship" << i+1 << " (Size: " << ships[i]->getSize() <<")" <<endl;
            cout << " Enter row (0-9), col (0-9) and orientation (H/V): ";
            if (!(cin >> row >> col >> orientation)) {
                cout << " Invalid input type! Please enter numbers for row and col." << endl;
                cin.clear();            
                cin.ignore(10000, '\n'); 
                continue;              
            }
            bool isHorizontal = (orientation == 'H' || orientation == 'h');

            if (grid.inBounds(row, col, ships[i]->getSize(), isHorizontal) && !grid.isTileOccupied(row, col, ships[i]->getSize(), isHorizontal))
            {
                grid.placeShip(row, col, ships[i]->getSize(), isHorizontal, 'S');
                placed=true;
                cout << " Ship placed successfully" << endl;
            } else {
                cout << " Invalid position! The ship might be out of bounds or overlapping. Try again." << endl;
            }
        }
    }
}
void HumanPlayer:: makeMove(Player* opponent)
{
    int row, col;
    bool moveFinished=false;
    while(!moveFinished)
    {
        cout << " Enter coordinates to attack- row (0-9) and col (0-9) ";
        cin >> row>> col;
        if(row < 0 || row >= 10 || col < 0 || col >= 10)
        {
            cout << "Invalid coordinates! Try again." << endl; 
            continue;
        }
        char targetCell=opponent->getGrid().getCell(row, col);
        if(targetCell== 'X' || targetCell=='M') cout << " You already attacked this spot. Try somewhere else!" << endl;
        else if(targetCell=='S')
        { 
            cout << " HIT!" << endl;
            Ship* hitShip = opponent->getGrid().getShipAt(row, col);
            if(!hitShip)
            {
            hitShip->takeHit();
            opponent->getGrid().markHit(row, col);
            moveFinished= true;
            }
        } 
        else{
            cout << " MISS!" << endl;
            opponent->getGrid().markMiss(row, col);
            moveFinished = true;
        }
    }
    displayGrid();
}