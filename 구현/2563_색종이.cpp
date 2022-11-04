#include <iostream>
using namespace std;

int main(){
    bool paper[101][101]={0, };
    int N;
    int area=0;

    cin>>N;

    while(N--){
        int w, h;
        cin>>w>>h;
        for(int y=h;y<h+10;y++){
            for(int x=w;x<w+10;x++){
                paper[y][x]=1;
            }
        }
    }

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(paper[j][i]) area++;
        }
    }

    printf("%d", area);
}