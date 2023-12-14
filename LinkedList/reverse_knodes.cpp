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

Node* reversal_k_nodes(Node* &head,int k){
    Node* curr=head;
    Node* prev=NULL;
    int counter=0;
    while(curr&&counter<k){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        counter++;
    }
    //curr gives (k+1)th node
    if(curr){
        Node* new_node= reversal_k_nodes(curr,k);
        head->next=new_node;
    }
    return prev; 
}

int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();
    ll.head=reversal_k_nodes(ll.head,2);
    ll.display();
}