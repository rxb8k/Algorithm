#include <iostream>
using namespace std;

int main () {
    int N, K;
    long long dp[201][201];
    /*
        K=1 K=2 K=3 K=4
    N=1 1   2   3   4
    N=2 1   3   6   10
    N=3 1   4   10  20
    N=4 1   5   15  35
    N=5 1   6   21  56
    N=6 1   7   28  84
    ...
    N=20 1  21
    실제 dpTable에는 나머지만 저장
    */
    cin>>N>>K;

    for (int i=1; i<201; i++) {
        for (int j=1; j<201; j++) {
            if (i==1) {
                dp[i][j] = j;
            }
            else if (j==1) {
                dp[i][j] = 1;
            }
            else if (j==2) {
                dp[i][j] = i+1;
            }
            else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
            }
        }
    }
    
    /*
    for (int i=1; i<11; i++) {
        for (int j=1; j<11; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    cout<<dp[N][K];
}