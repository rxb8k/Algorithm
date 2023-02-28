#include <iostream>
using namespace std;

char board[8][8];

int main () {
    int answer = 0;

    for (int i=0; i<8; i++) {
        string line;
        cin>>line;
        for (int j=0; j<8; j++) {
            board[i][j] = line[j];
        }
    }

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if ((i%2==0 && j%2==0)|| (i%2==1 && j%2==1)) { // 하얀 칸
                if (board[i][j] == 'F') answer++;
            }
        }
    }

    cout<<answer;
}