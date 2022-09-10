#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 26

int n; // 지도의 가로 세로 길이
int map[MAX][MAX];
bool check[MAX][MAX];
int id=0; // 단지 번호
int village[MAX*MAX];

// 4방향 탐색에 사용할 좌표 이동용 배열 (좌, 하, 우, 상)
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

void dfs(int x, int y){
    check[x][y]=true; // 1. 함수에 들어오면 방문 완료 처리

    // 2. 방문해서 할 작업
    village[id]++;

    // 3. 다음 지점에 대해
    for(int i=0;i<4;i++){
        // 4방향으로 탐색을 해가며 다음 지점의 x, y 좌표 설정
        int nx=x+dx[i];
        int ny=y+dy[i];

        // 지도 범위 확인
        if( 0<=nx && nx<n && 0<=ny && ny<n ){
            // 다음 위치가 집이면서 && 방문하지 않았다면 dfs로 방문
            if(map[nx][ny]==1 && !check[nx][ny]){
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    cin>>n;

    // 1. 지도(map) 생성
    // 2. 체크 리스트 초기화
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d", &map[i][j]); // 입력을 1개씩 숫자로 끊어 받음
            check[i][j]=false;
        }
    }

    /* 
    3. 각 지점 방문
    dfs(0,0)와 같이 시작점부터 dfs를 돌리지 않는 이유는
    시작점에 집이 없으면 그대로 탐색이 중단되기 때문
    따라서 방문하지 않은 모든 집에 대해 탐색을 수행한다

    한 번의 탐색을 통해 -> 한 개의 단지를 그룹핑해 탐색하게 된다.
    */
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==1 && check[i][j]==false) {
                id++; // 이 탐색에서 사용할, 즉 이 탐색을 통해 탐지된 단지에 부여할 id 세팅
                dfs(i,j);
            }
        }
    }

    // 결과 출력
    sort(village+1, village+id+1);
    cout<<id<<'\n';
    for(int i=1;i<=id;i++) cout<<village[i]<<'\n';
}