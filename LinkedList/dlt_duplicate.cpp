#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    void insertAtTail(int val)
    {
        Node *new_node = new Node(val);
        if (!head)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << "-->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

void deleteDuplicate(Node *&head)
{
    Node *curr = head;
    while(curr){
            while (curr->next && curr->val == curr->next->val)
    {
        Node *temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }
    curr = curr->next;
    }
}

int main()
{
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(2);
    ll.insertAtTail(4);
    ll.insertAtTail(4);
    ll.display();
    // deleteAlternative(ll.head);
    deleteDuplicate(ll.head);
    ll.display();
}
