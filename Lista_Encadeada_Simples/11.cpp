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

    // Função para obter o ponteiro head (apenas para fins de teste)
    Node *getHead()
    {
        return head;
    }

    // Função para verificar se a lista contém um ciclo
    bool hasCycle()
    {
        if (head == nullptr)
            return false;

        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true; // Ciclo detectado
            }
        }

        return false; // Nenhum ciclo detectado
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
    // Inserindo elementos na lista
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.insertAtBeginning(40);

    // Criando um ciclo manualmente para teste
    Node *head = list.getHead();
    head->next->next->next->next = head->next;

    // Verificando se a lista contém um ciclo
    if (list.hasCycle())
    {
        cout << "Ciclo detectado na lista." << endl;
    }
    else
    {
        cout << "Nenhum ciclo detectado na lista." << endl;
    }

    return 0;
}
