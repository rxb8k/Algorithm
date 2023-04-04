#include <iostream>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

int solution(string S) {
    stack<char> s;
    
    for (char c : S) {
        if (s.empty()) s.push(c);
        else {
            char topBefore = s.top();
            s.push(c);
            if (topBefore == s.top()) {
                s.pop(); s.pop();
            }
        }
    }
    
    if (s.empty()) return 1;
    else return 0;
}