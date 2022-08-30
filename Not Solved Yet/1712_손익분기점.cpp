
#include <iostream>
using namespace std;

int main(){
    int a, b, c; long point, i;
    cin>>a>>b>>c; point=-1; i=1;
    if(b<=c){
        while(1){
            if(a+b*i<c*i){
                point=i;
                break;
            }
            i++;
        }
    }
    cout<<point;
}