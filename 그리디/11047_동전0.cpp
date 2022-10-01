#include <iostream>
using namespace std;

int main(){
    int n, k;
    int coin[10]={0,};
    int countSum=0;

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }

    for(int i=n-1;i>=0;i--){
        int count=k/coin[i];
        k-=count*coin[i];
        countSum+=count;
    }
    cout<<countSum;

}