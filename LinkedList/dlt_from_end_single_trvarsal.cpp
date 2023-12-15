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

void f(Node* &head,int k){
    Node* ptr1=head;
    Node* ptr2=head;

    //move ptr2 by k step
    while(k--){
        ptr2=ptr2->next;
    }
    //if k=lenght of LL
    if(ptr2==NULL){
        Node* temp=head;
        head=head->next;
        free(temp);
        return;
    }
    //if k<lenght of ll
    // when ptr2 at null...ptr 1 will be pointing to a postition to be deleted
    //but for mainting the linkage we ned to keep the acsees of prev node of ptr1
    //we have to stop at (ptr2->next==null) 
    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    //node to be dlt===> ptr1->nxt
    Node* temp=ptr1->next;
    ptr1->next=ptr1->next->next;
    free(temp);
}


int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.display();
    f(ll1.head,3);
    ll1.display();
}