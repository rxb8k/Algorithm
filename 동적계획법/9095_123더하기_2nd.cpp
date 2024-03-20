#include <iostream>
using namespace std;

int main () {
    int n;
    int dp[13] = {0, };

    dp[1] = 1;
    dp[2] = 2; // (1+1), (2)
    dp[3] = 4; // (1+1+1), (2+1), (1+2), (3)

    for (int i=4; i<=12; i++) {
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    } 

    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin>>n;
        cout<<dp[n]<<'\n';
    }
}