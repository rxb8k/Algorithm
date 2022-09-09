#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nodeParent[100001]; // 각 노드의 부모를 저장할 배열

void dfs(int start, vector<int> graph[], bool check[]){
    check[start]=true; // 방문 표시

    // 해당 정점의 하위 정점 각각에 대해
    for(int i=0;i<graph[start].size();i++){
        int next=graph[start][i]; // 다음 정점 설정
        if(!check[next]){
            nodeParent[next]=start;
            /*
            다음 정점에 방문하지 않았을 때에 한해
            next 노드의 부모를 start로 설정한다.
            next가 이미 방문한 정점이라는 것은
            next 노드가 start 노드의 부모 노드이거나 (무방향 그래프이므로, 이럴 수도 있음)
            혹은 start와 아예 상관 없는 노드라는 이야기이다.
            따라서 next 노드에 방문하지 않았을 때, 즉 next 노드가 start의 자식 노드라는 것이 자명할 경우에만
            next 노드의 부모를 start로 설정해주어야 한다.
            */
            dfs(next, graph, check);
        } 
    }
}

int main(){
    int n;
    cin>>n;
    int m=n-1;

    vector<int> graph[n+1]; // 1. 그래프 생성
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 트리는 싸이클이 없는 무방향 그래프이므로, 무방향 그래프 생성
    }

    bool check[n+1]; // 2. 체크 리스트 생성
    fill(check, check+n+1, false);

    for(int i=1;i<=n;i++) {
        sort(graph[i].begin(), graph[i].end()); // 3. 정렬
        nodeParent[i]=0;
    }

    // 4. dfs 수행
    dfs(1, graph, check);

    // 결과 출력
    for(int i=2;i<=n;i++) cout<<nodeParent[i]<<'\n';
}