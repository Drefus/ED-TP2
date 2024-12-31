#include "Procedimento.hpp"

Procedimento::Procedimento()
{
}

Procedimento::Procedimento(int numMax, double duracao)
{
    this->numMax = numMax;
    this->duracao = duracao;
    this->numAtual = 0;
    this->unidades = new Unidade[numMax];
}

Procedimento::~Procedimento()
{
}

int Procedimento::emptyUnit()
{
    for (int i = 0; i < numMax; i++)
    {
        if (!unidades[i].getIsOccupied())
        {
            return i;
        }
    }
    return -1;
}

void Procedimento::addService(Time initialTime, double duracao, int numUnit)
{
    Time finalTime = initialTime;
    finalTime.addTime(duracao);
    unidades[numUnit].addService(initialTime, finalTime, true);
    numAtual++;
}

double Procedimento::getDuration()
{
    return duracao;
}

void Procedimento::setDuration(double duracao)
{
    this->duracao = duracao;
}
