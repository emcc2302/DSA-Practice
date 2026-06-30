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

void insert_last(Node*& head, int data) {
    Node* newnode = new Node(data);

    if (head == NULL) {  // Special case: Empty list
        head = newnode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {  // Traverse to the end of the list
        temp = temp->next;
    }
    temp->next = newnode;  // Add the new node at the end
}



Node* reverse_kth_ll(Node*&head,int k){
    Node*prevptr=NULL;
    Node*currptr=head;
    int counter=0;

    while(currptr!=NULL && counter<k){
        Node*nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        counter++;
    }

if(currptr!=NULL){
    Node*newhead=reverse_kth_ll(currptr,k);
    head->next=newhead;
}
return prevptr;

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
Node*head=NULL;
insert_last(head,1);
  display(head);
  insert_last(head,2);
  display(head);
  insert_last(head,3);
  display(head);
  insert_last(head,4);
  display(head);
   insert_last(head,5);
  display(head);
   insert_last(head,6);
  display(head);

  head=reverse_kth_ll(head,3);
  display(head);
}