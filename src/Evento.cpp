#include "Evento.hpp"

Evento::Evento(int filaId, int tempo, int duracao) : filaId(filaId), tempo(tempo), duracao(duracao)
{
}

Evento::Evento()
{
}

Evento::~Evento()
{
}

int Evento::getFilaId()
{
    return filaId;
}

int Evento::getTempo()
{
    return tempo;
}

int Evento::getDuracao()
{
    return duracao;
}

void Evento::setFilaId(int filaId)
{
    this->filaId = filaId;
}

void Evento::setTempo(int tempo)
{
    this->tempo = tempo;
}

void Evento::setDuracao(int duracao)
{
    this->duracao = duracao;
}
