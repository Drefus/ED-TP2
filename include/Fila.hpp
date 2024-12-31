#ifndef FILA_HPP
#define FILA_HPP
#include "Node.hpp"

class Fila
{
private:
    Node *head;
    Node *tail;
    int size;
    int id;

public:
    Fila(int id);
    ~Fila();

    void Insert(Paciente paciente);
    Paciente Remove();
    bool IsEmpty();
    void OrderByTime();
    Node *MergeSort(Node *head);
    Node *GetMiddle(Node *head);
    Node *SortedMerge(Node *left, Node *right);
    Node *GetHead();
    Node *GetTail();
};

#endif