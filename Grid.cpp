#include "Grid.hpp"
#include <iostream>

Grid::Grid()
{
    for(int i=0 ; i<10; i++)
    {
        for(int j=0 ; j<10; j++)
        {
            cells[i][j] = '~' ;
        }
    }
}

bool Grid::isTileOccupied(int row, int col, int shipSize, bool horizontal) const
{
    for (int i = 0; i < shipSize; i++) {
        int currentRow = horizontal ? row : row + i;
        int currentCol = horizontal ? col + i : col;

        if (cells[currentRow][currentCol] != '~') 
        {
            return true; 
        }
    }
    return false;
}

bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const
{
    if (row < 0 || row >= 10 || col < 0 || col >= 10) 
        return false;
    if (horizontal) { 
        if (col + shipSize > 10) 
            return false;
    }
    else { 
        if (row + shipSize > 10) 
            return false;
    } 
    return true;
}

void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol)
{
    if (horizontal) {
        for (int i = 0; i < shipSize; i++) 
            cells[row][col + i] = symbol; 
    } else {
        for (int i = 0; i < shipSize; i++)
            cells[row + i][col] = symbol;
    }
}

void Grid::markHit(int row, int col)
{
    cells[row][col] = 'X';
}

void Grid::markMiss(int row, int col)
{
    cells[row][col] = 'M';
}

char Grid::getCell(int row, int col) const
{
    if (row < 0 || row >= 10 || col < 0 || col >= 10) 
        return '?'; 
    return cells[row][col];
}

void Grid::printGrid(bool showShips)
{
    std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << i << " "; 
        for (int j = 0; j < 10; j++) {
            char cell = getCell(i,j); 
            bool isShip = (cell != '~' && cell != 'X' && cell != 'M');
            if (!showShips && isShip) {
                std::cout << "~ ";
            } 
            else {
                std::cout << cell << " ";
            }
        }
        std::cout << std::endl;
    }
}