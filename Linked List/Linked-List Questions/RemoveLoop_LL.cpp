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

Node* startingPoint(Node* head,Node* floyIndex){
    
    if(floyIndex==NULL){
        return NULL;
    }

    Node* slow=head;
    while(floyIndex!=slow){
        slow=slow->next;
        floyIndex=floyIndex->next;
    }
     return slow;
}
void RemoveLOOP(Node* starting){
    
    if(starting==NULL){
        return;
    }
    Node* temp=starting;
    while(temp->next!=starting){
        temp=temp->next;
    }
    temp->next=NULL;
}


Node* FloyAlgo(Node* head){

    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL){
        
        
        slow=slow->next;
        fast=fast->next->next;
        

        if(fast==slow){
            return slow;
            break;
        }
    }
    return NULL;


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
    

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=n2 ;

    Node* index=FloyAlgo(head);
    Node* index2=startingPoint(head,index);
    RemoveLOOP(index2);
    printLL(head);

    
    return 0;
}
