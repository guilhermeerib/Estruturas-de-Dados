
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

    // Função para contar o número total de nós na lista
    int countNodes()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
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

    // Contando o número total de nós
    cout << "Número total de nos: " << list.countNodes() << endl; // Saída: 4

    return 0;
}
