#include <iostream>
using namespace std;

int main() {
    int button[3]={300, 60, 10};
    int count[3]={0,0,0};
    int result=0;
    int T, originalT;
    cin>>T;
    originalT=T;

    while(T>=300){
        T-=button[0];
        count[0]++;
    }
    while(T>=60){
        T-=button[1];
        count[1]++;
    }
    while(T>=10){
        T-=button[2];
        count[2]++;
    }
    
    for(int i=0;i<3;i++) result+=button[i]*count[i];

    if (result==originalT) {
        cout<<count[0]<<" "<<count[1]<<" "<<count[2];
    }
    else { cout<<-1; }
}