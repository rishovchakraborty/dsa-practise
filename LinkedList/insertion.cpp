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

void insertAtHead(Node *&head, int val)
{
    Node *new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insertAtTail(Node *&head, int val)
{
    Node *new_node = new Node(val);
    Node *temp = head;
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertAtKPos(Node* &head,int val,int pos){
    if(pos==0){
        insertAtHead(head,val);
        return;
    }
    Node* new_node= new Node(val);
    Node* temp=head;
    int curr_pos=0;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->val << "-->";
        temp = temp->next;
    }
    cout << "null" << endl;
}

int main()
{
    Node *head = NULL;
    // insertAtHead(head,2);
    insertAtTail(head, 2);
    display(head);
    // insertAtHead(head,3);
    insertAtTail(head, 3);
    display(head);
}