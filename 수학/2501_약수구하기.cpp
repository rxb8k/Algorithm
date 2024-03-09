#include <iostream>
using namespace std;

int main () {
    int N, K;
    cin>>N>>K;

    int answer = 0;
    int divisorCnt = 0; // 약수 개수 카운트

    for (int i=1; i<=N; i++) {
        if (N%i == 0) {
            divisorCnt++;
            if (divisorCnt==K) {
                answer = i;
                break;
            }
        }
    }

    cout<<answer;
}