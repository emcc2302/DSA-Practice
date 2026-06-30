#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a Number: ";
    cin >> n;

    int original = n;
    int sum = 0;

    while(n > 0) {
        int digit = n % 10;
        sum = sum + (digit * digit * digit);
        n = n / 10;
    }

    if(sum == original)
        cout << original << " is an Armstrong Number";
    else
        cout << original << " is not an Armstrong Number";

    return 0;
}