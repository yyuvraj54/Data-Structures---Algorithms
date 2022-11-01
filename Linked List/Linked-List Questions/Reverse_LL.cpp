#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};


Node* Reverse(Node* &head){
    Node*  pre=NULL;
    Node*  curr=head;
    Node* forward;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=pre;
        pre=curr;
        curr=forward;
    }
    return pre;


}

void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }     
    cout<<endl;
}

int main()
{

    Node* head=new Node(5);
    Node* tail=head;

    Node* n2=new Node(10);
    head->next=n2;
    Node* n3=new Node(15);
    n2->next=n3;
    Node* n4=new Node(20);
    n3->next=n4;
    Node* n5=new Node(25);
    n4->next=n5;
    n5->next=NULL;



    printLL(head);

    

    printLL(Reverse(head));

    



    
    return 0;
}
