#include <iostream>
using namespace std;

int main () {
    int T;
    cin>>T;

    long long koong[69];
    for (int i=0; i<2; i++) koong[i] = 1;
    koong[2] = 2; koong[3] = 4;
    for (int i=4; i<69; i++) {
        koong[i] = koong[i-1] + koong[i-2] + koong[i-3] + koong[i-4];
    }

    while (T--) {
        int n;
        cin>>n;
        cout<<koong[n]<<'\n';
    }
}