#include <iostream>
using namespace std;

int main () {
    ios::sync_with_stdio(false); 

    /* 점화식 : P[i] = P[i-3] + P[i-2] + P[i-1]
    1 1 
    2 2
    3 4
    4 7
    5 13
    6 24
    7 44

    이유 : https://www.acmicpc.net/board/view/95422
    즉 기존의 수에 1, 2, 3을 더해서 새 수를 만드는 경우의 수의 합
    */

   int p[12];
   p[1] = 1;
   p[2] = 2;
   p[3] = 4;

   for (int i=4; i<12; i++) p[i] = p[i-3] + p[i-2] + p[i-1];


    int T;
    cin>>T;

    while (T--) {
        int n;
        cin>>n;
        cout<<p[n]<<'\n';
    }
}