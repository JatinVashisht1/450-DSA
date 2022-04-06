#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
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

void removeLoop(Node* slow, Node* head){
    // find number of nodes involved
    int k = 1;
    // ptr->next != slow instead of ptr != slow because we have initialized k = 1, not 0;
    for(Node* ptr = slow; ptr->next != slow;ptr= ptr->next){
        k++;
    }

    // get a pointer to kth node from head
    Node* curr = head;
    for(int i = 0; i<k; i++){
        curr = curr->next;
    }

    // move current and head pointer with same speed simultaneously untill they meed
    while(curr != head){
        curr = curr->next;
        head = head->next;
    }

    // at the end of following loop
    // curr will point to the last node of the loop
    while(curr->next != head){
        curr = curr->next;
    }
    
    // set next of curr to NULL to break the loop
    curr->next = nullptr;
    return;
}

Node *detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return nullptr;
}

void printList(Node* head){
    if(!head){
        return;
    }
    cout<<head->data<<" ";
    printList(head->next);
}

int main()
{
    Node *head = nullptr;
    for (int i = 5; i > 0; i--)
    {
        insert(&head, 5 + i, 5-i+1);
    }

    // insert cycle
    Node *lastNode = head->next->next->next->next;
    lastNode->next = head->next;

    Node *slow = detectLoop(head);
    if (slow)
    {
        removeLoop(slow, head);
        cout << "Loop is present\n";
        printList(head);
        cout<<"\n-------------------------\n";
        cout<<detectLoop(head);
    }
    else
    {
        cout << "loop is absent\n";
    }
    return 0;
}