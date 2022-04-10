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
        return;
    }
    cout << head->data << " ";
    printList(head->next);
}

Node* reverseList(Node* head){
    Node* prev;
    Node* curr = head;
    Node* next = head->next;
    prev = NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

Node* addOneUtil(Node* head, Node* tempHead,bool carry, int pos = 1){
    cout<<"Entered function\n";
    if(head == NULL){
        return tempHead;
    }
    if(pos == 1){
        if(head->data == 9){
            head->data = 0;
            carry = true;
            return addOneUtil(head->next, tempHead, carry, pos+1);
        }else{
            head->data++;
            carry = false;
            return addOneUtil(head->next, tempHead, false, pos+1);
        }
    }
    if(head->next == NULL){
        if(carry){
            if(head->data != 9){
                head->data++;
                return tempHead;
            }
            else {
                head->data = 0;
                Node* temp = new Node();
                temp->data = 1;
                head->next = temp;
                return tempHead;
            }
        }else{
            return tempHead;
        }
    }
    if(carry){
        if(head->data == 9){
            head->data = 0;
            carry = true;
            return addOneUtil(head->next, tempHead, carry, pos+1);
        }else{
            head->data++;
            carry = false;
            return addOneUtil(head->next, tempHead, carry, pos+1);
        }
    }
    return addOneUtil(head->next, tempHead, carry, pos+1);
}

Node* addOne(Node* head){
    head = reverseList(head);
    // printList(head);
    // cout<<"\n";
    head = addOneUtil(head, head, false);
    head = reverseList(head);
    return head;
}

int main()
{
    Node* head = NULL;
    insert(&head, 9, 1);
    insert(&head, 4, 1);
    insert(&head, 8, 3);
    insert(&head, 7, 3);
    printList(head);
    cout<<"\n";
    // head = reverseList(head);
    head = addOne(head);
    printList(head);
    return 0;
}