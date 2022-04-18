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

void insert(Node** head, int data, int pos){
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



void reverseList(Node** head){
    Node* curr, *prev, *next;
    curr = *head;
    next = curr->next;
    prev = NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

Node* addTwoNumbersUtil(Node* headOne, Node* headTwo, int carry=0){
    Node* headThree = new Node();
    Node* headThreeTemp = headThree;
    while (headOne && headTwo)
    {
        cout<<"head one is "<<headOne->data<<" head two is "<<headTwo->data<<" head three is "<<headThree->data<<"\n";
        headThreeTemp->data = headOne->data + headTwo->data;   
        Node* temp = new Node();
        temp->data = 0;
        headThreeTemp->next = temp;
        headThreeTemp = headThreeTemp->next;
        

        cout<<"head one is "<<headOne->data<<" head two is "<<headTwo->data<<" head three is "<<headThree->data<<"\n";
        headOne = headOne->next;
        headTwo = headTwo->next;
    }
    if(headOne){
        cout<<"entered if head one\n";
        Node* temp = new Node();
        temp->data = headOne->data;
        // cout<<temp->data<<"\n";
        headThreeTemp->next = temp;
        headOne = headOne->next;
        headThreeTemp = headThreeTemp->next;
    }
    if(headTwo){
        cout<<"entered if head two\n";
        Node* temp = new Node();
        temp->data = headTwo->data;
        headThreeTemp->next = temp;
        headTwo = headTwo->next;
        headThreeTemp = headThreeTemp->next;
    }
    return headThree;
}

Node* addTwoNumbers(Node* headOne, Node* headTwo){
    reverseList(&headOne);
    reverseList(&headTwo);
    Node* headThree = new Node();
    headThree = addTwoNumbersUtil(headOne, headTwo);
    reverseList(&headThree);
    return headThree;
}

int main(){
Node* headOne = NULL;
Node* headTwo = NULL;
insert(&headOne, 3, 1);
insert(&headOne, 4, 2);
insert(&headOne, 5, 3);

insert(&headTwo, 4, 1);
insert(&headTwo, 2, 2);
// insert(&headTwo, 4, 3);
printList(headOne);
cout<<"\n";
printList(headTwo);
cout<<"\n";
Node* headThree = addTwoNumbers(headOne, headTwo);
printList(headThree);

return 0;
}