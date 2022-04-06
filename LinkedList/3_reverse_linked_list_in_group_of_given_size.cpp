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

void insertInLinkedList(Node **head, int data, int position)
{
    Node *temp = new Node();
    temp->data = data;
    if (position == 1)
    {
        temp->next = *head;
        *head = temp;
        return;
    }

    Node *temp2 = new Node();
    temp2 = *head;
    for (int i = 0; i < position - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
    return;
}



Node *reverseBySize(Node* head, int k)
{
    // game of current, next and previous nodes!
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
    while(current != NULL && count<k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(next!= NULL){
        head->next = reverseBySize(next, k);
    }
    // previous node will become head when the function will finish executing
    return prev;
}

void printList(Node* head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    printList(head->next);
}

int main()
{
    Node* head = NULL;
    insertInLinkedList(&head, 55, 1);
    insertInLinkedList(&head, 45, 1);
    insertInLinkedList(&head, 35, 1);
    insertInLinkedList(&head, 25, 1);
    insertInLinkedList(&head, 15, 1);
    insertInLinkedList(&head, 5, 1);
    insertInLinkedList(&head, 35, 1);
    printList(head);
    cout<<"\n";
    head = reverseBySize(head, 3);
    printList(head);
    return 0;
}