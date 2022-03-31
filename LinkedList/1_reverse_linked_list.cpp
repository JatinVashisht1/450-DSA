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

void reverseListUtil(Node **root, queue<Node *> temp)
{
    // cout<<"entered reverselistutil\n";
    cout << "current root is " << (*root)->data << "\n";
    if ((*root) == NULL)
    {
        cout << "Entered base condition\n";
        temp.push(NULL);
        return;
    }
    temp.push((*root)->next);
    if ((*root)->next != NULL)
    {
        reverseListUtil(&(*root)->next, temp);
    }
    else{
    cout << "hello world\n";
    Node *curr = new Node();
        curr = temp.front();
        temp.pop();

    cout << "curr is " << curr->data << " \n";
    (*root)->next = curr;
    // cout<<
    cout << "leaving reverselist util\n";
    }
}

void reverseList(Node **root)
{
    cout << "Entered reverseList\n";
    queue<Node *> temp = queue<Node *>();
    temp.push((*root));
    reverseListUtil(root, temp);
    cout << "Leaving reverse list\n";
}

void printList(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printList(root->next);
    cout << root->data << " ";
}

void print2(Node** root, Node* prev){
    if (*root == NULL)
    {
        cout<<"Entered base\n";
        return;
    }

    print2(&(*root)->next, *root);
    cout<<"recursion ended\n";
    (*root)->next = prev;
    // cout<<(*root)->data<<"\n";
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
    cout << "\n";
    // reverseList(&root);
    print2(&root, NULL);
    printList(root);
    return 0;
}