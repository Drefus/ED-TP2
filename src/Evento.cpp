#include "Evento.hpp"

Evento::Evento() : filaId(0), year(0), month(0), day(0), hour(0.0), duracao(0.0) {}

Evento::Evento(int filaId, string pacienteId, int year, int month, int day, double hour, double duracao)
    : filaId(filaId), pacienteId(pacienteId), year(year), month(month), day(day), hour(hour), duracao(duracao) {}

Evento::~Evento() {}

int Evento::getFilaId()
{
    return filaId;
}

void Evento::setFilaId(int filaId)
{
    this->filaId = filaId;
}

int Evento::getYear()
{
    return year;
}

void Evento::setYear(int year)
{
    this->year = year;
}

int Evento::getMonth()
{
    return month;
}

void Evento::setMonth(int month)
{
    this->month = month;
}

int Evento::getDay()
{
    return day;
}

void Evento::setDay(int day)
{
    this->day = day;
}

double Evento::getHour()
{
    return hour;
}

void Evento::setHour(double hour)
{
    this->hour = hour;
}

double Evento::getDuracao()
{
    return duracao;
}

void Evento::setDuracao(double duracao)
{
    this->duracao = duracao;
}

bool Evento::compareTime(Evento evento)
{
    if (this->year < evento.getYear())
    {
        return false;
    }
    else if (this->year > evento.getYear())
    {
        return true;
    }
    else
    {
        if (this->month < evento.getMonth())
        {
            return false;
        }
        else if (this->month > evento.getMonth())
        {
            return true;
        }
        else
        {
            if (this->day < evento.getDay())
            {
                return false;
            }
            else if (this->day > evento.getDay())
            {
                return true;
            }
            else
            {
                if (this->hour < evento.getHour())
                {
                    return false;
                }
                else if (this->hour > evento.getHour())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
}
