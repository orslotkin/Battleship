#include "Game.hpp"
#include <iostream>
using namespace std;

Game:: Game(Player* p1, Player* p2): player1(p1), player2(p2) {}
void Game:: setup()
{
    cout<< " player 1 setup" << endl;
    player1->placeAllShips();
    cout<< "\n player 2 setup" << endl;
    player2->placeAllShips();
}
void Game:: start()
{
    cout<< "\n Starting Battleship Game" << endl;
    while(!isGameOver())
    {
        player1->makeMove(player2);
        if(player2->allShipsSunk())
        {
            cout << "\n CONGRATULATIONS! " << player1->getName() << " WINS!" << endl;
            break;
        }
        player2->makeMove(player1);
        if(player1->allShipsSunk())
        {
            cout << "\n CONGRATULATIONS! " << player2->getName() << " WINS!" << endl;
            break;
        }
    }
    cout << "Game Over" << endl;
}
bool Game:: isGameOver() const
{
    return player1->allShipsSunk() || player2->allShipsSunk();
}