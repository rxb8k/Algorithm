// Silver IV
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> stack;

void push(string cmd){
    int x=stoi(cmd);
    stack.push_back(x);
}
void pop(){
    if(stack.size()==0) cout<<-1<<'\n';
    else {
        int top=stack.back();
        stack.pop_back();
        cout<<top<<'\n';
    }
}
void size() { cout<<stack.size()<<'\n'; }
void empty() { cout<<(stack.size()==0?1:0)<<'\n';}
void top() {cout<<(stack.size()==0?-1:stack.back())<<'\n';}

int main(){
    cin.tie(NULL); cout.tie(NULL);ios_base::sync_with_stdio(false);
    unsigned int N; string cmd; int x;
    
    cin>>N;

    for(int i=0; i<N;i++){
        getline(cin, cmd); 
        if(!cmd.compare("top")) top();
        else if(!cmd.compare("empty")) empty();
        else if(!cmd.compare("size")) size();
        else if(!cmd.compare("pop")) pop();
        else{
            cout<< cmd.substr(5, 15);
        }
    }
}