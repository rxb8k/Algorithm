#include <iostream>
#include <vector>
using namespace std;

int a, b, cmd;
int U[1000001]; // 각 서로소 집합을 하나의 정점으로 보는 그래프

int find(int a){ // 주어진 원소의 루트 노드 번호 반환
    if(U[a]==a) return a; // 자기 자신이 루트이면 그대로 반환
    else return U[a]=find(U[a]); 
    // 루트가 아니라면, '해당 원소의 루트의 루트'를 다시 찾아 반환

    /*
    else return find(U[a]); ** 시간 초과 **
    제일 처음에 호출한 a의 루트 값만 수정한다.
    따라서 하나 위의 다른 노드에서 부모를 찾기 위해서는 또 다시 동일한 재귀를 반복해야 한다.

    else return U[a]=find(U[a]);
    find(U[a])의 결과를 -> U[a]에 입력하고 -> 그 결과를 반환하므로
    이 재귀를 돌며 거쳤던 노드들의 루트가 하나로 통일된다
    따라서 다른 노드에서 루트를 찾을 때에는 재귀 없이 바로 결과를 얻을 수 있다
    */
}

void join(int a, int b){ // 정점을 잇는 간선 추가
    int aRoot=find(a); // a의 루트 노드
    int bRoot=find(b); // b의 루트 노드
    U[bRoot]=aRoot; // a의 루트를 b의 루트의 루트로 -> 같은 루트 하에 있도록
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0;i<=n;i++) U[i]=i;

    for(int i=0;i<m;i++){
        scanf("%d %d %d", &cmd, &a, &b);
        if(cmd){ // [1] 두 원소가 같은 집합에 포함되어 있는지 확인
            if(find(a)==find(b)) printf("YES\n"); // 루트 노드가 같을 경우
            else printf("NO\n");
        } else { // [0] 두 원소 합치기(Union)
            join(a, b);
        }
    }
}