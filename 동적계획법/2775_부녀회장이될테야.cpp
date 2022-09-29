#include <iostream>
using namespace std;

int main(){
    int T;
    cin>>T;

    int dpTable[15][15]={0,};

    for(int i=0;i<=14;i++){ // 0~14층
        for(int j=1;j<=14;j++){ // 1~14호
            if(i==0) dpTable[i][j]=j;
            else {
                int sum=0;
                for(int k=1;k<=j;k++) sum+=dpTable[i-1][k];
                dpTable[i][j]=sum;
            }
        }
    }

    while(T--){
        int k, n;
        cin>>k>>n;
        cout<<dpTable[k][n]<<'\n';
    }
}