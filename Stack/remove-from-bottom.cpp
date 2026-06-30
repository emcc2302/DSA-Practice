#include<iostream>
#include<stack>
using namespace std;


void remove_bottom(stack<int>&input){
      stack<int>temp;
      if(input.size()==1){
        input.pop();
        return;
      }
    while(input.size()!=1){
        int curr=input.top();
        input.pop();
         temp.push(curr);
    }
    input.pop();

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
    remove_bottom(st);
    remove_bottom(st);

    

    while(not st.empty()){
        int curr=st.top();
        st.pop();
 
    cout<<curr<<endl;
       }
}