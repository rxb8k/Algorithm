#include <iostream>
#include <queue>
#include <functional>
using namespace std;

#define MAX_NODE 20000
#define INF 99999999

int dist[MAX_NODE+1];

void dijkstra(int start, vector<pair<int, int> > graph[]){
    priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;
    /* priority_queue는 기본적으로 첫번째 인자(거리)순으로 원소를 내림차순 정렬해 내보낸다.
    오름차순 정렬을 사용하기 위해 <greater>를 사용한다. */

    // 시작 정점 방문 처리. 시작점에서의 거리는 0
    dist[start]=0;
    pq.push(make_pair(0, start));

    while(!pq.empty()){
        int currNode=pq.top().second; // 현재 방문한 정점
        int currCost=pq.top().first; // 방문한 정점의 거리 값
        pq.pop();

        // 정점에 방문해서 할 작업

        // 해당 정점에 연결된 정점들에 대해
        for(int i=0;i<graph[currNode].size();i++){
            int nextNode=graph[currNode][i].first; // 조사할 다음 정점 설정
            int nextCost=currCost+graph[currNode][i].second; // 현재 정점을 거쳐 다음 정점을 갈 때의 비용

            if(nextCost<dist[nextNode]){ // nextNode까지 가기 위한 비용보다 방금 계산한 비용이 더 작을 경우
                dist[nextNode]=nextCost; // 최소 비용 갱신
                pq.push(make_pair(nextCost, nextNode)); // 우선순위 큐에 삽입
            }
        }
    }
}

int main(){
    int v, e; // 노드, 간선의 개수
    cin>>v>>e;

    int k; // 시작 정점의 번호
    cin>>k;

    // 가중치가 있는 그래프 생성
    vector<pair<int, int> > graph[v+1];
    for(int i=0;i<e;i++){
        int u, v, w; // 출발점, 도착점, 가중치
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v, w)); // u->v의 가중치는 w
        // graph[v].push_back(make_pair(u, w)); 
    }

    // distance 배열 초기화 -> 무한으로
    fill(dist, dist+v+1, INF);

    dijkstra(k, graph); // 다익스트라 알고리즘 실행

    for(int i=1;i<=v;i++){
        if(i==k) cout<<0<<'\n'; // 시작점은 0으로 출력
        else if(dist[i]==INF) cout<<"INF\n"; // 경로가 존재하지 않는 경우
        else cout<<dist[i]<<'\n';
    }
}