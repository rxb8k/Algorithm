#include <iostream>
using namespace std;

/*
    rule:
    퀸은 일직선으로 앞, 뒤, 대각선 어떤 방향이든 '원하는 만큼' 이동할 수 있으며
    서로의 퀸이 움직이는 경로에 다른 퀸이 있어서는 안 된다.
    즉, 퀸의 특성상 체스판 한 행당 한 개의 퀸만 존재할 수 있다.
*/

int N;
// bool board[15][15] = {false, }; // 2차원 배열을 만들 필요 없음
int queenRow[15] = {false, }; // 각 행에서의 퀸의 위치만 저장하는 1차원 배열만 있으면 됨
int answer = 0;

bool possible (int row) {
    for (int i=0; i<row; i++) { // 현재까지의 모든 행에 대해 퀸의 위치를 검사
        // queenRow[i] (i = 0~row-1)는 현재까지 fix된 퀸의 위치, queenRow[row]는 현재 놓으려는 퀸의 위치

        if ( (queenRow[i] == queenRow[row]) // 행 내에서 퀸이 놓여있는 열의 위치가 같거나
            || abs(queenRow[i] - queenRow[row]) == abs (i-row) // 두 위치가 대각선으로 놓여있다면, 즉 행의 변화량과 열의 변화량이 같다면
        ) {
            return false;
        }
    }
    return true;
}

void backTracking (int row) {
    if (row == N) {
        answer++;
        return;
    }
    else {
        for (int col=0; col<N; col++) { // 현재 행에서 모든 열에 퀸을 놓아보며 검사
            queenRow[row] = col; // 일단 냅다 놓아 봄
            if (possible(row)) backTracking(row+1); // 놓을 수 있으면 그 다음 행의 퀸의 위치를 또 찾음
        }
    }
}

int main () {
    cin>>N;
    backTracking(0); // 0행부터 탐색 시작
    cout<<answer;
}