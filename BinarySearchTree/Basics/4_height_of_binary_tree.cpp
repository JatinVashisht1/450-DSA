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

Node *getNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    return temp;
}

void insert(Node **root, int data)
{
    Node *temp = getNode(data);
    if (*root == NULL)
    {
        *root = temp;
    }
    else if (data <= (*root)->data)
    {
        insert(&(*root)->left, data);
    }
    else
    {
        insert(&(*root)->right, data);
    }
}

int getHeight(Node *root, int height = 0)
{
    if(root == NULL){
        // returning -1 because the height of leaf node would be 0
        return -1;
    }
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int main()
{
    Node *root = NULL;
    insert(&root, 45);
    insert(&root, 55);
    insert(&root, 35);
    insert(&root, 25);
    insert(&root, 30);
    insert(&root, 65);
    insert(&root, 75);
    cout<<getHeight(root);
    return 0;
}