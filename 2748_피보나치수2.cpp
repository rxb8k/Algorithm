#include <iostream>
using namespace std;

// int fibo(unsigned int n){
//     if(n==0) return 0;
//     else if(n==1) return 1;
//     else return fibo(n-1)+fibo(n-2);
// }

int fibo_loop(unsigned int n){
    int* fibo=new int[n];
    fibo[0]=0, fibo[1]=1;
    for(int i=0;i<n;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    for(int i=0;i<n;i++){
        cout<<fibo[i];
    }
    return fibo[n];
}

int main() {
    unsigned int n; cin>>n;
    cout<< fibo_loop(n);
}