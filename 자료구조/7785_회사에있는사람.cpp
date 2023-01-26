#include <iostream>
#include <map>
#include <functional>
using namespace std;

int main () {
    int n;
    cin>>n;

    map<string, int, greater<string> > log; // Key 기준 내림차순 정렬

    for (int i=0; i<n; i++) {
        string name;
        string direction;
        cin>>name>>direction;

        if (direction.compare("enter") == 0) { // 결과가 0이면 같음. 무조건 " 쌍따옴표 " 써야 string으로 인식함
            log.insert(make_pair(name, 0));
        } else if (direction.compare("leave") == 0) {
            log.erase(name);
        }
    }

    for (auto l : log) {
        cout<<l.first<<'\n';
    }
}