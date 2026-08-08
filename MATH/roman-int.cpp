#include <iostream>
#include <string>

using namespace std;

// Helper function to return the value of each Roman character
int getRomanValue(char r) {
    if (r == 'I') return 1;
    if (r == 'V') return 5;
    if (r == 'X') return 10;
    if (r == 'L') return 50;
    if (r == 'C') return 100;
    if (r == 'D') return 500;
    if (r == 'M') return 1000;
    return 0;
}

int romanToInt(string s) {
    int total=0;

    for(int i=0;i<s.size();i++){
        int curr = getRomanValue(s[i]);

        int next =(i+1<s.size())?getRomanValue(s[i+1]) : 0;

        if(curr<next){
            total=total+(next-curr);
            i++;
        }
        else{
            total+=curr;
        }
    }

    return total;
}

int main() {
    string roman = "MCMXCIV"; // 1994
    
    cout << "Roman Numeral: " << roman << endl;
    cout << "Integer Value: " << romanToInt(roman) << endl; // Output: 1994
    
    return 0;
}