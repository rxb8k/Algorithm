#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[9];
int arr[9];
bool visited[10001];

void backTracking (int depth) {
    if (depth == M) {
        for (int i=0; i<M; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
    }
    else {
        for (int i=0; i<N; i++) {
            int next = num[i];

            if (!visited[next]) {
                visited[next] = true;
                arr[depth] = next;
                backTracking(depth+1);
                visited[next] = false;
            }
        }
    }
}

int main () {
    cin>>N>>M;
    for (int i=0; i<N; i++) {
        cin>>num[i];
    }
    sort(num, num+N); // 오름차순 정렬
    backTracking(0);
}