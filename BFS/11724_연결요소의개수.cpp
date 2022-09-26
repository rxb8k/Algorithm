#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
bool visitied[1001];

void bfs(int start){
    queue<int> q;

    q.push(start);
    visitied[start]=true;

    while(!q.empty()){
        int temp=q.front();
        q.pop();

        for(int i=0;i<graph[temp].size();i++){
            int next=graph[temp][i];

            if(!visitied[next]){
                q.push(next);
                visitied[next]=true;
            }
        }
    }
}

int main(){
    int N, M;
    int connected_component=0;

    cin>>N>>M;

    for(int i=0;i<M;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 무방향 그래프
    }

    fill(visitied, visitied+N+1, false);

    for(int i=1; i<=N; i++) sort(graph[i].begin(), graph[i].end());

    for(int i=1; i<=N; i++){
        if(!visitied[i]) {
            bfs(i);
            connected_component++;
            /*
            모든 정점을 돌며, 방문하지 않았다고 되어 있는 정점이 있다면
            해당 정점을 시작점으로 하여 bfs를 수행하고 연결 요소의 개수를 1 증가시킨다.
            bfs를 한 번 수행함으로써 시작점과 연결된 정점들은 모두 방문 처리가 완료되기 때문이다.
            따라서 방문하지 않은 정점은 이전까지의 탐색에서 발견되지 않은, 새로운 연결 요소에 해당하는 정점이다.
            */
        }
    }
    cout<<connected_component;
}