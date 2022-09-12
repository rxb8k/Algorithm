#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long dpTable[10001];
    int n;

    dpTable[0]=0; dpTable[1]=1;

    cin>>n;
    for(int i=2;i<=n;i++){
        dpTable[i]=dpTable[i-1]+dpTable[i-2];
    }

    cout<<dpTable[n];
}