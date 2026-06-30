#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>next_greatest_element(vector<int>&arr){
    int n=arr.size();
    vector<int> output(n,-1);
    stack<int>st;//indices stack not element
    st.push(0); // push the 0th indices
    for(int i=1;i<n;i++){
        while(!st.empty() and arr[i]>arr[st.top()]){ // we use while loop  here not if condition because we want to compare the current element with all other element
            output[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    return output;
}


int main()
{
   int n;
    cin>>n;
    vector<int >v;
    while(n--){
        int x;
        cin>>x;
        v.push_back(x);

    }

    vector<int>res=next_greatest_element(v);

    for(int i=0; i <res.size();i++){
        cout<<res[i]<<" ";
    }
return 0;
}