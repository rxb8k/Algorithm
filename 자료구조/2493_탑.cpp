#include <iostream>
#include <stack>
using namespace std;

int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    stack<pair<int, int> > tower;
    int n;
    cin>>n;

    for (int index=1; index<=n; index++) {
        int height;
        int answer =0;
        cin>>height;
        
        // 수신탑이 될 수 있는 탑들만 스택에 넣는다.

        while (!tower.empty()) {
            int target = tower.top().second;

            if (height < target) { // 수신탑 발견
                cout<<tower.top().first<<" ";
                break; // 수신탑 출력하고 다음 탑으로 넘어감
            } else { // 길이를 만족하는 수신탑 발견 못 함
                tower.pop(); // 쓰잘데기 없으니 쳐내고 다시 검사
            }
        } 
        
        if (tower.empty()) cout<<"0 "; // 첫번째 탑 or 스택이 다 비었음 (수신탑을 찾을 수 없음)
        tower.push(make_pair(index, height)); // 다음 탑으로 넘어가기 전, 현재 탑의 높이를 스택에 푸쉬
    }
}