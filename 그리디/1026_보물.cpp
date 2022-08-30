#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, size;
    int a[50], b[50];
    int s=0;
    
    cin>>n; size=n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    // key idea: A의 원소가 작을수록 큰 B 원소와 곱한다
    sort(b, b+n);
    sort(a, a+n);

    for(int i=0;i<n;i++) { s+=a[i]*b[size-1-i];}
    cout<<s;
}