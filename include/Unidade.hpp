#ifndef UNIDADE_HPP
#define UNIDADE_HPP
#include "Time.hpp"
#include "Service.hpp"

class Unidade
{
private:
    Service *services;
    bool isOccupied;

public:
    Unidade(/* args */);
    ~Unidade();
    void addService(Time initialTime, Time finalTime, bool isOccupied);
    bool getIsOccupied();
    void setIsOccupied(bool isOccupied);
};

#endif
