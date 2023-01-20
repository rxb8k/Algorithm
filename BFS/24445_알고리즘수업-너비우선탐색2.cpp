#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001

int N, M, R;
bool visited[MAX] = { false, };
int order[MAX] = {0, };

int main () {
    int orderCount = 0;
    cin>>N>>M>>R;

    // 그래프 생성
    vector<int> graph[N+1];
    for (int i=0; i<M; i++) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 그래프 내 정점 내림차순 정렬
    for (int i=1; i<=N; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<int> ());
    }

    // BFS
    queue<int> q;

    q.push(R);
    visited[R] = true;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        // 정점에 방문해서 할 작업
        order[curr] = ++orderCount;
        
        for (int i=0; i<graph[curr].size(); i++) {
            int next = graph[curr][i];
            
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }

    // 결과 출력
    for (int i=1; i<=N; i++) {
        printf("%d\n", order[i]);
    }
}