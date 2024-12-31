#include "Service.hpp"

Service::Service() : initialTime(Time(0, 0, 0, 0)), finalTime(Time(0, 0, 0, 0)), isOccupied(false)
{
}

Service::~Service()
{
}

Service::Service(Time initialTime, Time finalTime, bool isOccupied) : initialTime(initialTime), finalTime(finalTime), isOccupied(isOccupied)
{
}

Time Service::getInitialTime()
{
    return initialTime;
}

void Service::setInitialTime(Time initialTime)
{
    this->initialTime = initialTime;
}

Time Service::getFinalTime()
{
    return finalTime;
}

void Service::setFinalTime(Time finalTime)
{
    this->finalTime = finalTime;
}

bool Service::getIsOccupied()
{
    return isOccupied;
}

void Service::setIsOccupied(bool isOccupied)
{
    this->isOccupied = isOccupied;
}

Service *Service::getNext()
{
    return next;
}

void Service::setNext(Service *next)
{
    this->next = next;
}
