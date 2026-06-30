#include<iostream>
#include<stack>
using namespace std;


void insert_bottom(stack<int>&input,int x){
      stack<int>temp;
    while(not input.empty()){
        int curr=input.top();
        input.pop();
         temp.push(curr);
    }
    input.push(x);

while(not temp.empty()){
   int curr=temp.top();
   temp.pop();
   input.push(curr);
}

}

int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
insert_bottom(st,100);
insert_bottom(st,200);

    

    while(not st.empty()){
        int curr=st.top();
        st.pop();
 
    cout<<curr<<endl;
       }
}