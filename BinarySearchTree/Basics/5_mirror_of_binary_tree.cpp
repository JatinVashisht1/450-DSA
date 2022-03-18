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

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> temp;
    temp.push(root);
    while (!temp.empty())
    {
        Node *current = temp.front();
        cout << current->data << " ";
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
}

void mirrorTree(Node** root){
    if(*root == NULL){
        return;
    }
    mirrorTree(&(*root)->left);
    mirrorTree(&(*root)->right);

    // these lines will be executed after recursion arrives at leave nodes of right and left sub trees
    // swapping pointers of the nodes
    Node* temp = (*root)->right;
    (*root)->right = (*root)->left;
    (*root)->left = temp;
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
    levelOrderTraversal(root);
    mirrorTree(&root);
    cout<<"\n";
    levelOrderTraversal(root);
    return 0;
}