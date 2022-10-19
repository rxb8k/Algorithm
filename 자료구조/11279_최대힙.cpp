#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> maxHeap;
    int N;

    cin>>N;
    while(N--){
        int x; // 입력되는 자연수는 2의 31승보다 작으므로, 정수형
        scanf("%d", &x);
        if(x>0){
            maxHeap.push(x);
        } else {
            if(maxHeap.empty()) printf("0\n");
            else {
                printf("%d\n", maxHeap.top());
                maxHeap.pop();
            }
        }
    }
}