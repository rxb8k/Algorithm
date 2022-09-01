#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional> // greater, less
using namespace std;

void printQueue(priority_queue<int, vector<int>, greater<int> > pq){
    priority_queue<int, vector<int>, greater<int> > pqCopy=pq;
    cout<<"\n[ ";
    while(!pqCopy.empty()){
        cout<<pqCopy.top()<<" ";
        pqCopy.pop();
    }
    cout<<"]\n";
}

int main(){
    int N;
    priority_queue<int, vector<int>, greater<int> > card; // 작은 원소부터 내보내는 우선순위 큐
    int countSum=0;

    /* key idea: 매 비교 시점마다 가장 작은 카드 묶음부터 오름차순으로 비교한다 */

    cin>>N;
    for(int i=0;i<N;i++) { 
        int input;
        cin>>input;
        card.push(input);
    }

    if(card.size()==1) countSum=0; // 카드 묶음이 1개일 경우 예외 처리
    else {
        bool running=true;
        do {
            /*
            firstCard와 secondCard는 각각 남은 카드 묶음 중 제일 작은 것, 두번째로 작은 묶음이다.
            다시 비교를 수행할 때, 남은 카드 묶음의 개수가 1개이면 firstCard는 0으로 설정하여 계산한다.
            시행착오 : 이 처리를 secondCard에서 하면 안 되는데, 이는 firstCard가 pop되고 나서 사이즈가 1이 되었다면 원래 사이즈는 2였기 떄문이다.
            */
            int firstCard=0;
            if(card.size()!=1) {
                firstCard=card.top();
                card.pop();
            } 
            
            int secondCard=card.top();
            card.pop();

            if(card.empty()) running=false;

            countSum+=firstCard+secondCard;
            card.push(firstCard+secondCard); // 새로이 만들어진 카드 묶음을 우선순위 큐에 추가한다.
        } while (running);
    }
    cout<<countSum;
}