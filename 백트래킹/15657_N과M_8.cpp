#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int input[9];
int arr[9];

void backTracking (int depth, int start) {
    if (depth == M) {
        for (int i=0; i<M; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    else {
        for (int i=start; i<N; i++) {
            arr[depth] = input[i];
            backTracking(depth+1, i);
        }
    }
}

int main () {
    cin>>N>>M;
    for (int i=0; i<N; i++) {
        cin>>input[i];
    }
    sort(input, input+N);
    backTracking(0, 0);
}