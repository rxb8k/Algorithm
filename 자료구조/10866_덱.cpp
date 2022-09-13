#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<int> dq;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        string cmd;
        cin>>cmd;
        int x;
        if(cmd=="push_front") {
            cin>>x;
            dq.push_front(x);
        }
        else if(cmd=="push_back") {
            cin>>x;
            dq.push_back(x);
        }
        else if(cmd=="pop_front") {
            if(dq.empty()) cout<<-1<<'\n';
            else {
                cout<<dq.front()<<'\n';
                dq.pop_front();
            }
        }
        else if(cmd=="pop_back") {
            if(dq.empty()) cout<<-1<<'\n';
            else {
                cout<<dq.back()<<'\n';
                dq.pop_back();
            }
        }
        else if(cmd=="size") {
            cout<<dq.size()<<'\n';
        }
        else if(cmd=="empty") {
            cout<<(dq.empty()?1:0)<<'\n';
        }
        else if(cmd=="front") {
            cout<<(dq.empty()?-1:dq.front())<<'\n';
        }
        else if(cmd=="back") {
            cout<<(dq.empty()?-1:dq.back())<<'\n';
        }
    }
    return 0;
}