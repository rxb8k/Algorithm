#include <iostream>
using namespace std;

void solution(int k, int n){
    int p[14][14];
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            if(i==0) p[i][j]=i;
            else {
                p[i][j]+=p[i-1][j];
            } 
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
                cout<<p[i][j]<< " ";
            }
            cout<<endl;
        }
}

int main(){
    int k, n, T;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>k>>n;
        solution(k,n);
    }
}