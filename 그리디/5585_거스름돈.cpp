#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int input;
    cin>>input;
    int money=1000-input;

    int coin[6]={500, 100, 50, 10, 5, 1};
    int coinValueIndex=0;
    int coinNumber=0;


    while(coinValueIndex<6 && money>0){
        if(money==0) break;
        int coinValue=coin[coinValueIndex];
        if(money>=coinValue) { money-=coinValue; coinNumber++; }
        else if(money<coinValue) coinValueIndex++;
    }
    cout<<coinNumber;
}