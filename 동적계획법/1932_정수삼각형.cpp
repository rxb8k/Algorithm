#include <iostream>
using namespace std;

#define MAX_SIZE 501
int dpTable[MAX_SIZE][MAX_SIZE] = {0,};

int main () {
    int n;
    cin>>n;

    for (int i=0; i<n; i++) { // i : 0 ~ n-1
        for (int j=0; j<i+1; j++) { //  j : 0 ~ i
            int input;
            cin>>input;

            if (i==0 && j==0) dpTable[i][j] = input; // 제일 위 칸
            else {
                if (j==0) { // 제일 왼쪽 끝
                    dpTable[i][j] = dpTable[i-1][j] + input;
                } else if (j==i) { // 제일 오른쪽 끝
                    dpTable[i][j] = dpTable[i-1][j-1] + input;
                }  else { // 나머지 내부
                    dpTable[i][j] = max(dpTable[i-1][j-1] + input, dpTable[i-1][j] + input);
                }
            }
        }
    }

    /*
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<dpTable[i][j]<<" ";
        }
        cout<<endl;
    }*/

    int max = 0;
    for (int j=0; j<n; j++) {
        if (dpTable[n-1][j] > max) max = dpTable[n-1][j];
    }

    cout<<max;
}