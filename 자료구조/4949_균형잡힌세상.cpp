#include <iostream>
#include <fstream> // for cin.getline
#include <cstring> // for strlen()
#include <stack>
using namespace std;

int main(){
    while(1){
        char c[101];
        stack<char> s; // 이 위치에 선언해줘야 매번 스택이 초기화됨
        bool isBalanced=true;
        cin.getline(c, 101);
        
        for(int i=0;i<strlen(c);i++){
            if(c[i]=='[' || c[i]=='('){ // 1. 닫는 괄호가 나오면 스택에 push
                s.push(c[i]);
            }
            else if(c[i]==']' || c[i]==')'){
                // 2. 닫는 괄호가 나왔을 경우
                if(s.empty()) {
                    // 2-1. 스택이 비어있으면 올바르지 않은 괄호 쌍
                    isBalanced=false;
                }
                else {
                    // 2-2.스택의 top이 짝이 맞지 않는 괄호일 경우 올바르지 않은 괄호 쌍
                    // 2-3.스택의 top이 짝이 맞는 괄호일 경우 pop
                    if(c[i]==']' && s.top()=='[') s.pop();
                    else if(c[i]==')' && s.top()=='(') s.pop();
                    else isBalanced=false;
                }
            }
            if(c[i]=='.'){
                if(i==0) break; // 입력 종료 조건
                if(!s.empty()) isBalanced=false; // 한 문장을 다 돌았는데도 스택에 남아있는 게 있으면 올바르지 않음
                cout<<(isBalanced ? "yes\n" : "no\n");
                continue;
            }
        }
        if(c[0]=='.') break; // 입력 종료 조건
    }
}