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

Node* MergeTwoSorted_LL(Node* first,Node* second){

    if(first->next==NULL){
        first->next=second;
        return first;
    }
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    


    Node* curr1= first;
    Node* next1=curr1->next;
    Node* curr2=second;
    Node* next2=curr2->next;
    

     while(next1!=NULL && curr2!=NULL){

       if((curr2->data<=next1->data) && (next1->data>=curr2->data)){
        curr1->next=curr2;
        next2=curr2->next;
        curr2->next=next1;

        curr1=curr2;
        curr2=next2; 
       }
       else{
            curr1=next1;
            next1=next1->next;
    
         if (next1==NULL){
            curr1->next=curr2;
            return first;
            }
        }
    }

     return first;
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
    Node* first1=new Node(2);
    Node* first=first1;
    Node* first2=new Node(4);
    Node* first3=new Node(4);
    Node* first4=new Node(7);

    first1->next=first2;
    first2->next=first3;
    first3->next=first4;
    first4->next=NULL;
    

    Node* second1=new Node(2);
    Node* second=second1;
    Node* second2=new Node(3);
    Node* second3=new Node(6);
    Node* second4=new Node(8);

    second1->next=second2;
    second2->next=second3;
    second3->next=second4;
    second4->next=NULL;


    // We have 2 Linked list with name first and second
    //first -> 2 4 4 7
    //second-> 2 3 6 8
    printLL(first);
    printLL(second);

    
    Node* head=NULL;
    if(first->data<=second->data){
        head=MergeTwoSorted_LL(first , second);
    }
    else{
        head=MergeTwoSorted_LL(second , first);
    }
    
    
    printLL(head);

    


    
    
}