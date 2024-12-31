#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP
#include "Evento.hpp"
class Escalonador
{
private:
    int tam;
    int maxsize;
    Evento *data;

public:
    Escalonador(int maxsize);
    Escalonador();
    ~Escalonador();
    Evento RemoveById(string id);
    Evento GetById(string id);
    void Insert(Evento event);
    Evento Remove();
    bool IsEmpty();
    int GetAncestral(int posicao);
    int GetSucessorEsq(int posicao);
    int GetSucessorDir(int posicao);
    void HeapifyPorBaixo(int posicao);
    void HeapifyPorCima(int posicao);
};

#endif