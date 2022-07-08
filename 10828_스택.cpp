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
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    unsigned int N; string cmd; int x;
    
    cin>>N;

    for(int i=0; i<N;i++){
        if(!cmd.compare("top")) top();
        else if(!cmd.compare("empty")) empty();
        else if(!cmd.compare("size")) size();
        else if(!cmd.compare("pop")) pop();
        else{
            cin>>x;
            push(x);
        }
    }
}