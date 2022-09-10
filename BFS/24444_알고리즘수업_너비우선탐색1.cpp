#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 방문 순서를 저장할 배열 및 카운트
int visitedOrder[100001];
int visitCount=0;

void bfs(int start, vector<int> graph[], bool check[]){
    // 이번 탐색에서 방문할 정점들을 저장하는 큐
    queue<int> q; 

    // 시작 정점 방문 처리
    q.push(start);
    check[start]=true;

    while(!q.empty()){ // 방문할 정점들에 대해 아래 반복
        int temp=q.front(); // 탐색할 정점
        q.pop();

        // 정점에 방문해서 할 작업
        visitCount++;
        visitedOrder[temp]=visitCount;

        // 해당 정점에 연결된 정점들에 대해
        for(int i=0;i<graph[temp].size();i++){
            int next=graph[temp][i]; // 다음 정점 설정

            if(!check[next]){ // 방문하지 않았다면 큐에 넣어주고, 방문 표시
                q.push(next);
                check[next]=true;
                
                // 재귀 없음
            }
        }
    }    
}

int main(){
    int n, m, r;
    cin>>n>>m>>r;
    
    vector<int> graph[n+1];
    bool check[n+1];

    // 1. 그래프 생성
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 양방향
    }

    // 2. 체크 리스트 생성, 방문 순서 배열 초기화
    fill(check, check+n+1, false);
    fill(visitedOrder, visitedOrder+n+1, 0);
    
    // 3. 오름차순 정렬
    for(int i=1;i<=n;i++) sort(graph[i].begin(), graph[i].end());

    // 4. BFS on
    bfs(r, graph, check);

    // 결과 출력
    for(int i=1;i<=n;i++) cout<<visitedOrder[i]<<'\n';
}