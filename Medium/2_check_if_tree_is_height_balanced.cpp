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
    if (root == NULL)
    {
        *root = NULL;
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

int getHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

bool isBalanced(Node *root)
{
    // variable for left height
    int lh;
    // variable for right height
    int rh;
    if (root == NULL)
    {
        return true;
    }
    // getting height of left and right subtree
    lh = getHeight(root->left);
    rh = getHeight(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    {
        return true;
    }
    return false;
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

    int isBal = isBalanced(root);
    cout<<isBal;
    return 0;
}