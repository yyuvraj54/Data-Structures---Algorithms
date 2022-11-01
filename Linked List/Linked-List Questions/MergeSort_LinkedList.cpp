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

Node* Merge(Node* left , Node* right){

    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    Node* ans=new Node(-1);
    Node* temp=ans;

    while(left!=NULL && right!=NULL){

        if(left->data < right->data){
            temp->next=left;
            temp=left;
            left=left->next;

        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        } 

    }
    while (left!=NULL)
    {
        temp->next=left;
        temp=left;
        left=left->next;
 
    }
    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    
    }
    
    ans=ans->next;
    return ans;
}



Node* midelement(Node* head){
    Node* fast=head->next;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;

}


Node* Mergesort(Node* head){
    
    if(head==NULL || head->next==NULL){
            return head;
        }
    
    
    Node* mid=midelement(head);
    Node* left=head;
    Node* right=mid->next;
    mid->next=NULL;

    left=Mergesort(left);
    right=Mergesort(right);

    Node* ans = Merge(left , right  );
    return ans;

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
    Node* first1=new Node(8);
    Node* head=first1;
    Node* first2=new Node(7);
    Node* first3=new Node(2);
    Node* first4=new Node(4);

    first1->next=first2;
    first2->next=first3;
    first3->next=first4;
    first4->next=NULL;
    printLL(head);

    Node* solution = Mergesort(head);
    printLL(solution);


 


return 0;
}