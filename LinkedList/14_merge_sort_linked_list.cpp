#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
};

void insert(Node **head, int data, int pos)
{
    Node *temp = new Node();
    temp->data = data;
    if (pos == 1)
    {
        temp->next = *head;
        *head = temp;
        return;
    }

    Node *temp2 = new Node();
    temp2 = *head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
    return;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    printList(head->next);
}

Node *getMid(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;
    while (fast && fast->next /*&& fast->next->next*/)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    // cout << "Entered merge function\n";
    // if left is null then right will be already sorted so return right
    if (left == NULL)
    {
        return right;
    }
    // if right is null then left will be already sorted so return left
    if (right == NULL)
    {
        return left;
    }

    Node *ans = new Node();
    Node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left; // because temp has to remain at the end of the list to add new element at the end of the list each time
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    // cout << "leaving merege function\n";
    return ans;
}

Node *mergeSort(Node *head)
{
    // cout << "Entered mergeSort\n";
    if (head == NULL || head->next == NULL)
    {
        // cout << "Entered base condition\n";
        return head;
    }
    Node *mid = getMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;
    // cout<<"mid is "<<mid->data; 
    // cout<<" left is "<<left->data; 
    // cout<<" right is "<<right->data<<"\n";
    left = mergeSort(left);
    right = mergeSort(right);
    // cout<<"Recursive calls ended\n";
    Node *result = merge(left, right);
    return result;
}

int main()
{
    Node *head = NULL;
    insert(&head, 25, 1);
    insert(&head, 35, 1);
    insert(&head, 15, 1);
    insert(&head, 75, 1);
    insert(&head, 5, 1);
    printList(head);
    // cout<<"mid element is "<<getMid(head)->data<<"\n";
    head = mergeSort(head);
    cout<<"\n";
    printList(head);
    return 0;
}