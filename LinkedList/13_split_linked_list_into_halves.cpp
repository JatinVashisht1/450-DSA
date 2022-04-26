#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        next = NULL;
    }
};

void insertNode(Node** head, int data, int pos){
    Node* temp = new Node();
    temp->data = data;

    if(pos == 1){
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

void printList(Node* head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    printList(head->next);
}

void splitLinkedListIntoTwoHalves(Node** head){
    Node* fast = *head;
    Node* slow = *head;

    while(fast->next != *head){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* slowNext = slow->next;
    fast->next = slowNext;
    slow->next = *head;
}

int main(){

    Node* head = NULL;
    insertNode(&head, 15, 1);
    insertNode(&head, 25, 1);
    insertNode(&head, 35, 1);
    insertNode(&head, 45, 1);
    head->next->next->next = head;
    splitLinkedListIntoTwoHalves(&head);
    printList(head);


    printList(head);

    return 0;
}