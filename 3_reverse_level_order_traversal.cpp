#include <iostream>
#include <stack>
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

void reverseLevelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> temp;
    stack<int> temp2;
    temp.push(root);
    while (!temp.empty())
    {
        Node *current = temp.front();
        temp2.push(current->data);
        if (current->left != NULL)
        {
            temp.push(current->left);
        }
        if (current->right != NULL)
        {
            temp.push(current->right);
        }
        temp.pop();
    }
    while(!temp2.empty()){
        cout<<temp2.top()<<" ";
        temp2.pop();
    }
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
    
    reverseLevelOrder(root);
    return 0;
}