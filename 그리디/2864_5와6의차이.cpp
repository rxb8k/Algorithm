#include <iostream>
#include <cmath>
using namespace std;

int fiveToSix(int n){
    int digit=0;
    int convertedNum=0;
    while(n>0){
        int digitNum=n%10;
        if(digitNum==5) digitNum=6;
        convertedNum+=digitNum*pow(10, digit);
        n/=10;
        digit+=1;
    }
    return convertedNum;
}

int sixToFive(int n){
    int digit=0;
    int convertedNum=0;
    while(n>0){
        int digitNum=n%10;
        if(digitNum==6) digitNum=5;
        convertedNum+=digitNum*pow(10, digit);
        n/=10;
        digit+=1;
    }
    return convertedNum;
}

int main(){
    int a, b;
    cin>>a>>b;

    // a+b의 최솟값
    cout<<sixToFive(a)+sixToFive(b)<<" ";

    // a+b의 최댓값
    cout<<fiveToSix(a)+fiveToSix(b);
}