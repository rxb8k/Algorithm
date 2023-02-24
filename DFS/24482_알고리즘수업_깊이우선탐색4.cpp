#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

#define MAX 100001
int N, M, R;
vector<int> graph[MAX];
bool visited[MAX] = {false, };
int depth[MAX] = {-1, };

void dfs (int start, int currDepth) {
    visited[start] = true;

    // 정점에 방문해서 할 작업
    depth[start] = currDepth;

    for (int i=0; i<graph[start].size(); i++) {
        int next = graph[start][i];
        if (!visited[next]) {
            dfs(next, currDepth+1);
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
        sort(graph[i].begin(), graph[i].end(), greater<int>()); // 정점 내림차순 정렬
        depth[i] = -1;
    }

    dfs(R, 0);

    for (int i=1; i<=N; i++) cout<<depth[i]<<'\n';
}