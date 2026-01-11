#pragma once
#include "Player.hpp"

class AiPlayer : public Player{
public:
    AiPlayer(const char* name);
    void placeAllShips();
    void makeMove(Player* opponent);
private:
    int getRandomCoordinate();
};