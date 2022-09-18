#include <iostream>
using namespace std;

struct body{
    int w;
    int h;
    // bool operator<(body other) if(this->w<other.w && this->h<other.h) return true;
};

int main(){
    int n;
    cin>>n;

    body b[50];
    for(int i=0;i<n;i++) cin>>b[i].w>>b[i].h;

    int rank[50];
    fill(rank, rank+n, 0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b[i].w<b[j].w && b[i].h<b[j].h) {
                rank[i]++;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<rank[i]+1<<" ";
}