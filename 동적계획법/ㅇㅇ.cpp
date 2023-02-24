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

   for (int j=1; j<201; j++) {
    dp[1][j] = j; // 첫줄 초기화
   }
   dp[2][1] = 1;

   for (int i=2; i<201; i++) {
    for (int j=2; j<201; j++) {
        dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
    }
   }

   cout<<dp[N][K];
}