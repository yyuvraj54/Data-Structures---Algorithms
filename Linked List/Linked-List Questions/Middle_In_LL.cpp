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

int MiddleElement(Node* head){
    
    int counter=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        counter++;
    }
    cout<<counter<<endl;
    
    int index=0;
    if(counter%2==0){
        index=(counter/2)+1;
    }
    else{
        index=counter/2;
        
    }
    cout<<"Middle index is :"<<index<<endl;



    Node* temp2=head;
    int pos=0;
    while(pos<=index){
        temp2=temp2->next;
        pos++;
    }
    return temp2->data;



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
    //n5->next=NULL;
    Node* n6=new Node(30);
    n5->next=n6;
    n6->next=NULL;
    printLL(head);
    
    MiddleElement(head);



    
    return 0;
}
