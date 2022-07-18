#include <iostream>
using namespace std;

int main(){
    int max=0; int index=0; int num;
    for(int i=0;i<9;i++){
        cin>>num;
        if(!i){max=num; index=1;}
        else{
            if(num>max) { max=num; index=i+1; }
        }
    }
    cout<<max<<endl<<index;
}