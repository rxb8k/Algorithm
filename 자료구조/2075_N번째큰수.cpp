#include <iostream>
#include <queue>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    
    int N;
    priority_queue<int> pq;
    // key idea: 상위 N개의 수만 저장한다.

    cin>>N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int x;
            cin>>x;

            if (pq.size() < N) pq.push(-x); // 음수로 바꿔 pq에 넣음
            else {
                pq.push(-x);
                pq.pop(); // (절대값이) 제일 작은 수를 빼냄
            }
        }
    }

    cout<<-pq.top();
}