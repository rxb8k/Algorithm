#include <iostream>
using namespace std;

int N, M;
int arr[9];
bool visited[9] = {false, };

void dfs (int depth) {
    if (depth == M) { // 길이가 M인 배열이 완성되었으면 출력
        for (int i=0; i<M; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
    }
    else { // 완성되지 않았으면
        for (int i=1; i<=N; i++) { // 전체 수를 돌면서
            if (!visited[i]) { // 방문하지 않았으면 방문
                visited[i] = true;
                arr[depth] = i; // arr 배열에 넣음
                dfs(depth + 1); // 그 다음 depth의 원소를 다시 DFS로 탐색
                visited[i] = false; 
                /*
                 다음 depth 원소를 찾고 돌아와서,
                 기존 위치의 방문 여부를 다시 초기화한다.
                 어차피 돌아올 땐 이미 arr 출력이 다 완료된 후이다.
                 초기화해주지 않으면 '1 2 3 4'와 같이
                 최초 1회만 탐색이 진행되고 끝난다.
                */
            }
        }
    }
}

int main () {
    cin>>N>>M;
    dfs(0);
}