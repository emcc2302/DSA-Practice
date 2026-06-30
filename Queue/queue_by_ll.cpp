#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

Node(int data){
    this->data=data;
    this->next=NULL;
}
};

class Queue{
    Node*head;
    Node*tail;
    int size;
    public:
    Queue(){
        head=NULL;
        tail=NULL;
        size=0;
    }




    void enqueue(int data){
        Node*newnode=new Node(data);
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        size++;

    }


    void dequeue(){
        if(head==NULL){
            return ;
        }

        else{
            Node*oldhead=head;
            Node*newhead=head->next;
            head=newhead;

            if(head==NULL) tail=NULL;
            oldhead->next=NULL;
            delete oldhead;
            size--;
        }
    }


    int getSize(){
        return size;
    }

    bool isEmpty(){
        return head==NULL;
    }

    int front(){
        if(head==NULL)
            return -1;
        
        return head->data;
    }
};



int main()
{
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);
    qu.dequeue();
    qu.enqueue(50);
    qu.enqueue(60);
    while(!qu.isEmpty()){
        cout<<qu.front()<<" ";
        qu.dequeue();
    }
return 0;
}