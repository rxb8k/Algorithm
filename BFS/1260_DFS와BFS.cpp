#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(int start, vector<int> graph[], bool check[]){
    // dfs 함수에 들어오면 방문 완료로 판단한다.
     // 시작 정점 탐색 완료
    check[start]=true;

    // 정점에 방문해서 할 작업
    cout<<start<<" ";

    // 해당 정점에 연결된 정점들에 대해
    for(int i=0; i<graph[start].size(); i++){ 
        // 탐색할 다음 정점은 graph[start] 하위 정점들
        int next=graph[start][i];

        // 해당 하위 정점에 방문하지 않았다면 재귀로 다시 해당 정점에 대해 DFS on
        if(!check[next]) dfs(next, graph, check); 
    }
}

void bfs(int start, vector<int> graph[], bool check[]){
    // 방문할 정점을 넣어두는 큐 (FIFO)
    queue<int> q;

    // 시작 정점 방문 완료
    q.push(start);
    check[start]=true;

    while(!q.empty()){
        // 탐색할 정점, 즉 큐의 맨 앞에 있는 정점을 빼고 이를 'temp'로 설정
        int temp=q.front();
        q.pop();

        // 정점에 방문해서 할 작업
        cout<<temp<<" ";

        // 해당 정점에 연결된 정점들에 대해
        for(int i=0;i<graph[temp].size(); i++){
            // 탐색할 다음 정점은 graph[temp] 하위 정점들
            int next=graph[temp][i];

            // 해당 하위 정점에 방문하지 않았다면 큐에 넣어주고, 방문했음을 표시
            if(!check[next]){
                q.push(next);
                check[next]=true;
            }
        }
    }
}


int main(){
    int n, m, v;
    cin>>n>>m>>v;

    // 1. 무방향 그래프 생성
    vector<int> graph[n+1];
    for(int i=0;i<m;i++){ // 간선의 개수만큼
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v); // 해당 정점(u)에 연결된 정점들(v)을 추가
        graph[v].push_back(u); // 양방향 그래프일 경우에만 작성
    }

    // 2. Check 리스트 생성
    // Check list는 별도의 구조를 가질 필요는 없으며, 그냥 각 정점에 대한 방문 여부를 저장하도록 하면 된다.
    bool check[n+1];
	fill(check, check+n+1, false);

    // 3. 그래프 내 정점 정렬 -> 탐색 시 정점에 순차적으로 접근하기 위해
    for(int i=1; i<=n; i++) sort(graph[i].begin(), graph[i].end());

    // 4. DFS와 BFS 수행
    dfs(v, graph, check);
    cout<<"\n";
	fill(check, check+n+1, false);
	bfs(v, graph, check);
}