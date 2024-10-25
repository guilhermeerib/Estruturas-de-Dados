
#include <iostream>
#include <unordered_set>
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

    // Função para remover elementos duplicados
    void removeDuplicates()
    {
        if (head == nullptr)
            return;

        unordered_set<int> seen;
        Node *current = head;
        Node *prev = nullptr;

        while (current != nullptr)
        {
            if (seen.find(current->data) != seen.end())
            {
                // Elemento duplicado encontrado
                prev->next = current->next;
                delete current;
            }
            else
            {
                // Elemento não duplicado
                seen.insert(current->data);
                prev = current;
            }
            current = prev->next;
        }
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
    // Inserindo elementos na lista
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);
    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(40);
    list.printList(); // Saída: 40 -> 20 -> 30 -> 10 -> 20 -> 10 -> nullptr

    // Removendo elementos duplicados
    list.removeDuplicates();
    list.printList(); // Saída: 40 -> 20 -> 30 -> 10 -> nullptr

    return 0;
}
