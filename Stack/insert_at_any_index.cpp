#include<iostream>
#include<stack>
using namespace std;


void insert_any_index(stack<int>&input,int x,int idx){
      stack<int>temp;
      int n=input.size();
      int count =0;
    while(count<n-idx){
        count++;
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
insert_any_index(st,100,1);
insert_any_index(st,200,2);

    

    while(not st.empty()){
        int curr=st.top();
        st.pop();
 
    cout<<curr<<endl;
       }
}