// Bronze I
// 팩토리얼을 이용한 풀이
#include <iostream>
using namespace std;

int factorial(int& x){
    int answer=1; int i=x;
    for(int i=x;i>0;i--) answer*=i;
    return answer;
}

int main(){
    int N, K, N_K;
    cin>> N >> K; N_K=N-K;
    cout<< factorial(N)/(factorial(K)*factorial(N_K));
}