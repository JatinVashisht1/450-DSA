#include <iostream>
#include <queue>
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
    }
    else if (data < (*root)->data)
    {
        insert(&(*root)->left, data);
    }
    else
    {
        insert(&(*root)->right, data);
    }
}

void leftView(Node *root, queue<Node *> temp = queue<Node *>())
{
    if (root == NULL && !temp.empty())
    {
        return;
    }

    temp.push(root);
    temp.push(root->right);
    temp.push(root->left);
    
}

int main()
{
    Node *root = NULL;
    insert (&root, 45);
    insert (&root, 55);
    insert (&root, 35);
    insert (&root, 25);
    insert (&root, 30);
    insert (&root, 65);
    insert (&root, 75);

    leftView(root);
    return 0;
}