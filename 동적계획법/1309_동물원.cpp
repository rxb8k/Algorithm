#include <iostream>
using namespace std;

#define MAX 100001
#define MOD 9901

int main () {
    int N;
    long long dp[MAX][4];
    /*
    전체 경우의 수 table
    N   | ㅁㅁ | ㅇㅁ | ㅁㅇ | sum // 마지막 우리의 형태
    1   |   1   1   1   3
    2   |   3   2   2   7
    3   |   7   5   5   17
    4   |   17  12  12  41
    실제 dpTable에는 나머지를 저장한다.
    */

    cin>>N;

    dp[1][0] = 1; dp[1][1] = 1; dp[1][2] = 1; dp[1][3] = 3;

    for (int i=2; i<=N; i++) {
        dp[i][0] = (dp[i-1][3]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][3] = (dp[i][0] + dp[i][1] + dp[i][2]) % MOD;
    }

    cout<<dp[N][3];
}