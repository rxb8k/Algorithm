#include <iostream>
#include <algorithm>
using namespace std;

#define INF 9999999

int adj[101][101] = { 0, };
int kevinBacon[101] = {0, };

int main () {
    int N, M;
    cin>>N>>M;

    for (int i=0;i<101;i++) { for (int j=0;j<101;j++) adj[i][j]=INF; } // 연결되지 않은 상태로 초기화

    while (M--) {
        int a, b;
        cin>>a>>b;
        adj[a][b] = 1;
        adj[b][a] = 1; // 연결시켜줌
    }

    for (int k=1; k<=N; k++) { // 경유하는 친구
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (i!=j && j!=k && adj[i][j] > adj[i][k] + adj[k][j]) { // i와 j가 k에 의해 연결되어 있으면 (= INF 이상의 값이 나오지 않으면)
                    adj[i][j] = adj[i][k] + adj[k][j]; // 연결되어 있으므로 몇 단계만에 갈 수 있는지 계산해 저장함
                    adj[j][i] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    int min = INF;
    int minUser = 0;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cout<<adj[i][j]<<" ";
            if (adj[i][j] < INF) kevinBacon[i] += adj[i][j];
        }
        cout<<"kevinBacon: "<<kevinBacon[i]<<endl;
        if (kevinBacon[i] < min) {
            min = kevinBacon[i];
            minUser = i;
        }
    }

    cout<<minUser;
}