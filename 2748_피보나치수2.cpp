// Bronze I
#include <iostream>
using namespace std;

// int fibo(unsigned int n){
//     if(n==0) return 0;
//     else if(n==1) return 1;
//     else return fibo(n-1)+fibo(n-2);
// }

int main() {
    unsigned int n, answer; cin>>n;

    long fibo[91]; 
    for(int i=0;i<91;i++) fibo[i]=0;
    fibo[1]=1;

    for(int i=2;i<=n;i++) { fibo[i]= fibo[i-1]+fibo[i-2]; }

    cout<< fibo[n];
}