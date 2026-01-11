#pragma once
#include "Ship.hpp"
#include "Grid.hpp"

class Player
{
    protected:
        char* playerName;
        Ship* ships[5]; 
        Grid grid;
    public:
        Player(const char* name);
        virtual ~Player();
        virtual void placeAllShips() = 0;
        virtual void makeMove(Player* opponent) = 0;
        bool allShipsSunk() const;
        void displayGrid();
        Grid& getGrid() { return grid; }
        const char* getName() const { return playerName; }
};