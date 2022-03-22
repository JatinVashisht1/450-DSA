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

void insert(Node **root, int data)
{
    Node *tempNode = getNode(data);

    if (*root == NULL)
    {
        *root = tempNode;
    }
    else if (data < (*root)->data)
    {
        insert (&(*root)->left, data);
    }
    else
    {
        insert (&(*root)->right, data);
    }
}

// level order traversal or BFS of BST
void levelOrderTraversal(Node* root){
    
    if (root == NULL){
        return;
    }

    // creating a temp node to store nodes
    queue<Node*> temp; 
    temp.push(root);

    // remember that insertion in queue is done at end and deletion at front
    while(!temp.empty()){

        // current variable is initialised to store the node at the front of temp queue
        Node* current = temp.front();
        cout<<current->data<<" ";

        // pushing chids of current node to the queue
        if(current->left != NULL){
            temp.push(current->left);
        }
        if(current->right != NULL){
            temp.push(current->right);
        }
        // popping the explored node
        temp.pop();
    }
}

int main()
{
    Node* root = NULL;
    insert (&root, 45);
    insert (&root, 55);
    insert (&root, 35);
    insert (&root, 25);
    insert (&root, 30);
    insert (&root, 65);
    insert (&root, 75);

    levelOrderTraversal(root);
    
    
    return 0;
}