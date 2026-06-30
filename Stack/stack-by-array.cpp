#include<iostream>
using namespace std;

class Stack{
    int size;
    int *arr;
    int top;
    public:
        Stack(int c){
            this->size=c;
            arr=new int[c];
            this->top=-1;
        }


void push(int data){
    if(top == size-1){
        cout<<"Overflow\n";
        return ;
    }
        top++;
    arr[top]=data;
}


void pop(){
    if(top==-1){
        cout<<"Underflow\n";
        return ;
    }
    top--;
}

int getTop(){
    if(top==-1){
        cout<<"Undrflow";
        return INT_MIN;
    }
    return arr[top];
}

bool isEmpty(){
    return top==-1;
}

int Stacksize()
{
    return top+1;
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