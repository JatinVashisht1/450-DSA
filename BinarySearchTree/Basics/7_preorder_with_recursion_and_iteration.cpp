#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node()
    {
        left = NULL;
        right = NULL;
    }
};

void insert(Node **root, int data)
{
    Node *temp = new Node();
    temp->data = data;
    if (*root == NULL)
    {
        *root = temp;
        return;
    }
    if (data < (*root)->data)
    {
        insert(&(*root)->left, data);
    }
    if (data > (*root)->data)
    {
        insert(&(*root)->right, data);
    }
}

void preorderWithRecursion(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderWithRecursion(root->left);
    preorderWithRecursion(root->right);
}

void preorderWithIteration(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        // pop a node from the stack and print it
        Node *curr = s.top();
        s.pop();

        cout << curr->data << " ";

        // push the right child of the popped node into the stack
        if (curr->right)
        {
            s.push(curr->right);
        }

        // push the left child of the popped node into the stack
        if (curr->left)
        {
            s.push(curr->left);
        }

        // the right child must be pushed first so that the left child
        // is processed first (LIFO order)
    }
}

int main()
{
    Node *root = NULL;
    insert(&root, 55);
    insert(&root, 35);
    insert(&root, 65);
    insert(&root, 25);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 75);

    preorderWithRecursion(root);
    cout<<"\n--------------\n";
    preorderWithIteration(root);
    return 0;
}