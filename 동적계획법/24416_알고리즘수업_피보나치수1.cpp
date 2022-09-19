#include <iostream>
using namespace std;

int code1count=0;
int code2count=0;

int fibo(int n){
    if(n==1 || n==2) {
        code1count++;
        return 1;
    }
    else return (fibo(n-1)+fibo(n-2));
}

int main(){
    int n;
    cin>>n;

    // 재귀를 활용한 피보나치
    fibo(n);

    // 동적 프로그래밍을 활용한 피보나치
    int fiboTable[41];
    fiboTable[1]=1;
    fiboTable[2]=1;

    for(int i=3;i<=n;i++){
        fiboTable[i]=fiboTable[i-1]+fiboTable[i-2];
        code2count++;
    }

    cout<<code1count<<" "<<code2count;
}