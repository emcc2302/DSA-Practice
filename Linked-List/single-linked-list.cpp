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

void insert_begining(Node* &head,int data){                  //pass by reference because we want to change the linked list
Node*newnode=new Node(data);
newnode->next=head;
head=newnode;
}

void insert_last(Node*&head,int data){
    Node*newnode=new Node(data);
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
     temp->next=newnode;
        // newnode->next=NULL;    no need to write this ,because in the constractor next always point to next
}

void insert_At_Any_Position(Node*&head,int data,int pos){
    Node*newnode=new Node(data);
    if(pos==0){
        insert_begining(head,data);
        return;
    }

    Node*temp=head;
    int curr_pos=0;
    while(curr_pos!=pos-1){
        temp=temp->next;
        curr_pos++;
    }
    newnode->next=temp->next;
    temp->next=newnode; //because we traverse to (position - 1) that is temp ,so temp -> next will be the position ,so temp->next =newnode no temp=newnode
}

void delete_begining(Node*&head){
    Node*temp=head;
    head=head->next;
    free(temp);
}


void delete_last(Node*&head){
    Node*second_last=head;
    while(second_last->next->next!=NULL){
        second_last=second_last->next;
    }
    Node*temp=second_last->next;
    second_last->next=NULL;
    free(temp);
}

void delete_any_position(Node*&head,int pos){
     if(pos==0){
         delete_begining(head);
        return;
    }
    Node*pre_pos=head;
    int curr_pos=0;
    while(curr_pos!=pos-1)
    {
        pre_pos=pre_pos->next;
        curr_pos++;
    }
    Node*temp=pre_pos->next;
    pre_pos->next=pre_pos->next->next;
    free(temp);
}

void display(Node*head){                                    //pass by value ,because we don't want to chane the linked list,just print it
 Node*temp=head;  // for traversing the ll we need a temp variable pointing to head,because if we change head we may loss the ll
 while(temp!=NULL){
    cout<<temp->data<<"-> ";
    temp=temp->next;
 }
 cout<<"NULL"<<endl;
 
              
}

int main(){
Node* head=NULL;
 insert_begining(head,3);
 display(head);
 insert_begining(head,2);
 display(head);
 insert_begining(head,1);
 display(head);
 insert_last(head,4);
  display(head);
  insert_At_Any_Position(head,5,4);
  display(head);
  delete_begining(head);
  display(head);
   delete_last(head);
   display(head);
   delete_any_position(head,2);
   display(head);
}


