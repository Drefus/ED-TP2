#include "Procedimento.hpp"

// Service class implementation
Service::Service() : initialTime(), finalTime(), isOccupied(false), next(nullptr) {}

Service::Service(Time initialTime, Time finalTime, bool isOccupied)
    : initialTime(initialTime), finalTime(finalTime), isOccupied(isOccupied), next(nullptr) {}

Service::~Service()
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

// Unidade class implementation
Unidade::Unidade() : services(nullptr), isOccupied(false) {}

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
    newService->setNext(services);
    services = newService;
}

bool Unidade::getIsOccupied()
{
    return isOccupied;
}

void Unidade::setIsOccupied(bool isOccupied)
{
    this->isOccupied = isOccupied;
}

// Procedimento class implementation
Procedimento::Procedimento() : numMax(0), numAtual(0), duracao(0.0), unidades(nullptr) {}

Procedimento::Procedimento(int numMax, double duracao)
    : numMax(numMax), numAtual(0), duracao(duracao), unidades(new Unidade[numMax]) {}

Procedimento::~Procedimento()
{
    if (unidades != nullptr)
    {
        for (int i = 0; i < numMax; ++i)
        {
            unidades[i].~Unidade();
        }
        delete[] unidades;
    }
}

int Procedimento::emptyUnit()
{
    for (int i = 0; i < numMax; ++i)
    {
        if (!unidades[i].getIsOccupied())
        {
            return i;
        }
    }
    return -1; // No empty unit found
}

void Procedimento::addService(Time initialTime, double duracao, int numUnit)
{
    if (numUnit >= 0 && numUnit < numMax)
    {
        unidades[numUnit].addService(initialTime, Time(initialTime.getYear(), initialTime.getMonth(), initialTime.getDay(), initialTime.getHour() + duracao), true);
    }
}

double Procedimento::getDuration()
{
    return duracao;
}

void Procedimento::setDuration(double duracao)
{
    this->duracao = duracao;
}