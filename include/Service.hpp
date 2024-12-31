#ifndef SERVICE_HPP
#define SERVICE_HPP
#include "Time.hpp"
class Service
{
private:
    Time initialTime;
    Time finalTime;
    bool isOccupied;
    Service *next;

public:
    Service(/* args */);
    ~Service();
    Service(Time initialTime, Time finalTime, bool isOccupied);
    Time getInitialTime();
    void setInitialTime(Time initialTime);
    Time getFinalTime();
    void setFinalTime(Time finalTime);
    bool getIsOccupied();
    void setIsOccupied(bool isOccupied);
    Service *getNext();
    void setNext(Service *next);
};

#endif
