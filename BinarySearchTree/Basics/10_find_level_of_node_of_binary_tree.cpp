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

// concept of level order traversal will be used
int findLevel(Node *root, Node *node, int level = 0)
{
    if (root == NULL || node == NULL)
    {
        return level;
    }

    // making a queue to store elements
    queue<Node *> temp;
    temp.push(root);
    while (!temp.empty())
    {
        Node* current = new Node();
        current = temp.front();
        if (current == node)
        {
            level++;
            return level;
        }
        if (current->left != NULL)
        {
            temp.push(root->left);
            root = root->left;
            level++;
        }
        if (current->right != NULL)
        {
            temp.push(root->right);
            level++;
        }
        // popping the explored node
        // in queue the deletion is done at front and insertion at end
        temp.pop();
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
    int level = findLevel(root, root->left);
    cout<<"level is "<<level;
    return 0;
}