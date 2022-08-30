#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b, c, n;
    int count[9];
    for(int i=0;i<9;i++) count[i]=0;

    cin>>a>>b>>c;
    int num=a*b*c;
    cout<<num<<endl;

    for(int i=9;i>0;i--){
        int n=num/int(pow(10, i));
        cout<<n<<endl;
    }
    // while(1){
    //     int n=num%10;
    //     count[num]++;
    //     int num=num/10;
    //     if(num<0) break;
    // }
    
    for(int i=0;i<9; i++) cout<<count[i]<<'\n';
}