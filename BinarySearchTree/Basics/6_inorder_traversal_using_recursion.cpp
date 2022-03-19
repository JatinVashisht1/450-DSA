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

void inorderWithRec(Node *root)
{
    
    if(root == NULL){
        return;
    }
    inorderWithRec(root->left);
    cout << root->data << " ";
    inorderWithRec(root->right);
}

void inorderWithIter(Node* root){
    // stack to take care of visited nodes
    // basically we are first adding nodes to stack in nested while loop
    // and then printing the top element of stack and popping it
    // then curr is set to the right node inorder to traverse the right sub tree also
    stack<Node*> temp;
    Node* curr = root;
    while(curr != NULL || !temp.empty()){
        while(curr != NULL){
            temp.push(curr);
            curr = curr->left;
        }
        curr = temp.top();
        temp.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
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

    inorderWithIter(root);
    cout<<"\n-------------\n";
    inorderWithRec(root);
    return 0;
}