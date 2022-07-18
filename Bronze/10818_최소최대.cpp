#include <iostream>
using namespace std;

int main(){
    int n; int num; int max=0; int min=0;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>num;
        if(i==0) { max=num; min=num; }
        else {
            if(num>max) max=num;
            if(num<min) min=num;
        }
    }
    cout<<min<<' '<<max;
}