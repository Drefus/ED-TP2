#ifndef PROCEDIMENTO_HPP
#define PROCEDIMENTO_HPP

#include "Time.hpp"

// Service class definition
class Service
{
private:
    Time initialTime;
    Time finalTime;
    bool isOccupied;
    Service *next;

public:
    Service();
    Service(Time initialTime, Time finalTime, bool isOccupied);
    ~Service();

    Time getInitialTime();
    void setInitialTime(Time initialTime);
    Time getFinalTime();
    void setFinalTime(Time finalTime);
    bool getIsOccupied();
    void setIsOccupied(bool isOccupied);
    Service *getNext();
    void setNext(Service *next);
};

// Unidade class definition
class Unidade
{
private:
    Service *services;
    bool isOccupied;

public:
    Unidade();
    ~Unidade();

    void addService(Time initialTime, Time finalTime, bool isOccupied);
    bool getIsOccupied();
    void setIsOccupied(bool isOccupied);
};

// Procedimento class definition
class Procedimento
{
private:
    int numMax;
    int numAtual;
    double duracao;
    Unidade *unidades;

public:
    Procedimento();
    Procedimento(int numMax, double duracao);
    ~Procedimento();

    int emptyUnit();
    void addService(Time initialTime, double duracao, int numUnit);
    double getDuration();
    void setDuration(double duracao);
};

#endif