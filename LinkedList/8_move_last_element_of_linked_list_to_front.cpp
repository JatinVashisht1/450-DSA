#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = nullptr;
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
        return;
    }
    cout << head->data << " ";
    printList(head->next);
}

Node* bringLastElementToFront(Node* head){

    Node* headTemp = new Node();
    headTemp = head;
    if(head == NULL || head->next == NULL){
        return head;
    }

    while(head->next->next){
        head = head->next;
    }
    Node* lastElement = new Node();
    lastElement = head->next;
    lastElement->next = headTemp;
    head->next = NULL;
    headTemp = lastElement;
    return headTemp;
}

int main()
{
    Node *head = NULL;
    insert(&head, 55, 1);
    insert(&head, 65, 1);
    insert(&head, 75, 1);
    insert(&head, 85, 1);
    insert(&head, 95, 1);
    printList(head);
    cout<<"\n";
    head = bringLastElementToFront(head);
    printList(head);
    return 0;
}