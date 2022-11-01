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

Node* Reverse(Node* mid){
    Node* pre=NULL;
    Node* curr=mid->next;
    Node* forward=NULL;


    //Reverse the LL
    while(curr!=NULL){
        forward=curr->next;
        curr->next=pre;
        pre=curr;
        curr=forward;
    }
    return pre;
    


}


bool palindrome(Node* head){
    //Find middle Node

    Node* mid=head; // also know as slow
    Node* fast=head;

    while(fast!=NULL){
        mid=mid->next;
        fast=fast->next->next;
    }
    
    //Reverse the LL from middle
    Node* temp=mid->next;
    mid->next=Reverse(mid);

    //Pre is now the head after middle

    Node* head1=head;
    Node* head2=mid->next;

    while(head1 !=mid && head2!=NULL){
        if(head1->data!=head2->data){
         return false;   
        }
        head1=head1->next;
        head2=head2->next;
        
    }

    temp=mid->next;
    mid->next=Reverse(mid);


return true;
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
    Node* n1=new Node(1);
    Node* head=n1;
    Node* n2=new Node(4);
    Node* n3=new Node(4);
    Node* n4=new Node(1);
    //Node* n5=new Node(10);


    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=NULL;
    //n5->next=NULL;
    
    

    printLL(head);
    cout<<palindrome(head)<<endl;
    printLL(head);

    return 0;    
}