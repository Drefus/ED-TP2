#include "Unidade.hpp"

Unidade::Unidade() : isOccupied(false), services(nullptr)
{
}

Unidade::~Unidade()
{
    Service *current = services;
    while (current != nullptr)
    {
        Service *temp = current;
        current = current->getNext();
        delete temp;
    }
}

void Unidade::addService(Time initialTime, Time finalTime, bool isOccupied)
{
    Service *newService = new Service(initialTime, finalTime, isOccupied);
    newService->setNext(nullptr);

    if (services == nullptr)
    {
        services = newService;
    }
    else
    {
        Service *current = services;
        while (current->getNext() != nullptr)
        {
            current = current->getNext();
        }
        current->setNext(newService);
    }
}

bool Unidade::getIsOccupied()
{
    return isOccupied;
}

void Unidade::setIsOccupied(bool isOccupied)
{
    this->isOccupied = isOccupied;
}
