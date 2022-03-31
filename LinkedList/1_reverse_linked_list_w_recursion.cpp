#include <iostream>
#include <queue>
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

void reverseListUtil(Node **root, Node* temp)
{
    if(temp->next == NULL){
        *root = temp;
        return;
    }
    reverseListUtil(root, temp->next);
    Node* q = temp->next;
    q->next = temp;
    temp->next = NULL;
}

void reverseList(Node **root)
{
    reverseListUtil(root, *root);   
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
    Node *root = NULL;
    insertNode(&root, 45, 1);
    insertNode(&root, 55, 2);
    insertNode(&root, 65, 3);
    insertNode(&root, 75, 4);
    insertNode(&root, 85, 5);
    printList(root);
    reverseList(&root);
    cout<<"\n";
    printList(root);
    return 0;
}