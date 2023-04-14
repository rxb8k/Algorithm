#include <iostream>
using namespace std;

int N, S;
int num[21];
bool visited[21] = {false, };
int answer = 0;
int sum = 0;

// 시간초과 코드
void backTracking (int size, int depth) {
    if (size == depth) {
        if (sum == S) answer++;
        sum = 0;
        return;
    }
    else {
        for (int i=0; i<N; i++) { // num 배열의 N개 원소를 돌면서
            if (visited[i] == false) { // 방문하지 않았으면 방문
                sum += num[i];
                backTracking(size, depth+1);
            }
        }
    }
}

void recursive (int currDepth, int currSum) {
    if (currDepth == N) {
        if (currSum == S) answer++;
        return;
    }

    /*
    현재 단계(currDepth)에서는 현재 수 num[currDepth]를 더할지, 안 더할지 두 개의 경우의 수가 있다.
    이 두 가지 경우의 수에 따라 각각 다음 단계(currDepth+1)를 진행해나간다.
    이 과정을 currDepth == N이 될 때까지 반복한다.

    currDepth가 한정적이게 되는 문제가 있지 않은가? 없다.
    인덱스로서의 currDepth의 범위는 0~N-1이며,
    currDepth가 N이 될 때까지 0, 1, 2, .. N-1 번째 요소를 더할지 말지만 결정하는 것이다.
    */

    recursive(currDepth + 1, currSum); // 현재 수를 더하지 않음
    recursive(currDepth + 1, currSum + num[currDepth]); // 현재 수를 더함

}

int main () {
    cin>>N>>S;
    for (int i=0; i<N; i++) cin>>num[i];

    // for (int i=1; i<=N; i++) backTracking(i, 1); // 크기가 1~N개일 때 각각의 부분수열을 백 트래킹으로 찾음 (시간초과)
    recursive(0, 0);

    if (S==0) answer -= 1; 
    // 만들어야 하는 수가 0인 경우, 맨 처음에 아무것도 더하지 않은 경우를 빼줘야 한다. 아무것도 안 했는데 맨 처음 if문에서 그냥 answer++ 되어버림

    cout<<answer;
}