#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};

class Stack{
    Node*head;
    int capacity;
    int currSize;
    public:
    Stack(int c){
        this->capacity=c;
        this->currSize=0;
        head=NULL;
    }



    bool isEmpty(){
        return head==NULL;
    }

    bool isFull(){
        return currSize==capacity;
    }

   void push(int data){
    if(this->currSize==this->capacity){
        cout<<"Overflow";
        return ;
    }

    Node*new_node=new Node(data);
    new_node->next=head;
    head=new_node;
    currSize++;
   } 

   void pop(){
    if(head==NULL){
        cout<<"Underflow";
    }
    Node*new_head=head->next;
    head->next=NULL;
    delete head;
    head=new_head;
   }

   int size(){
    return currSize;
   }

   int getTop(){
     if(head==NULL){
        cout<<"Underflow";
    }
    return head->data;
   }

};


int main(){
Stack st(5);
st.push(1);
st.push(2);
cout<<st.getTop()<<"\n";
st.push(3);
st.push(4);
cout<<st.getTop()<<"\n";
st.push(5);
cout<<st.getTop()<<"\n";

st.pop();
st.pop();
cout<<"Poped elements are\n";
cout<<st.getTop()<<"\n";
return 0;
}
