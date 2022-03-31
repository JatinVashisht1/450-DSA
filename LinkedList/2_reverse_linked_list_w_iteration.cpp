#include <iostream>
#include <stack>
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

void insertAtLast(Node **head, Node* head2,Node *temp)
{
    if(head2 == NULL){
        *head = temp;
        temp->next = NULL;
        return;
    }else if(head2->next == NULL){
        (*head)->next = temp;
        temp->next = NULL;
        return;
    }else{
        insertAtLast(&(*head)->next, head2->next, temp);
    }
}

void reverseListUtil(Node **head, stack<Node *> temp)
{
    cout<<"Entered reverse list util\n";
    Node *headTemp = temp.top();
    while (!temp.empty())
    {
        cout<<"Entered while loop\n";
        insertAtLast(head, *head,temp.top());
        temp.pop();
    }
    *head = headTemp;
}

void reverseList(Node **head)
{
    cout<<"Entered reverseList\n";
    stack<Node *> temp;
    while ((*head) != NULL)
    {
        temp.push(*head);
        *head = (*head)->next;
    }

    reverseListUtil(head, temp);
}

void insertNode(Node **head, int data, int pos)
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

void printList(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printList(root->next);
}

int main()
{
    // Node* head = NULL;
    Node *root = NULL;
    insertNode(&root, 45, 1);
    insertNode(&root, 55, 2);
    insertNode(&root, 65, 3);
    insertNode(&root, 75, 4);
    insertNode(&root, 85, 5);
    printList(root);
    reverseList(&root);
    printList(root);
    return 0;
}