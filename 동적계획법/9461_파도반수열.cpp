#include <iostream>
using namespace std;

int main(){
    int T;
    cin>>T;

    long long dpTable[101];
    for(int i=1;i<=100;i++){
        if(i<=3) dpTable[i]=1;
        else if(i<=5) dpTable[i]=2;
        else{
            dpTable[i]=dpTable[i-1]+dpTable[i-5];
        }
    }

    //for(int i=1;i<=100;i++) cout<<dpTable[i]<<" ";

    while(T--){
        int n;
        cin>>n;
        cout<<dpTable[n]<<'\n';
    }
}