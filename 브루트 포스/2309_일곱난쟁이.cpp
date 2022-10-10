#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int dwarf[9]={0,};
    int heightSum=0;

    for(int i=0;i<9;i++){
        cin>>dwarf[i];
        heightSum+=dwarf[i];
    }

    bool flag=false;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(i!=j){
                int diff=heightSum-dwarf[i]-dwarf[j];
                if(diff==100) {
                    dwarf[i]=999;
                    dwarf[j]=999;
                    flag=true;
                    break;
                }
            }
        }
        if(flag) break;
    }

    sort(dwarf, dwarf+9);
    for(int i=0;i<7;i++) cout<<dwarf[i]<<'\n';
}