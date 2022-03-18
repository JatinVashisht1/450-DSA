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

// to get a new node dynamically
Node *getNode(int data)
{
    Node *node = new Node();
    node->data = data;
    return node;
}

void insertNode(Node **root, int data)
{
    Node *tempNode = getNode(data);

    if (*root == NULL)
    {
        *root = tempNode;
    }
    else if (data < (*root)->data)
    {
        insertNode(&(*root)->left, data);
    }
    else
    {
        insertNode(&(*root)->right, data);
    }
}

// level order traversal or BFS of BST
void levelOrderTraversal(Node* root){
    if (root == NULL){
        return;
    }
    queue<Node*> temp;
    temp.push(root);
    while(!temp.empty()){
        Node* current = temp.front();
        cout<<current->data<<" ";

        if(current->left != NULL){
            temp.push(current->left);
        }
        if(current->right != NULL){
            temp.push(current->right);
        }
        temp.pop();
    }
}

int main()
{
    Node* root = NULL;
    insertNode(&root, 45);
    insertNode(&root, 55);
    insertNode(&root, 35);
    insertNode(&root, 25);
    insertNode(&root, 30);
    insertNode(&root, 65);
    insertNode(&root, 75);

    levelOrderTraversal(root);
    
    
    return 0;
}