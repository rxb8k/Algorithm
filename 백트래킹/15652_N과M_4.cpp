#include <iostream>
using namespace std;

int N, M;
int arr[9];

void backTracking (int depth) {
    if (depth == M) {
        for (int i=0; i<M; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
    }
    else {
        for (int i=1; i<=N; i++) {
            if (depth >= 1 && i<arr[depth-1]) continue; // depth가 1 이상인데, 넣으려는 수가 이전 원소보다 작으면 Pass
            arr[depth] = i;
            backTracking(++depth);
            depth--;
        }
    }
}

int main () {
    cin>>N>>M;
    backTracking(0);
}