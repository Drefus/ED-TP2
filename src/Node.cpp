#include "Node.hpp"

Node::Node(Paciente paciente) : data(paciente), next(nullptr)
{
}

Node::~Node()
{
}

Node::Node() : next(nullptr)
{
}
