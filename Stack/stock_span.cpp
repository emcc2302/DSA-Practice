#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int>prev_greatest_element(vector<int>&arr){
    int n=arr.size();
    reverse(arr.begin(),arr.end());
    vector<int> output(n,-1);
    stack<int>st;//indices stack not element
    st.push(0); // push the 0th indices
    for(int i=1;i<n;i++){
        while(!st.empty() and arr[i]>arr[st.top()]){ // we use while loop  here not if condition because we want to compare the current element with all other element
            output[st.top()]=n-i-1;
            st.pop();
        }
        st.push(i);
    }
    reverse(output.begin(),output.end());
    reverse(arr.begin(),arr.end());
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

    vector<int>res=prev_greatest_element(v);

    for(int i=0; i <res.size();i++){
        cout<<(i-res[i])<<" ";
    }
return 0;
}