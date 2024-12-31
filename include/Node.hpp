#ifndef NODE_HPP
#define NODE_HPP
#include "Paciente.hpp"
class Node
{
public:
    Paciente data;
    Node *next;
    Node(Paciente paciente);
    ~Node();
    Node();
};
#endif