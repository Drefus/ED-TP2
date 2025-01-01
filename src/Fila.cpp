#include "Fila.hpp"

Fila::Fila(int id) : head(nullptr), tail(nullptr), size(0), id(id) {}

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

Fila::Fila() : head(nullptr), tail(nullptr), size(0), id(0) {}

void Fila::Insert(Paciente paciente)
{
    Node *newNode = new Node(paciente);
    if (IsEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

Paciente Fila::Remove()
{
    if (IsEmpty())
    {
        throw "Fila is empty";
    }
    Node *temp = head;
    Paciente paciente = head->data;
    head = head->next;
    if (head == nullptr)
    {
        tail = nullptr;
    }
    delete temp;
    size--;
    return paciente;
}

bool Fila::IsEmpty()
{
    return head == nullptr;
}

void Fila::OrderByTime()
{
    if (size > 1)
    {
        head = MergeSort(head);
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        tail = current;
    }
}

Node *Fila::MergeSort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
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
    if (head == nullptr)
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
    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }
    Node *result = nullptr;
    if (left->data.getCurrentTime().compareTime(right->data.getCurrentTime()))
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