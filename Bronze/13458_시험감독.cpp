#include <iostream>
using namespace std;


int main(){
    long long n, b, c; long long  answer=0;
    long long  a[1000000]; long long  x[1000000];
    for(int i=0;i<n;i++){a[i]=0; x[i]=0;}

    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>b>>c;

    for(int i=0;i<n;i++){
        if(a[i]>b) x[i]=(a[i]-b)/c;
        if(a[i]>b+c*x[i]) x[i]++;
        // cout<<x[i]<< " ";
        answer+=x[i];
    }
    answer+=n;
    cout<<answer;
}