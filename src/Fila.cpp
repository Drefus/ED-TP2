#include "Fila.hpp"

Fila::Fila(int id) : head(nullptr), tail(nullptr), size(0)
{
    this->id = id;
}

Fila::~Fila()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}

void Fila::Insert(Paciente paciente)
{
    Node *newNode = new Node(paciente);
    if (IsEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        Node *current = head;
        Node *previous = nullptr;
        while (current != nullptr && current->data.getPriority() >= paciente.getPriority())
        {
            previous = current;
            current = current->next;
        }
        if (previous == nullptr)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = current;
            previous->next = newNode;
            if (current == nullptr)
            {
                tail = newNode;
            }
        }
    }
    size++;
}

Paciente Fila::Remove()
{
    if (IsEmpty())
    {
        throw "Fila vazia";
    }
    Node *temp = head;
    Paciente paciente = temp->data;
    head = head->next;
    delete temp;
    size--;
    return paciente;
}

bool Fila::IsEmpty()
{
    return size == 0;
}

void Fila::OrderByTime()
{
    Node *current = head;
    Node *previous = nullptr;
    while (current != nullptr)
    {
        Node *next = current->next;
        while (next != nullptr)
        {
            if (current->data.getTimeOfService() > next->data.getTimeOfService())
            {
                if (previous == nullptr)
                {
                    head = next;
                }
                else
                {
                    previous->next = next;
                }
                current->next = next->next;
                next->next = current;
                Node *temp = current;
                current = next;
                next = temp;
            }
            previous = current;
            current = current->next;
            next = next->next;
        }
    }
    tail = current;
    current = head;
    while (current != nullptr)
    {
        tail = current;
        current = current->next;
    }
}
