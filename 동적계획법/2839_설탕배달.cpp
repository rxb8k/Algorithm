#include <iostream>
using namespace std;

#define MAX 5001

int main () {
    int sugarBag[MAX];
    int N;
    cin>>N;

    for (int i=0; i<MAX; i++) { sugarBag[i] = -1; }

    sugarBag[3] = 1;
    sugarBag[5] = 1;
    sugarBag[6] = 2;

    for (int i=8; i<=N; i++) {
        if (sugarBag[i-3] == -1) {
            sugarBag[i] = sugarBag[i-5] + 1;
        } else if (sugarBag[i-5] == -1) {
            sugarBag[i] = sugarBag[i-3] + 1;
        } else {
            sugarBag[i] = min(sugarBag[i-3] + 1, sugarBag[i-5] + 1);
        }
    }
    
    cout<<sugarBag[N];
}