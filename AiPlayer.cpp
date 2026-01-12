#include "AiPlayer.hpp"
#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

AiPlayer::AiPlayer(const char* name) : Player(name) {}

int AiPlayer::getRandomCoordinate()     
{   
      return std::rand() % 10;
}
void AiPlayer:: placeAllShips()
{
    for(int i=0; i<5; i++)
    {
        bool placed=false;
        while(!placed)
        {
            int row = getRandomCoordinate();
            int col = getRandomCoordinate();
            bool isHorizontal = (std::rand() % 2 == 0);

            if (grid.inBounds(row, col, ships[i]->getSize(), isHorizontal) && !grid.isTileOccupied(row, col, ships[i]->getSize(), isHorizontal))
            {
                grid.placeShip(row, col, ships[i]->getSize(), isHorizontal, ships[i]->getSimble());
                placed=true;
            } 
        }
    }
    cout << playerName << " has finished placing ships." << endl;
}
void AiPlayer ::makeMove(Player* opponent)
{
    int row, col;
    bool moveFinished = false;
    while(!moveFinished)
    {
        row = getRandomCoordinate();
        col = getRandomCoordinate();
        char targetCell = opponent->getGrid().getCell(row, col);
        if(targetCell == 'X' || targetCell == 'M') continue;
        cout << playerName << " attacks coordinates (" << row << ", " << col << "): ";
        if(targetCell != '~')
        { 
            cout << "HIT!" << endl;
            for(int i = 0; i < 5; i++) 
            {
                if(opponent->getShip(i)->getSimble() == targetCell){
                    opponent->getShip(i)->takeHit();
                    break;
                }
            }
            opponent->getGrid().markHit(row, col);
            moveFinished = true;
        } 
        else {
            cout << "MISS!" << endl;
            opponent->getGrid().markMiss(row, col);
            moveFinished = true;
        }
    }
    displayGrid(false);
}