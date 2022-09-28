#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int m, n;
    cin>>m>>n;

    int sum=0;
    int min=10000;

    for(int i=m;i<=n;i++){
        if(sqrt(i)==(int)sqrt(i)){
            sum+=i;
            if(min>i) min=i;
        }
    }
    if(sum>0){
        cout<<sum<<'\n'<<min;
    } else cout<<-1;
}