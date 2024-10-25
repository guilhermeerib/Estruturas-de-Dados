
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

    // Função para buscar um valor específico na lista
    string search(int value)
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return "Encontrado"; // Valor encontrado
            }
            temp = temp->next;
        }

        return "Nao encontrado"; // Valor não encontrado
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

    // Buscando valores na lista
    cout << "Busca por 20: " << list.search(20) << endl; // Saída: Encontrado
    cout << "Busca por 15: " << list.search(15) << endl; // Saída: Não encontrado
    return 0;
}
