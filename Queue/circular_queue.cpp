#include<iostream>
#include<vector>
using namespace std;

class Queue{
    int front;
    int back;
    vector<int>v;
    int curr_size;
    int total_size;
    public:
    Queue(int n){
        v.resize(n);
        this->total_size=n;
        this->back=n-1;
        this->front=0;
        this->curr_size=0;
    }

    void enqueue(int data ){
        if(isFull()) return ;
      back=(back+1)%total_size;
      v[back]=data;
      curr_size++;
    }


    void dequeue(){
       if(isEmpty()) return;
       front=(front+1)%total_size;
       curr_size--;
    }

    int getFront(){
        if(front==-1) return -1;
        return v[front];
    }

    bool isEmpty(){
        return curr_size==0;
    }

    bool isFull(){
        return curr_size==total_size;
    }
};


int main()
{
    Queue qu(4);
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);
    qu.dequeue();
    qu.dequeue(); 
    qu.dequeue();
    qu.enqueue(50);
    qu.enqueue(60);
    while(!qu.isEmpty()){
        cout<<qu.getFront()<<" ";
        qu.dequeue();
    }
return 0;
}