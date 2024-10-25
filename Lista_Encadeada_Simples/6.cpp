
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

    // Função para remover o último elemento da lista
    void removeLast()
    {
        // Lista vazia
        if (head == nullptr)
        {
            return;
        }

        // Apenas um elemento na lista
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        // Mais de um elemento na lista
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        } 

        delete temp->next;
        temp->next = nullptr;
    }

    // Função para imprimir a lista
    void printList()
    {
        Node *temp = head;

        cout << endl;
        cout << "lista: ";
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

    // Removendo o último elemento
    list.removeLast();
    list.printList(); // Saída: 5 -> 30 -> 20 -> nullptr
    return 0;
}
