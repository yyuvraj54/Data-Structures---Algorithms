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



void RemoveDublicates_UnSorted(Node* head){
    
    Node* curr=head;  
    Node* temp;
    while(curr!=NULL){
        int number=curr->data;
        temp=curr;
        while(temp->next!=NULL){
            if(temp->next->data==number){
                Node* next_next=temp->next->next;
                Node* deleteNode=temp->next;
                temp->next=next_next;
            }
            else{
                temp=temp->next;
            }
        }
        curr=curr->next;

    }

}

void RemoveDublicates_Sorted(Node* head){


    Node* temp=head;

    while(temp->next!=NULL){
        if(temp->next->data==temp->data){

            Node* next_next=temp->next->next;
            Node* DeleteNode=temp->next;
            delete DeleteNode;
            temp->next=next_next;
            
        }
        else{
            temp=temp->next;
        }
    }
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

    Node* n1=new Node(30);
    Node* head=n1;
    Node* n2=new Node(99);
    Node* n3=new Node(20);
    Node* n4=new Node(2);
    Node* n5=new Node(30);
    Node* n6=new Node(99);
    Node* n7=new Node(99);
    

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=n7;
    n7->next=NULL;
    cout<<"Orignal: "<<endl;
    printLL(head);
    RemoveDublicates_UnSorted(head);
    
    cout<<"After Removing: "<<endl;    
    printLL(head);
    







    
    return 0;
}
