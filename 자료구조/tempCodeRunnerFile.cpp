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

    while (!s.empty()) {
        int currTop = s.top();
        s.pop();
        if (s.empty()) break;
        cout<<currTop<<" "<<s.top()<<" "<<cnt<<endl;
        if (s.top() > currTop){
            cout<<"D";
            cnt++;
        } 
    }

    cout<<cnt;
}