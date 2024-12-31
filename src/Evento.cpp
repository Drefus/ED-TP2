#include "Evento.hpp"

Evento::Evento() : filaId(0), time(0, 0, 0, 0), duracao(0.0) {}

Evento::Evento(int filaId, string pacienteId, Time time, double duracao)
    : filaId(filaId), pacienteId(pacienteId), time(time), duracao(duracao) {}

Evento::~Evento() {}

int Evento::getFilaId()
{
    return filaId;
}

void Evento::setFilaId(int filaId)
{
    this->filaId = filaId;
}

double Evento::getDuracao()
{
    return duracao;
}

void Evento::setDuracao(double duracao)
{
    this->duracao = duracao;
}

string Evento::getPacienteId()
{
    return pacienteId;
}

void Evento::setPacienteId(string pacienteId)
{
    this->pacienteId = pacienteId;
}

Time Evento::getTime()
{
    return time;
}

void Evento::setTime(Time time)
{
    getTime().setYear(time.getYear());
    getTime().setMonth(time.getMonth());
    getTime().setDay(time.getDay());
    getTime().setHour(time.getHour());
}
