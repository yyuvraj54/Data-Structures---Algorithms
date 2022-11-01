#include<iostream>
using namespace std;
#include<map>


class Node{
    public:
    
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->random=NULL;
    }
};



void InsertAttail(Node * &head ,Node* &tail, int data){
    Node* newnode=new Node(data);
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        
        tail->next=newnode;
        tail=newnode;
    }

}

Node* cloneLL(Node* &head ){

    Node* temp=head;

    Node* start=NULL;
    Node* end=NULL;
    
    while(temp!=NULL){
        int data=temp->data;
        InsertAttail(start, end,data);
        temp=temp->next;

    }

    return start;

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

    Node* head=new Node(1);
    Node* n2=new Node(2);
    head->next=n2;
    
    Node* n3=new Node(3);
    n2->next=n3;
    Node* n4=new Node(4);
    n3->next=n4;

    Node* n5=new Node(5);
    n4->next=n5;
    n5->next=NULL;

    head->random=n3;
    n2->random=head;
    n3->random=n5;
    n4->random=n3;
    n5->random=n2;

    printLL(head);

    //Creating a new cloned linked list 
    map<Node* , Node*> maped ;
    map<Node*, Node*> :: iterator  itr;

    Node* Startnode=cloneLL(head);
    printLL(Startnode);

//mapping nodes 
    Node* orignalnode=head;
    Node* StartnodeAgain=Startnode;
    while(StartnodeAgain!=NULL){
        maped[orignalnode]=StartnodeAgain;

        orignalnode=orignalnode->next;
        StartnodeAgain=StartnodeAgain->next;
    }

// for(itr=maped.begin(); itr!=maped.end(); itr++ ){
//     cout<< itr->first<<"  "<<itr->second<<endl; 
// }

Node* orignalLL=head;
Node* StartnodeOnceAgain=Startnode;
while(StartnodeOnceAgain!=NULL){

    
    Node* linked=maped[orignalLL->random];
    StartnodeOnceAgain->random=linked;


    orignalLL=orignalLL->next;
    StartnodeOnceAgain=StartnodeOnceAgain->next;
}





// Testing of code

// Node* temp1=head;
// Node* temp2=Startnode;
// while(temp1!=NULL){
//     cout<<temp1->data<<" random -> "<<temp1->random->data<<endl;
//     temp1=temp1->next;
    
// }
// cout<<" ------- "<<endl;


// while(temp2!=NULL){
//     cout<<temp2->data<<" random -> "<<temp2->random->data<<endl;
//     temp2=temp2->next;
    
// }



    
    
    return 0;
}