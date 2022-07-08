// Silver III
// 팩토리얼을 이용한 풀이
#include <iostream>
#include <iomanip>
using namespace std;

int factorial(int& x){
    int answer=1; int i=x;
    for(int i=x;i>0;i--) answer*=i;
    return answer;
}

int combination(int& n, int& r){
    int n_r=n-r;
    return factorial(n)/(factorial(r)*factorial(n_r));
}

int main(){
    int N=0; int M=0; int K=0; int color[50];
    for(int i=0;i<50;i++) color[i]=0;
    
    cin>>M;
    for(int i=0;i<M;i++) cin>>color[i];
    cin>>K;
    for(int i=0;i<M;i++) N+=color[i];

    // 랜덤하게 뽑는 경우는 nCk, 색이 같은 경우는 color[i]Ck, 그게 M개의 경우가 있음
    int sameColorCase=0;
    for(int i=0;i<M;i++){
        sameColorCase+=combination(color[i], K);
    }
    
    double answer=sameColorCase/combination(N, K); cout<<setprecision(9)<< answer;
}