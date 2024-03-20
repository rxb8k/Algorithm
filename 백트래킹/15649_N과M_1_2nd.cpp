#include <iostream>
using namespace std;

int N, M;
int arr[9] = {0, };
int visited[9] = {0, }; // 중복 처리를 위한 방문 체크 필요

void backTrakcing (int depth) {
    if (depth == M) { // stop
        for (int i=0; i<M; i++) { 
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
        
    }
    else {
        for (int i=1; i<=N; i++) {
            if (visited[i] == false) { // 방문하지 않은 원소일 때에만
                arr[depth] = i;
                visited[i] = true; 
                backTrakcing(depth+1);
                /* 
                visited 배열 초기화가 진행되는 시점은
                재귀가 계속 진행되어 depth==M까지 가고,
                배열 출력까지 진행된 뒤임
                */
                visited[i] = false;
            }
        }
    }
}

int main () {
    cin>>N>>M;
    backTrakcing(0);
}