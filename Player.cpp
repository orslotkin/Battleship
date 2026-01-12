#include "Player.hpp"
#include <iostream>
#include <string.h>

Player::Player(const char* name)
{
    if (name != NULL) {
        int len=strlen(name);
        this->playerName=new char[len+1];
        strcpy(this->playerName,name);
    } else {
        this->playerName = NULL;
    }
    this->ships[0] = new Carrier();
    this->ships[1] = new Battleship();
    this->ships[2] = new Cruiser();
    this->ships[3] = new Submarine();
    this->ships[4] = new Destroyer();
}

Player::~Player()
{
    if (this->playerName != NULL) {
        delete[] this->playerName;
    }
    for (int i = 0; i < 5; i++) {
        if (ships[i]) 
            delete ships[i];
    }
}

bool Player::allShipsSunk() const
{
    for (int i = 0; i < 5; i++) {
        if (ships[i]->isSunk() == false) 
            return false;
    }
    return true;
}

void Player::displayGrid(bool showShips)
{
    grid.printGrid(showShips);
}