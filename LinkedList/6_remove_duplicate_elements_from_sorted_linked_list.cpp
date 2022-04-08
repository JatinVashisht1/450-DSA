#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
};

void insert(Node **head, int data, int pos)
{
    Node *temp = new Node();
    temp->data = data;
    if (pos == 1)
    {
        temp->next = *head;
        *head = temp;
        return;
    }

    Node *temp2 = new Node();
    temp2 = *head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
    return;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        cout << "\n";
        return;
    }
    cout << head->data << " ";
    printList(head->next);
}

Node *removeDuplicatesFromSorted(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *head2 = new Node();
    head2 = head;
    while (head->next != NULL)
    {
        if (head->next->data == head->data)
        {
            Node *temp = new Node();
            temp = head->next;
            head->next = temp->next;
            delete temp;
        }
        else
        {
            head = head->next;
        }
    }
    return head2;
}

int main()
{

    Node *head = NULL;
    int numberOfElements = 12;
    // cin>>numberOfElements;
    for (int i = 1; i <= numberOfElements; i++)
    {
        int data = i + 1;
        if (i == 9 || i == 10)
        {
            data = 9;
        }
        insert(&head, data, i);
    }
    printList(head);
    head = removeDuplicatesFromSorted(head);
    cout<<"\n";
    printList(head);
    return 0;
}