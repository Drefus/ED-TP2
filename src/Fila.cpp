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

Fila::Fila() : head(nullptr), tail(nullptr), size(0)
{
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

// Este método ordena a fila com base no horário de chegada dos pacientes.
// Se dois pacientes tiverem o mesmo horário de chegada, ele os ordena com base na prioridade.
// O paciente com o horário de chegada mais cedo ou maior prioridade vem primeiro.
void Fila::OrderByTime()
{
    if (IsEmpty())
    {
        return;
    }
    head = MergeSort(head);
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    tail = current;
}

Node *Fila::MergeSort(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node *middle = GetMiddle(head);
    Node *nextOfMiddle = middle->next;
    middle->next = nullptr;

    Node *left = MergeSort(head);
    Node *right = MergeSort(nextOfMiddle);

    return SortedMerge(left, right);
}

Node *Fila::GetMiddle(Node *head)
{
    if (!head)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

Node *Fila::SortedMerge(Node *left, Node *right)
{
    if (!left)
    {
        return right;
    }
    if (!right)
    {
        return left;
    }

    Node *result = nullptr;
    if (left->data.getCurrentTime().compareTime(right->data.getCurrentTime()) == true ||
        (left->data.getCurrentTime().isEqual(right->data.getCurrentTime()) == true && left->data.getPriority() >= right->data.getPriority()))
    {
        result = left;
        result->next = SortedMerge(left->next, right);
    }
    else
    {
        result = right;
        result->next = SortedMerge(left, right->next);
    }
    return result;
}

Node *Fila::GetHead()
{
    return head;
}

Node *Fila::GetTail()
{
    return tail;
}
