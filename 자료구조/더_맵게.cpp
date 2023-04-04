#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    // 자료형, 구현체, 비교연산자
    // less<> 내림차순, 큰 것 우선, default
    // greater<> 오름차순, 작은 것 우선
    
    for (int s : scoville) { pq.push(s); }
    
    while (pq.top() < K) {
        int min1 = pq.top(); pq.pop();
        int min2 = pq.top(); pq.pop();
        int newFood = min1 + 2*min2;
        if (pq.empty()) {
            if (newFood < K) return -1; // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없음
        }
        pq.push(newFood);
        answer++;
        if (pq.top() >= K) break;
    }
    
    return answer;
}