
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

    // Função para inserir um novo elemento no início da lista
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Função para remover o primeiro nó que contém um valor específico
    void removeByValue(int value)
    {
        if (head == nullptr)
            return; // Lista vazia

        if (head->data == value)
        { // O valor está no primeiro nó
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *current = head;
        while (current->next != nullptr && current->next->data != value)
        {
            current = current->next;
        }

        if (current->next != nullptr)
        { // Encontrou o valor
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Função para imprimir a lista
    void printList()
    {
        Node *temp = head;

        cout << endl;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    // Inserindo no inicio
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.insertAtBeginning(5);
    list.printList(); // Saída: 5 -> 30 -> 20 ->10

    // Removendo o nó com valor 20
    list.removeByValue(20);
    list.printList(); // Saída: 5 -> 30 -> 10 -> nullptr
    return 0;
}
