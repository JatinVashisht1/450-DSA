#include <iostream>
#include <unordered_set>
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

Node *removeDuplicateFromUnsortedList(Node *head)
{
    // set is used to find the duplicate element faster
    // this brings down the time complexity from O(n pow 2) to O(n)
    unordered_set<int> set;
    Node *current = head;
    Node *previous = NULL;
    while (current != nullptr)
    {
        if (set.find(current->data) != set.end())
        {
            previous->next = current->next;
        }
        else
        {
            set.insert(current->data);
            previous = current;
        }
        current = current->next;
    }
    return head;
}

int main()
{
    Node *head = NULL;
    int numberOfElements = 12;

    for (int i = 1; i <= numberOfElements; i++)
    {
        int data = i + 1;
        if (i == 9 || i == 11)
        {
            data = 9;
        }
        insert(&head, data, i);
    }
    printList(head);
    cout<<"\n";
    head = removeDuplicateFromUnsortedList(head);
    printList(head);
    return 0;
}