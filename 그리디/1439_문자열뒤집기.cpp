#include <iostream>
using namespace std;

#define SIZE 1000000

int main(){
    char s[SIZE]={};
    cin>>s;
    int count0=0, count1=0; // 문자열 내 0 영역 및 1 영역의 개수

    for(int i=0;i<=SIZE;i++) {
        if(i==0) s[i]=='1' ? count1++ : count0++;
        else{
            if(s[i-1]=='1'&&s[i]=='0') count0++; // 1->0으로 바뀌면 0의 분량 추가
            else if(s[i-1]=='0'&&s[i]=='1') count1++; // 0->1로 바뀌면 1의 분량 추가
            // 0->0 혹은 1->1인 경우는 같은 영역이므로 고려할 필요 없음
        }
    }
    cout<< (count0>count1?count1:count0); // count0과 count1 중 더 작은 것이 답
}