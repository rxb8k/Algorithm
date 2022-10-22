#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> minHeap;
    /* 음수 입력이 없으므로, 음수 처리를 해서 PQ에 저장
    따라서 절댓값이 작은 순서대로 큐에 저장되므로, 최소 힙을 구현 가능
    */
    int N;
    cin>>N;
    
    while(N--){
        int x;
        scanf("%d", &x);
        if(x>0){
            minHeap.push(-x);
        } else {
            if(minHeap.empty()) printf("0\n");
            else {
                printf("%d\n", -minHeap.top());
                minHeap.pop();
            }
        }
    }
}