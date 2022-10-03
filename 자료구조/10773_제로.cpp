#include <stack>
#include <iostream>
using namespace std;

int main(){
    int k;
    stack<int> s;
    long long sum=0;

    cin>>k;

    while(k--){
        int x;
        cin>>x;
        if(x>0) s.push(x);
        else if(x==0) s.pop();
    }

    if(!s.empty()){
        while(!s.empty()){
            sum+=s.top();
            s.pop();
        }
    } else sum=0;
    cout<<sum;
}