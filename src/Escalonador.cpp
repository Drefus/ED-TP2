#include "Escalonador.hpp"

void Escalonador::Insert(Evento event)
{
    data[tam] = event;
    tam++;
    HeapifyPorCima(tam - 1);
}

Evento Escalonador::Remove()
{
    Evento menorNumero = data[0];
    data[0] = data[tam - 1];
    tam--;
    HeapifyPorBaixo(0);
    return menorNumero;
}

bool Escalonador::IsEmpty()
{
    if (tam > 0)
    {
        return false;
    }
    return true;
}

int Escalonador::GetAncestral(int posicao)
{
    return (posicao - 1) / 2;
}

int Escalonador::GetSucessorEsq(int posicao)
{
    return 2 * posicao + 1;
}

int Escalonador::GetSucessorDir(int posicao)
{
    return 2 * posicao + 2;
}

void Escalonador::HeapifyPorBaixo(int posicao)
{
    int sucessorEsq = GetSucessorEsq(posicao);
    int sucessorDir = GetSucessorDir(posicao);
    int menor = posicao;
    if (sucessorEsq < tam && data[sucessorEsq].getTempo() < data[posicao].getTempo())
    {
        menor = sucessorEsq;
    }
    if (sucessorDir < tam && data[sucessorDir].getTempo() < data[menor].getTempo())
    {
        menor = sucessorDir;
    }
    if (menor != posicao)
    {
        Evento temp = data[posicao];
        data[posicao] = data[menor];
        data[menor] = temp;
        HeapifyPorBaixo(menor);
    }
}

void Escalonador::HeapifyPorCima(int posicao)
{
    int ancestral = GetAncestral(posicao);
    if (data[ancestral].getTempo() > data[posicao].getTempo())
    {
        Evento temp = data[posicao];
        data[posicao] = data[ancestral];
        data[ancestral] = temp;
        HeapifyPorCima(ancestral);
    }
}

Escalonador::Escalonador(int maxsize)
{
    this->data = new Evento[maxsize];
    this->tam = 0;
}

Escalonador::~Escalonador()
{
}
