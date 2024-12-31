#ifndef PROCEDIMENTO_HPP
#define PROCEDIMENTO_HPP
#include "Unidade.hpp"
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