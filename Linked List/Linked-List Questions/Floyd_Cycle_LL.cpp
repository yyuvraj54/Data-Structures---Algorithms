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



bool FloyAlgo(Node* head){

    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL){
        
        
        slow=slow->next;
        fast=fast->next->next;
        

        if(fast==slow){
            return 1;
            break;
        }
    }
    return 0;


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

    cout<<FloyAlgo(head)<<endl;


    
    return 0;
}
