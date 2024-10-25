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

    // Função para inserir um novo elemento no final da lista
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
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

    // Função para separar a lista em pares e ímpares
    void separateEvenOdd(LinkedList &evenList, LinkedList &oddList)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data % 2 == 0)
            {
                evenList.insertAtEnd(temp->data);
            }
            else
            {
                oddList.insertAtEnd(temp->data);
            }
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList list;
    // Inserindo elementos na lista
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);

    // Criando listas para pares e ímpares
    LinkedList evenList;
    LinkedList oddList;

    // Separando a lista em pares e ímpares
    list.separateEvenOdd(evenList, oddList);

    // Imprimindo as listas resultantes
    cout << "Lista de numeros pares: ";
    evenList.printList(); // Saída: 2 -> 4 -> 6 -> nullptr

    cout << "Lista de numeros impares: ";
    oddList.printList(); // Saída: 1 -> 3 -> 5 -> nullptr

    return 0;
}
