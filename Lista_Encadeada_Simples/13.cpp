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

    // Função para obter o ponteiro head (apenas para fins de teste)
    Node *getHead()
    {
        return head;
    }

    // Função para concatenar duas listas encadeadas
    static LinkedList concatenate(LinkedList &list1, LinkedList &list2)
    {
        if (list1.head == nullptr)
            return list2;
        if (list2.head == nullptr)
            return list1;

        Node *temp = list1.head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = list2.head;

        return list1;
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
    LinkedList list1;
    list1.insertAtEnd(1);
    list1.insertAtEnd(3);
    list1.insertAtEnd(5);

    LinkedList list2;
    list2.insertAtEnd(2);
    list2.insertAtEnd(4);
    list2.insertAtEnd(6);

    LinkedList concatenatedList = LinkedList::concatenate(list1, list2);
    concatenatedList.printList(); // Saída: 1 -> 3 -> 5 -> 2 -> 4 -> 6 -> nullptr

    return 0;
}
