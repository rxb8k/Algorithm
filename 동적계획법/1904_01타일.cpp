#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000001

int main() {
    int N;
    cin>>N;

    vector<long long> dpTable;
    vector<int> remainder;

    // N=1, N=2일 때의 값 세팅
    for (int i=0; i<3; i++) {
        dpTable.push_back(i);
        remainder.push_back(i);
    }

    for (int i=3; i<MAX; i++) {
        dpTable.push_back(dpTable[i-2] + dpTable[i-1]);
        remainder.push_back((remainder[i-2] + remainder[i-1]) % 15746);
    }   

    cout<<remainder[N];
}