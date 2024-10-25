
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

    // Função para inverter a lista encadeada
    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next; // Armazena o próximo nó
            current->next = prev; // Inverte o ponteiro do nó atual
            prev = current;       // Move prev para o nó atual
            current = next;       // Avança para o próximo nó
        }
        head = prev; // Atualiza o head para o novo primeiro nó
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
    list.printList(); // Saída: 5,30,20,10

    // Revertendo ordem da lista
    list.reverse();
    list.printList(); // Saída: 
    return 0;
}
