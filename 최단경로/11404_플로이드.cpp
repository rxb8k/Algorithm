#include <iostream>
using namespace std;

#define INF 9999999

int main(){
    int n, m;
    cin>>n>>m;

    // 그래프 초기화 및 입력
    int adj[101][101];
    for(int i=0;i<101;i++){for(int j=0;j<101;j++) adj[i][j]=INF;}

    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(adj[a][b]==INF) adj[a][b]=c;
        else if(adj[a][b]!=INF && adj[a][b]>c) adj[a][b]=c; // 시작 도시와 도착 도시가 같은 노선이 있는 경우, 비용이 더 작은 것을 저장
    }

    for(int k=1;k<=n;k++){ // 경유지
        for(int i=1;i<=n;i++){ // 출발지
            for(int j=1;j<=n;j++){ // 도착지
                if(i!=j && j!=k && adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<(adj[i][j]==INF?0:adj[i][j])<<" ";
        }
        cout<<'\n';
    }
    
}