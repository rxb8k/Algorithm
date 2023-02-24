#include <iostream>
#include <queue>
using namespace std;

int main () {
    int N;
    queue<int> q;
    
    cin>>N;

    for (int i=1; i<=N; i++) {
        q.push(i); // 1~N FIFO : 1, 2, 3, ... , N
    }

    while (q.size() > 1) {
        q.pop();
        int top = q.front();
        q.pop();
        q.push(top);
        if (q.size() == 1) break;
    }

    cout<<q.front();
}