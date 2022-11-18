#include <iostream>
using namespace std;

bool paper[101][101]={0, };
int area = 0;

int main() {
    for (int i=0; i<4; i++) {
        int lx, ly, rx, ry;
        cin>>lx>>ly>>rx>>ry;

        for (int x=lx; x<rx; x++) {
            for (int y=ly; y<ry; y++) {
                paper[y][x] = 1;
            }
        }
    }

    for (int i=0; i<101; i++) {
        for (int j=0; j<101; j++) {
            if (paper[i][j]==true) {
                area++;
            }
        }
    }

    cout<<area;
}