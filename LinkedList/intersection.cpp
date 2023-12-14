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

int getLenght(Node* head){
    Node* temp=head;
    int lenght=0;

    while(temp){
        temp=temp->next;
        lenght++;
    }
    return lenght;
}

Node* moveHeadByK(Node* head,int k){
    Node* ptr=head;
    while(k--){
        ptr=ptr->next;
    }
    return ptr;
}

Node* getIntersection(Node* head1, Node* head2){
    //calculate lenght of both ll 
    int l1=getLenght(head1);
    int l2=getLenght(head2);

    //find diff k b/w ll n move longer ll by k
    Node* ptr1;
    Node* ptr2;

    if (l1>l2){
        //ll1 is longer
        int k=l1-l2;
        ptr1=moveHeadByK(head1,k);
        ptr2=head2;
    } else {
        //ll2 is longer
        int k=l2-l1;
        ptr1=head1;
        ptr2=moveHeadByK(head2,k);
    }

    //compre ptr 1 and ptr 2
    while(ptr1){
        if(ptr1==ptr2){
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return NULL;
}

int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);

    LinkedList ll2;
    ll2.insertAtTail(6);
    ll2.insertAtTail(7);

    ll2.head->next->next=ll1.head->next->next->next;
    Node* intersection=getIntersection(ll1.head,ll2.head);

    if(intersection){
        cout<<intersection->val<<endl;
    }else{
        cout<<"no ontersaction";
    }
}
    