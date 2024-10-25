
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

    // Função para inserir um novo elemento em uma posição específica
    void insertAtPosition(int value, int position)
    {
        cout << "Inserindo valor: " << value << " na posicao: " << position << endl;
        Node *newNode = new Node(value);
        if (position == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        for (int i = 0; temp != nullptr && i < position - 1; ++i)
        {
            temp = temp->next;
            cout << "iteracao:" << i << endl;
        }

        if (temp == nullptr)
        {
            cout << "A posicao fornecida e invalida." << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
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

    // Inserindo em posições específicas
    list.insertAtPosition(15, 2);
    list.printList(); // Saída: 5 -> 30 -> 15 -> 20 -> 10 -> nullptr

    list.insertAtPosition(25, 0);
    list.printList(); // Saída: 25 -> 5 -> 30 -> 15 -> 20 -> 10 -> nullptr

    list.insertAtPosition(35, 10); // Posição inválida
    list.printList();              // Saída: 25 -> 5 -> 30 -> 15 -> 20 -> 10 -> nullptr

    list.insertAtPosition(35, 6); // Posição válida
    list.printList();
    return 0;
}
