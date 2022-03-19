#include <iostream>
#include <stack>
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
        return;
    }
    if (data <= (*root)->data)
    {
        insert(&(*root)->left, data);
    }
    if (data > (*root)->data)
    {
        insert(&(*root)->right, data);
    }
}

void postOrderWithRecursion(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderWithRecursion(root->left);
    postOrderWithRecursion(root->right);
    cout << root->data << " ";
}

// Iterative function to perform postorder traversal on the tree
void postorderIterative(Node* root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
 
    // create an empty stack and push the root node
    stack<Node*> s;
    s.push(root);
 
    // create another stack to store postorder traversal
    stack<int> out;
 
    // loop till stack is empty
    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        Node* curr = s.top();
        s.pop();
 
        out.push(curr->data);
 
        // push the left and right child of the popped node into the stack
        if (curr->left) {
            s.push(curr->left);
        }
 
        if (curr->right) {
            s.push(curr->right);
        }
    }
 
    // print postorder traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
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

    postOrderWithRecursion(root);
    cout<<"\n----------\n";
    postorderIterative(root);

    return 0;
}