#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int p[1000]={};
    int result=0;

    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];

    // key idea: 빠른 사람부터 앞에 서야
    sort(p, p+n); // 오름차순으로 정렬
    for(int i=0;i<n;i++){
        result+=p[i]*(n-i);
    }
    cout<<result;
}