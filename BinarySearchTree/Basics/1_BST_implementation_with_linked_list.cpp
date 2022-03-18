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

// to get a new node dynamically
Node *getNode(int data)
{
    Node *node = new Node();
    node->data = data;
    return node;
}

// to insert new node in the BST
void insertNode(Node **root, int data)
{
    Node *tempNode = getNode(data);

    // handling all the three cases that we can come across
    // 1. if the root node is empty
    // this is our base condition
    if (*root == NULL)
    {
        // if root node is empty simply assign root node the tempNode
        // that we got from getNode function
        *root = tempNode;
    }
    // if the data of new node is less than the data in root node
    // traversing the tree via recursion untill we find a leave node
    else if (data < (*root)->data)
    {
        insertNode(&(*root)->left, data);
    }
    else
    {
        insertNode(&(*root)->right, data);
    }
}

int main()
{
    Node* root = NULL;
    insertNode(&root, 45);
    insertNode(&root, 55);
    insertNode(&root, 35);

    cout<<"data of root is "<<root->data<<"\ndata of left node of root is "<<root->left->data<<"\ndata of right node of root is "<<root->right->data;

    return 0;
}