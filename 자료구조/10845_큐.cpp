#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    queue<int> q;
    int n;
    cin>>n;

    while(n--){
        string cmd;
        cin>>cmd;
        if(cmd=="push"){
            int x;
            cin>>x;
            q.push(x);
        } else if (cmd=="pop"){
            if(!q.empty()){
                int front=q.front();
                q.pop();
                cout<<front<<"\n";
            } else cout<<"-1\n";
        } else if(cmd=="size") cout<<q.size()<<'\n';
        else if (cmd=="empty") cout<<(q.empty()?"1\n":"0\n");
        else if(cmd=="front") cout<<(q.empty()?-1:q.front())<<"\n";
        else if(cmd=="back") cout<<(q.empty()?-1:q.back())<<"\n";
    }
}