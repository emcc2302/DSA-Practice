//we will do this question by recursion stack based operation
//for ex 1->2->3->4
//in the stack 1(bottom),2,3,4(top)
//output=4->3->2->1

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

void insert(Node*&head,int data){
Node*newnode=new Node(data);
newnode->next=head;
head=newnode;

}

void display(Node*&head){
    Node*temp=head;  
 while(temp!=NULL){
    cout<<temp->data<<"-> ";
    temp=temp->next;
 }
 cout<<"NULL"<<endl;
}

void reverse_print(Node*head){
    if(head==NULL)
    {
        return;
    }
    reverse_print(head->next);
    cout<<head->data<<" ";
}

int main(){
Node*head=NULL;
insert(head,3);
display(head);
insert(head,2);
display(head);
insert(head,1);
display(head);
reverse_print(head);

}