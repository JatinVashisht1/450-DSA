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

void insertUsingRecursion(Node** head, int data, int position){
    // cout<<"head is "<<(*head)<<" data is "<<data<<" position is "<<position<<"\n";
    if(*head == NULL){
        // cout<<"Entered if 1\n";
        Node* temp = new Node();
        temp->data = data;
        *head = temp;
        temp->next = NULL;
        // cout<<"leaving if\n";
        return;
    }
    if(position == 0){
        // cout<<"entered if 2\n";
        Node* temp = new Node();
        temp->data = data;
        temp->next = (*head)->next;
        (*head)->next = temp;
        return;
    }
    insertUsingRecursion(&(*head)->next, data, --position);
}



void printList(Node* head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    printList(head->next);
}

int main(){
    Node* head = NULL;
    insertUsingRecursion(&head, 45, 1);
    // cout<<head->data<<"------------\n";
    insertUsingRecursion(&head, 55, 2);
    insertUsingRecursion(&head, 65, 3);
    insertUsingRecursion(&head, 75, 4);
    insertUsingRecursion(&head, 85, 5);
    insertUsingRecursion(&head, 95, 6);
    printList(head);
return 0;
}