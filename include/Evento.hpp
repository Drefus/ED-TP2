#ifndef EVENTO_HPP
#define EVENTO_HPP

class Evento
{
private:
    int filaId;
    int tempo;
    int duracao;

public:
    Evento();
    Evento(int filaId, int tempo, int duracao);
    ~Evento();

    int getFilaId();
    int getTempo();
    int getDuracao();
    void setFilaId(int filaId);
    void setTempo(int tempo);
    void setDuracao(int duracao);
};
;

#endif