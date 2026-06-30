#include<iostream>
#include<vector>
using namespace std;

class Queue{
    int front;
    int back;
    vector<int>v;
    public:
    Queue(){
        this->back=-1;
        this->front=-1;
    }

    void enqueue(int data ){
        v.push_back(data);
        back++;
        if(back==0) front=0;
    }


    void dequeue(){
        if(front==back){
            front=-1;
            back=-1;
            v.clear();
        }
        else{
            front++;
        }
    }

    int getFront(){
        if(front==-1) return -1;
        return v[front];
    }

    bool isEmpty(){
        return front==-1;
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
        cout<<qu.getFront()<<" ";
        qu.dequeue();
    }
return 0;
}