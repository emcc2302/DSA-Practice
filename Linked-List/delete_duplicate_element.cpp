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

void delete_duplicate(Node*&head){
    Node*current_node=head;
    while(current_node !=NULL){
        while(current_node->next!=NULL && current_node->data==current_node->next->data  ){
            Node*temp=current_node->next;
            current_node->next=current_node->next->next;
            free(temp);
        }
        current_node=current_node->next;
    }
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
    insert_last(head,4);
    display(head);
     insert_last(head,4);
    display(head);
     insert_last(head,2);
    display(head);
     insert_last(head,1);
    display(head);

    delete_duplicate(head);
    display(head);    
}