#include <iostream>
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

void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
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

    // zigZagTraversal(root);
    // TODO: Implement zigzagtraversal logic
    return 0;
}