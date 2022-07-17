#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int score[1000];
    for(int i=0;i<1000;i++) score[i]=0;
    double sum=0, mean=0, answer=0;

    int c, n;
    cin>>c;

    for(int i=0;i<c;i++){
        for(int i=0;i<1000;i++) score[i]=0;
        sum=0; mean=0; answer=0;

        cin>>n;
        for(int i=0;i<n;i++) {
            cin>>score[i];
            sum+=score[i];
        }
        mean=sum/n;
        for(int i=0;i<n;i++){
            if(score[i]>mean) answer++;
        }
        cout<<setprecision(3)<<fixed<<answer/n*100<<"%\n";
    }
}