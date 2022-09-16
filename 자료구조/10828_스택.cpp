#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    stack<int> s;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin>>n;

    while(n--){
        string cmd;
        cin>>cmd;
        if(cmd=="push"){
            int x;
            cin>>x;
            s.push(x);
        } else if(cmd=="pop"){
            if(!s.empty()){
                int top=s.top();
                s.pop();
                cout<<top<<'\n';
            } else cout<<"-1\n";
        } else if(cmd=="size") { cout<<s.size()<<'\n'; }
        else if(cmd=="empty")   {   cout<<(s.empty()?1:0)<<'\n'; }
        else if(cmd=="top"){
            if(!s.empty()){
                cout<<s.top()<<'\n';
            } else cout<<"-1\n";
        }
    }
    return 0;
}