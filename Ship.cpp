#include "Ship.hpp"
#include <iostream>
#include <string.h>

Ship::Ship(const char* shipName, int shipSize)
{
    if (shipName != NULL) {
        int len=strlen(shipName);
        this->name=new char[len+1];
        strcpy(this->name,shipName);
    } else {
        this->name = NULL;
    }
    this->size = shipSize;
    this->hitsTaken = 0;
}

Ship::~Ship()
{
    if (this->name != NULL) {
        delete[] this->name; 
    }
}

void Ship::takeHit()
{
    this->hitsTaken++;
    std::cout << name << " got hit!" << std::endl;
    if (this->hitsTaken >= this->size) {
        std::cout << name << " is sunk!" << std::endl;
    }
}

bool Ship::isSunk() const
{
    if (this->hitsTaken >= this->size)
        return true;
    return false;
}

Carrier::Carrier() : Ship("Carrier", 5){}

Battleship::Battleship() : Ship("Battleship", 4){}

Cruiser::Cruiser() : Ship("Cruiser", 3){}

Submarine::Submarine() : Ship("Submarine", 3){}

Destroyer::Destroyer() : Ship("Destroyer", 2){}
