#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    cout<<"Enter the value of m:"<<endl;
    cin>>m;

    vector<int>v1(n); // 1 1 2 2 3
    vector<int>v2(m); // 6 5 1 2 3 7 common elements are 1,2,3 so ans_sum=6

    for(int i=0;i<n;i++){
        cin>>v1[i];
    }

    for(int i=0;i<m;i++){
        cin>>v2[i];
    }

    int ans_sum=0;

    set<int>s1;

    for(auto ele: v1){
        s1.insert(ele);
    }

    for(auto ele:v2){
        if(s1.find(ele)!=s1.end()){
            ans_sum+=ele;
        }
    }

    cout<<"Ans: "<<ans_sum<<endl;

return 0;
}