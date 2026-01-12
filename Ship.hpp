#pragma once

class Ship {
    
    protected:
        char* name;
        int size;
        int hitsTaken;

    public:
        Ship(const char* shipName, int shipSize);
        virtual ~Ship(); 
        int getSize() const { return size; }
        virtual void takeHit();
        bool isSunk() const;
        char getSimble() const;
};

class Carrier : public Ship {
public:
    Carrier();
};

class Battleship : public Ship {
public:
    Battleship();
};

class Cruiser : public Ship {
public:
    Cruiser();
};

class Submarine : public Ship {
public:
    Submarine();
};

class Destroyer : public Ship {
public:
    Destroyer();
};
