#include <iostream>
using namespace std;

int main() {
    int rows = 6;
    int first = 1;
    int diff = 1;
    int count = 0;
   int  width = 6;

    for (int i = 1; i <= rows; ++i) {
     
        cout << string((rows - i) * width, ' ');
        int num = first;
        for (int j = 0; j < i; ++j) {
            cout << num;

            int len = to_string(num).length();
            cout << string(width - len, ' ');

            num += 2;
        }

        first += diff;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
        if (++count == 2) {
            diff += 2;
            count = 0;
        }

        cout << '\n';
    }

    return 0;
}