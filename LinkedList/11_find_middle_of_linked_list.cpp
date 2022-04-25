#include <iostream>
using namespace std;

class Node{
    public:
    int data; 
    Node* next;
    Node(){
        next = NULL;
    }
};

void printList(Node* head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    printList(head->next);
}

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

Node* findMiddle(Node* head){
    Node* slow = new Node();
    slow = head;
    Node* fast = head;
    while(fast && fast->next && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    Node* head = NULL;
    insertNode(&head, 15, 1);
    insertNode(&head, 25, 1);
    insertNode(&head, 35, 1);
    insertNode(&head, 45, 1);
    insertNode(&head, 55, 1);
    insertNode(&head, 65, 1);
    printList(head);
    cout<<"\n";
    cout<<findMiddle(head)->data;
    return 0;
}