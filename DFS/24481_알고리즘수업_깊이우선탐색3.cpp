#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001

int N, M, R;
vector<int> graph[MAX];
bool visited[MAX] = { false, };
int depth[MAX] = {-1, };
int depthCnt = 0;

void dfs (int R) {
    visited[R] = true;

    // 정점에 방문해서 할 작업 : depth 대입
    depth[R] = depthCnt;

    // 해당 정점에 연결된 정점들에 대해
    for (int i=0; i<graph[R].size(); i++) {
        int next = graph[R][i];
        if (!visited[next]) {
            depthCnt++; // 그 다음 방문할 정점의 depth는 한 단계 더 깊음
            dfs(next);
            depthCnt--; // 해당 정점에 방문하고 나서는 다시 depth를 원래대로
        }
    }
}

int main () {
    cin>>N>>M>>R;

    for (int i=0; i<M; i++) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=1; i<=N; i++) {
        sort(graph[i].begin(), graph[i].end()); // 오름차순 정렬
        /* 내림차순 - 기본, less<>
        오름차순 - greater<> */
        depth[i] = -1;
    }

    dfs(R);

    for (int i=1; i<=N; i++) cout<<depth[i]<<"\n";
}