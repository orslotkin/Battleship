#pragma once
#include "Player.hpp"

class HumanPlayer : public Player{
public:
    HumanPlayer(const char* name);
    void placeAllShips();
    void makeMove(Player* opponent);
};