#include<iostream>
using namespace std;

int main() {
    string word; cin >> word;
    string result = "";

    for(char letter :word){
        if(result.find(letter)==string::npos){
            result+=letter;
        }
    }
    cout<<result<<endl;
    return 0;
}