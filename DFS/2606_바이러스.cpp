#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned int answer=0;

void dfs(int start, vector<int> graph[], bool check[]){
    // DFS에 들어왔으면 방문했다고 간주
    check[start]=true;

    // 방문해서 할 작업
    answer++;

    // 해당 정점에 연결된 정점들에 대해
    for(int i=0;i<graph[start].size();i++){
        // 탐색할 다음 정점
        int next=graph[start][i];

        // 방문 안 했으면 DFS on
        if(!check[next]) dfs(next, graph, check);
    }
}

int main(){
    int n, m; // 노드, 간선
    cin>>n>>m;

    // 1. 그래프 생성 : 양방향 그래프
    vector<int> graph[n+1];
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 2. Check 배열 생성
    bool check[n+1];
    fill(check, check+n+1, false);

    // 3. 정렬 패스

    // 4. DFS 수행
    dfs(1, graph, check);
    cout<<answer-1; // 1번 컴퓨터는 제외
}