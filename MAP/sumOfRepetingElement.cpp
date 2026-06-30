// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     vector<int>arr={1,1,2,1,3,3,3};
//     vector<int>res;
//     map<int,int>mp;
//     for(int i=0;i<7;i++){
//         mp[arr[i]]++;
//     }
//     for(auto itr:mp){
//         if(itr.second>=2){
//             res.push_back(itr.first);
//         }
//     }
//     int sum=0;
//     for(int i=0;i<res.size();i++){
//         sum+=res[i];
//     }

//     cout<<sum<<endl;
// return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 1, 2, 1, 3, 3, 3};
    vector<int> res;
    map<int, int> mp;

    // Counting occurrences of each element
    for (int i = 0; i < (int)arr.size(); i++) {  // Fixed: used arr.size() instead of 7
        mp[arr[i]]++;
    }

    // Storing elements that appear at least twice
    for (auto itr : mp) {
        if (itr.second >= 2) {  
            res.push_back(itr.first);
        }
    }

    // Calculating sum
    int sum = accumulate(res.begin(), res.end(), 0); // Cleaner sum computation

    cout << sum << endl;
    return 0;
}
