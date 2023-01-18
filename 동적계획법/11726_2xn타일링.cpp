#include <iostream>
using namespace std;

int main () {
    int n;
    cin>>n;

    long long dpTable[1001];
    int remainder[1001];
    dpTable[1] = 1;
    dpTable[2] = 2;
    remainder[1] = 1;
    remainder[2] = 2;

    for (int i=3; i<=1000; i++) {
        dpTable[i] = dpTable[i-1] + dpTable[i-2];
        remainder[i] = (remainder[i-1] + remainder[i-2]) % 10007;
    }

    cout<<remainder[n];
}