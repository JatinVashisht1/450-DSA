#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node()
    {
        next = NULL;
    }
};

void insert(Node **head, int data, int pos)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (pos == 1)
    {
        temp->next = *head;
        *head = temp;
        return;
    }

    Node* temp2 = new Node();
    temp2 = *head;
    for(int i = 0; i<pos-2; i++){
        temp2 = temp2->next;
    }

    temp->next = temp2->next;
    temp2->next = temp;
    return;
}

bool detectLoopUtil(Node* head, Node* slow, Node* fast){
    if(head == NULL){
        // cout<<"Entered if 1\n";
        return false;
    }
    if(slow->next == NULL){
        // cout<<"entered if 2\n";
        return false;
    }
    if(fast->next == NULL || fast->next->next == NULL){
        // cout<<"Entered if 3\n";
        return false;
    }
    if(slow == fast){
        // cout<<"Returning true\n";
        return true;
    }
    return detectLoopUtil(head, slow->next, fast->next->next);
}

bool detectLoop(Node* head){
    return detectLoopUtil(head, head->next, head->next->next );
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
    insert(&head, 55, 1);
    insert(&head, 65, 2);
    insert(&head, 75, 3);
    insert(&head, 85, 4);
    insert(&head, 95, 5);
    printList(head);
    cout<<"\n";
    cout<<detectLoop(head);
    return 0;
}