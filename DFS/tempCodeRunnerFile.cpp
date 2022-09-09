#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nodeParent[100001]; // 각 노드의 부모를 저장할 배열

void dfs(int start, vector<int> graph[], bool check[]){
    check[start]=true; // 방문 표시

    // 방문해서 수행할 작업

    // 해당 정점의 하위 정점 각각에 대해
    for(int i=0;i<graph[start].size();i++){
        int next=graph[start][i]; // 다음 정점 설정
        if(!check[next]){
            nodeParent[next]=start;
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
        graph[v].push_back(u);
    }

    bool check[n+1]; // 2. 체크 리스트 생성
    fill(check, check+n+1, false);

    for(int i=1;i<=n;i++) {
        sort(graph[i].begin(), graph[i].end()); // 3. 정렬
        nodeParent[i]=0;
    }
    cout<<endl;

    // 4. dfs 수행
    dfs(1, graph, check);

    cout<<endl;

    // 결과 출력
    for(int i=2;i<=n;i++) cout<<nodeParent[i]<<'\n';
}