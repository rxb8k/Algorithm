#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int N;
    int n[9]={};
    int leftSum=0, rightSum=0;

    cin>>N;

    int digit=1;
    while(1){
        n[digit]=N%10; // N의 일의 자리 저장
        N/=10;
        digit++;
        if(1>N) break;
    }

    for (int i=1;i<=digit;i++){
        if(i<=digit/2) leftSum+=n[i];
        else rightSum+=n[i];
    }
    
    cout<<(leftSum==rightSum?"LUCKY":"READY");
}