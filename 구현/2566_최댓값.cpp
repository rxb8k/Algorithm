#include <iostream>
using namespace std;

int main () {
    int board[9][9];
    int max = 0;
    int max_x, max_y;

    for (int y=0; y<9; y++) {
        for (int x=0; x<9; x++) {
            cin>>board[y][x];
        }
    }

    for (int y=0; y<9; y++) {
        for (int x=0; x<9; x++) {
            if (board[y][x] >= max) {
                max = board[y][x];
                max_x = x, max_y = y;
            }
        }
    }
    for (int y=0; y<9; y++) {
        for (int x=0; x<9; x++) {
            cout<<board[y][x]<<" ";
        }
        cout<<endl;
    }

    cout<<max<<'\n'<<max_y+1<<" "<<max_x+1;
}