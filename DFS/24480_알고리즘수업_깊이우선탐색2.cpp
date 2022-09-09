#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int visitedOrder[100001]; // 각 정점의 방문 순서를 저장할 배열
int visitCount=0; // 방문 순서 카운트

void dfs(int start, vector<int> graph[], bool check[]){
    // dfs 함수에 들어오면 방문 완료로 판단
    check[start]=true; // 시작 정점 방문 완료

    // 정점에 방문해서 할 작업 수행
    visitCount++;
    visitedOrder[start]=visitCount;

    // 해당 정점에 연결된 정점들에 대해
    for(int i=0;i<graph[start].size();i++){
        int next=graph[start][i]; // 탐색할 다음 정점 설정
        if(!check[next]) dfs(next, graph, check); // 위에서 설정한 다음 정점에 방문하지 않았다면, 그 정점에 대해 다시 dfs
    }
}

int main(){
    int n, m, r;
    cin>>n>>m>>r;

    // 1. 양방향 그래프 생성, 가중치 1
    vector<int> graph[n+1];
    for(int i=0;i<m;i++){ // 간선의 수만큼
        int u, v;
        cin>>u>>v; // 간선 정보를 입력 받음
        graph[u].push_back(v); // 해당 정점(u)에 연결된 정점들(v)을 추가
        graph[v].push_back(u); // 양방향 그래프
    }

    // 2. Check 리스트 생성
    bool check[n+1];
    fill(check, check+n+1, false);
    
    // 3. 그래프 내 정점을 오름차순으로 정렬
    for(int i=1; i<=n; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
        visitedOrder[i]=0; // 방문 순서 배열 0으로 초기화
    }

    // 4. DFS와 BFS 수행
    dfs(r, graph, check);

    // 결과 출력
    for(int i=1;i<=n;i++) cout<<visitedOrder[i]<<'\n';
}