#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int N;
    int dp[1001]; // dp[i] = i개의 카드를 갖기 위해 지불할 돈의 최댓값

    cin>>N;

    for (int i=1; i<=N; i++) {
        cin>>dp[i]; // 우선 P[i]가 최선(최대)의 값이라고 가정
            /*
            이후부터는
            dp[2] = max (dp[1] + dp[1], card[2])
            dp[3] = max (dp[1] + dp[2], card[3])
            dp[4] = max (dp[1] + dp[3], dp[2] + dp[2], card[4])
            와 같이 계산됨
            */
        for (int j=1; j<i; j++) {
            /*
            i=1 일 때 X
            i=2 일 때 (1, 1)
            i=3 일 때 (1, 2)
            i=4 일 때 (1, 3) (2, 2)
            */
            dp[i] = max(dp[i], dp[j] + dp[i-j]); // 각 case에서의 값을 계산하며 dp 갱신
        }
    }

    cout<<dp[N];
}