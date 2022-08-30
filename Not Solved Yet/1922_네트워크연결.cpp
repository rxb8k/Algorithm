#include <iostream>
using namespace std;

int main(){
    int n, m;
    int a, b, c; // 노드1, 노드2, 가중치
    scanf("%d %d", &n, &m);

    // 인접 행렬로 그래프 표현
    int graph[1001][1001];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            graph[i][j]=9999; // 연결되지 않은 상태로 초기화
        }
    }

    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        graph[a][b]=c;
    }

    

    cout<<"출력 확인\n";

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<graph[i][j]<< " ";
        }
        cout<<endl;
    }
}