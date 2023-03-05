#include <iostream>
using namespace std;

int main () {
    int N;
    int answer = 0;
    int lastMilk = -1;
    // 처음엔 무조건 0 마셔야
    // 이후에는 0->1, 1->2, 2->0

    cin>>N;

    while (N--) {
        int store;
        cin>>store;
        
        if (lastMilk == -1) {
            if (store == 0) { answer++; lastMilk=store; }
            else continue;
        } 
        else {
            if (lastMilk < 2) {
                if (store == lastMilk+1) { answer++; lastMilk = store; }
            } else {
                if (store == 0 && lastMilk==2) { answer++; lastMilk = store; }
            }
        }
    } 

    cout<<answer;
}