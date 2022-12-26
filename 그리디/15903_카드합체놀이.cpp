#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

int main () {
    int n, m;
    ll result = 0;
    priority_queue<ll, vector<ll>, greater<ll> > pq; // PQ with Min Heap
    
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        int input;
        scanf("%d", &input);
        pq.push(input);
    }

    for (int i=0; i<m; i++) {
        ll minFirst = pq.top();
        pq.pop();
        ll minSecond = pq.top();
        pq.pop();
        ll minSum = minFirst + minSecond;
        pq.push(minSum);
        pq.push(minSum);
    }

    while (!pq.empty()) {
        result += pq.top();
        pq.pop();
    }

    printf("%lld", result);
}