#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

#define MAX 501

int n, m; // 세로, 가로 길이
bool paper[MAX][MAX]={false, };
bool visitied[MAX][MAX]={false, };
int picSize[MAX*MAX]={0, }; // 그림 크기

// 4방향 탐색에 사용할 좌표 이동용 배열 (좌, 하, 우, 상)
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};


void dfs(int x, int y, int picId){
    visitied[x][y]=true; // x가 세로 y가 가로

    // cout<<x<<", "<<y<<" picId: "<<picId<<endl;

    for(int i=0;i<4;i++){ // 4방향 탐색을 통해 다음 정점 설정
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(0<=nx && nx<n && 0<=ny && ny<m){
            // 다음 위치가 그림이면서 && 방문하지 않았다면 DFS 재귀 호출 통해 방문
            if(paper[nx][ny]==1 && !visitied[nx][ny]){
                picSize[picId]++; // 해당 정점이 그림이라면 해당 그림의 그림 크기 1 증가
                dfs(nx, ny, picId); // 현재 정점과 연결된 정점이므로, 같은 그림임
            }
        }
    }
}

int main(){
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>paper[i][j];
        }
    }

    int picCount=0;
    int maxSize=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visitied[i][j] && paper[i][j]){ // 그림인데 방문하지 않았다면 -> 새로운 그림임
                picCount++;
                picSize[picCount]=1;
                dfs(i, j, picCount); // 현재까지의 그림 개수를 그림의 id로 사용
                if(picSize[picCount]>maxSize) maxSize=picSize[picCount];
            }
        }
    }
    cout<<picCount<<"\n"<<maxSize; // 그림 크기 및 제일 큰 그림 크기 출력
}

