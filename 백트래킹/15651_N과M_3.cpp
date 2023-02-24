#include <iostream>
using namespace std;

int N, M;
int arr[8];

void backTracking (int depth) {
    if (depth == M) {
        for (int i=0; i<M; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    else { // 아직 출력할 배열이 만들어지지 않았으면
        for (int i=1; i<=N; i++) { // 전체 수를 돌면서
            arr[depth] = i; // 수를 현재 위치에 넣음
            backTracking(++depth); // depth 1 증가시키고 백트래킹 또 돌림
            depth--; // 재귀하고 돌아와서는 depth 다시 원래대로
        }
    }
}

int main () {
    cin>>N>>M;
    backTracking(0);
}