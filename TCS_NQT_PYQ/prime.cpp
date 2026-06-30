#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a Number: ";
    cin >> n;

    bool isPrime = true;

    if(n <= 1) {
        isPrime = false;
    }
    else {
        for(int i = 2; i <= n / 2; i++) {
            if(n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if(isPrime)
        cout << "Prime Number";
    else
        cout << "Not a Prime Number";

    return 0;
}