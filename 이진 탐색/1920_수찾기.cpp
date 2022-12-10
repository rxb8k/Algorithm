#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_SIZE 100001

int N, M;
vector<int> A;
int target[MAX_SIZE];

int binarySearch (int start, int end, int target) {
    if (start > end) return 0;

    int mid = (start+end)/2;
    
    if (target == A[mid]) { return 1; }
    else if (target > A[mid]) {
        return binarySearch(mid+1, end, target);
    } else if (target < A[mid]) {
        return binarySearch(start, mid-1, target);
    }
}

int main() {
    cin>>N;
    for (int i=0; i<N; i++) {   
        int input;
        cin>>input;
        A.push_back(input);
    }
    cin>>M;
    for (int i=0; i<M; i++) {   cin>>target[i];  }
    sort(A.begin(), A.end());

    for (int i=0; i<M; i++) {
        cout<<binarySearch(0, N-1, target[i])<<"\n";
    }
}