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

Node* k_Reverse(Node* &head,int k){
    if (head==NULL){
        return NULL;
    }
    Node* previous=NULL;
    Node* curr=head;
    Node* next=NULL;
    int counter=0;  

    while(counter<k && curr!=NULL){
        next=curr->next;

        curr->next=previous;
        previous=curr;
        curr=next;
        
        counter++;
    }

    if(next!=NULL){

        head->next=k_Reverse(next,k);
    }
    return previous;
    
      



    

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
    Node* n1=new Node(10);
    Node* head=n1;
    Node* n2=new Node(20);
    Node* n3=new Node(31);
    Node* n4=new Node(1);
    Node* n5=new Node(70);
    Node* n6=new Node(110);
    Node* n7=new Node(160);
    Node* n8=new Node(150);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=n7;
    n7->next=n8;
    n8->next=NULL;
    Node* tail=n8;

    int k;
    cin>>k;
    printLL(head);
    k_Reverse(head,k);
    printLL(head);
    return 0;
}
