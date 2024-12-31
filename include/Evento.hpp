#ifndef EVENTO_HPP
#define EVENTO_HPP
#include <string>
using namespace std;
#include "Time.hpp"
class Evento
{
private:
    int filaId;
    string pacienteId;
    Time time;
    double duracao;

public:
    Evento();
    Evento(int filaId, string pacienteId, Time time, double duracao);
    ~Evento();

    int getFilaId();
    void setFilaId(int filaId);

    Time getTime();
    void setTime(Time time);

    double getDuracao();
    void setDuracao(double duracao);
};
;

#endif