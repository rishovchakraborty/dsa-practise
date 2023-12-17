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
bool isPalindrom(Node* &head){
    //find mid ele
    Node* slow=head;
    Node* fast=head;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    //slow pointr poniting to middle element
    Node* curr=slow->next;
    Node* prev=slow;
    slow->next=NULL;

    //reverse the list
    while(curr){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    //check through thr reverse ll
    Node* h1=head;
    Node* h2=prev;
    while(h2){
        if(h1->val!=h2->val){
            return false;
        }
        h1=h1->next;
        h2=h2->next;
    }
    return true;
}

int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(1);
    ll.display();
    cout<<isPalindrom(ll.head);
}