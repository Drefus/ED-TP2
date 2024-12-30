#ifndef EVENTO_HPP
#define EVENTO_HPP
#include <string>
using namespace std;
class Evento
{
private:
    int filaId;
    string pacienteId;
    int year;
    int month;
    int day;
    double hour;
    double duracao;

public:
    Evento();
    Evento(int filaId, string pacienteId, int year, int month, int day, double hour, double duracao);
    ~Evento();

    int getFilaId();
    void setFilaId(int filaId);

    int getYear();
    void setYear(int year);

    int getMonth();
    void setMonth(int month);

    int getDay();
    void setDay(int day);

    double getHour();
    void setHour(double hour);

    double getDuracao();
    void setDuracao(double duracao);

    bool compareTime(Evento evento);
};
;

#endif