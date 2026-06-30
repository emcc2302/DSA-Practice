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

Node* reverse_linked_list(Node*&head){
    Node*pre=NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node*newptr=curr->next;
        curr->next=pre;
        pre=curr;
        curr=newptr;
    }
    return pre;
}

void display(Node*&head){
    Node*temp=head;  
 while(temp!=NULL){
    cout<<temp->data<<"-> ";
    temp=temp->next;
 }
 cout<<"NULL"<<endl;
}

int main(){
Node*head=NULL;
insert(head,3);
display(head);
insert(head,2);
display(head);
insert(head,1);
display(head);
cout<<endl;
head=reverse_linked_list(head);
cout << "Reversed Linked List:" << endl;

display(head);
}