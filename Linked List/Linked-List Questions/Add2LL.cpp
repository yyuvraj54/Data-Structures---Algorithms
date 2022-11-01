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

void insertAtTail(Node* &head ,Node* &tail,int data){
    Node* element=new Node(data);
    if(head==NULL){
        head=element;
        tail=element;
        return;
    }
    else{
        tail->next=element; 
        tail=element;
    } 

}
Node* Add2Number(Node* &first ,Node* &second){
    int sum=0;
    int carry=0;
    
    Node* head=NULL;
    Node* tail=NULL;

    while(first!=NULL && second!=NULL){

        int temp=first->data+second->data +carry;
        sum=temp%10;
        insertAtTail(head,tail,sum);
        carry=temp/10;
       
        first=first->next;
        second=second->next;
    }
    while(first!=NULL){
        int temp=first->data +carry;
        insertAtTail(head,tail,first->data);
        sum=temp%10;
        insertAtTail(head,tail,sum);
        carry=temp/10;

        first=first->next;
    }


    while(second!=NULL){
        int temp=second->data +carry;
        insertAtTail(head,tail,first->data);
        sum=temp%10;
        insertAtTail(head,tail,sum);
        carry=temp/10;
        second=second->next;
    }

    while(carry!=0){
        int temp=carry;
        sum=temp%10;
        insertAtTail(head,tail,sum);
        carry=sum/10;
    }
    return head;


}

Node* Reverse(Node* head){
    Node*  pre=NULL;
    Node*  curr=head;
    Node* forward=NULL;

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

    printLL(first1);
    printLL(second1);

    Node* firstLL=Reverse(first1);
    Node* secondLL=Reverse(second1);

    cout<<"--------"<<endl;
    Node* start=Add2Number(firstLL,secondLL);
    Node* ans =Reverse(start);

   

    printLL(ans);





    


    

    

    



    
    return 0;
}
