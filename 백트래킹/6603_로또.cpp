#include <iostream>
using namespace std;

int arr[7];
bool visited[50] = {false, };

void backTracking (int depth, int num[], int k) {
    if (depth == 6) {
        for (int i=0; i<6; i++) {
            cout<<arr[i]<<' ';
        }
        cout<<"\n";
    }
    else {
        for (int i=0; i<k; i++) {
            int next = num[i]; // num 중에서 다음에 방문할 원소를 고름

            if (depth == 0) { // depth가 0일 때는 비교하지 않고
                if (!visited[next]) { // 방문하지 않았으면 방문
                visited[next] = true;
                arr[depth] = next;
                backTracking(depth + 1, num, k);
                visited[next] = false;
                }
            }
            else if (depth>0 && next>arr[depth-1]) { // depth가 1 이상일 때는 이전 원소의 크기와 비교하여, 더 크면 방문
                if (!visited[next]) { // 방문
                visited[next] = true;
                arr[depth] = next;
                backTracking(depth + 1, num, k);
                visited[next] = false;
                }
            }
        }
    }
}

int main () {
    while (true) {
        int k;
        int num[14];

        cin>>k;
        if (k==0) break;
        for (int i=0; i<k; i++) {
            cin>>num[i];
        }
        
        backTracking(0, num, k);
        cout<<'\n';
    }
}