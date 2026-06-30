#include<iostream>
#include<stack>
using namespace std;


void remove_any_index(stack<int>&input,int idx){
      stack<int>temp;
      int n=input.size();
      int count =0;
      if(input.size()==1){
        input.pop();
        return;
      }
    while(count<n-idx-1){
        count++;
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
remove_any_index(st,1);
// remove_any_index(st,2);

    

    while(not st.empty()){
        int curr=st.top();
        st.pop();
 
    cout<<curr<<endl;
       }
}