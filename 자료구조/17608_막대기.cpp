#include <iostream>
#include <stack>
using namespace std;

int main () {
    stack<int> s;
    int N;
    int cnt = 1;

    cin>>N;

    while (N--) {
        int h;
        cin>>h;
        s.push(h);
    }
    int max = s.top();

    while (!s.empty()) {
        if (s.empty()) break;
        if (s.top() > max) { // 다음 막대기 높이가 현재 최대 높이 막대기보다 높으면
            cnt++; // 보이는 막대기 수 +1
            max = s.top(); // 해당 막대기의 길이로 최댓값 갱신
        }
        s.pop();
    }

    cout<<cnt;
}