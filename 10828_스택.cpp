// Silver IV
#include <iostream>
#include <vector>
using namespace std;

vector<int> stack;

void push(char X){stack.push_back(X);}

void pop(){
    if(stack.size()==0) cout<<-1<<'\n';
    else {
        int top=stack.back();
        stack.pop_back();
        cout<<top<<'\n';
    }
}

void size() { cout<<stack.size(); }

void empty() { cout<<(stack.size()==0?1:0)<<'\n';}

void top() {cout<<(stack.size()==0?-1:stack.back())<<'\n';}

int main(){
    // cin.tie(NULL); ios_base::sync_with_stdio(false);
    unsigned int N; cin>>N;
    string cmd;

    for(int i=0; i<N;i++){
        if(cmd=="top") top();
        else if(cmd=="empty") empty();
        else if(cmd=="size") size();
        else if(cmd=="pop") pop();
        else{
            push(cmd[5]);
        }
    }
}