#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N, M;
    cin>>N>>M;
    int num[101];

    for(int i=0;i<N;i++) cin>>num[i];

    int maxSum=0;
    int answer=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(i!=j && j!=k && i!=k){
                    int sum=num[i]+num[j]+num[k];
                    if(sum<=M){
                        if(sum > maxSum){
                            maxSum=sum;
                            answer=sum;
                        }
                    }
                }
            }
        }
    }
    cout<<answer;
}