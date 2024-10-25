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

    // Função para fundir duas listas encadeadas ordenadas
    static LinkedList mergeSortedLists(LinkedList &list1, LinkedList &list2)
    {
        LinkedList mergedList;
        Node *l1 = list1.head;
        Node *l2 = list2.head;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->data <= l2->data)
            {
                mergedList.insertAtEnd(l1->data);
                l1 = l1->next;
            }
            else
            {
                mergedList.insertAtEnd(l2->data);
                l2 = l2->next;
            }
        }

        // Adiciona os elementos restantes de l1, se houver
        while (l1 != nullptr)
        {
            mergedList.insertAtEnd(l1->data);
            l1 = l1->next;
        }

        // Adiciona os elementos restantes de l2, se houver
        while (l2 != nullptr)
        {
            mergedList.insertAtEnd(l2->data);
            l2 = l2->next;
        }

        return mergedList;
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

    LinkedList mergedList = LinkedList::mergeSortedLists(list1, list2);
    mergedList.printList(); // Saída: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> nullptr

    return 0;
}
