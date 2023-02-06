#include <iostream>
using namespace std;

int N, M;
int arr[9];
bool visited[9] = {false, };

void backTracking (int depth) {
    if (depth == M) { // arr 배열이 완성되었으면 출력
        for (int i=0; i<M; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
    } 
    else { // arr 배열이 아직 완성되지 않았으면
        for (int i=1; i<=N; i++) { // 전체 수를 돌며 방문했나 검사하고 방문
            if (depth==0) {
                if (!visited[i]) {
                    visited[i] = true;
                    arr[depth] = i;
                    backTracking(depth + 1);
                    visited[i] = false;
                }
            }
            if (depth>0) {
                if (!visited[i] && arr[depth-1]<i) {
                    visited[i] = true;
                    arr[depth] = i;
                    backTracking(depth + 1);
                    visited[i] = false;
                }
            }
        }
    }
}

int main () {
    cin>>N>>M;
    backTracking(0);
}