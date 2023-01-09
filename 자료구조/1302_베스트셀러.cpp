#include <string>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main () {
    map<string, int> book;
    int n;
    cin>>n;

    for (int i=0; i<n; i++) {
        string name;
        cin>>name;
        
        if (book.find(name) == book.end()) { // 아직 맵에 저장되지 않은 책이면
            book.insert(make_pair(name,1)); // 새로 넣어줌. default 판매수는 1
        } else {
            book[name] += 1; // 판매량 증가
        }
    }

    int max = 0;
    vector<string> bestSellers;

    // 판매량 최댓값 찾기
    for (auto const& b : book) {
        if (b.second > max) {
            max = b.second;
        }
    }

    // 최대 판매량을 판매량 책의 이름을 저장
    for (auto const& b : book) {
        if (b.second == max) {
            bestSellers.push_back(b.first);
        }
    }

    sort(bestSellers.begin(), bestSellers.end()); // 사전순 정렬
    cout<<bestSellers[0];
}