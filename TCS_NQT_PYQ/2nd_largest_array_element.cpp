#include<iostream>
using namespace std;

int main (){
    int n;
    cout <<"Enter Array Size : ";
    cin>>n;
    int array [n];

    cout<<"Enter Array Elements : ";

    for(int i=0;i<n;i++)
    {
        cin >> array[i];
    }


    int largest =array[0];
    int second_largest=-1;

    for(int i=1;i<n;i++){
        if (array[i]>largest)
        {
            second_largest=largest;
            largest=array[i];
        }
        else if(array[i]>second_largest && array[i]!=largest){
            second_largest=array[i];
        }
        
    }
    cout << "Second Largest Element = " << second_largest << endl;
    return 0;
}