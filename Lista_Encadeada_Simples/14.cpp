#include <iostream>
using namespace std;

// Definição da classe Node
class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

// Definição da classe LinkedList
class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    // Função para inserir um novo elemento de forma ordenada
    void insertOrdered(int value)
    {
        Node *newNode = new Node(value);

        // Caso especial: inserção no início ou lista vazia
        if (head == nullptr || head->data >= value)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Encontrar a posição correta para inserção
        Node *current = head;
        while (current->next != nullptr && current->next->data < value)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Função para imprimir a lista
    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    LinkedList list;
    // Inserindo elementos de forma ordenada
    list.insertOrdered(10);
    list.insertOrdered(5);
    list.insertOrdered(20);
    list.insertOrdered(15);
    list.insertOrdered(1);

    // Imprimindo a lista ordenada
    list.printList(); // Saída: 1 -> 5 -> 10 -> 15 -> 20 -> nullptr

    return 0;
}
