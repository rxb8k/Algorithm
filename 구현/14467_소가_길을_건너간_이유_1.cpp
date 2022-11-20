#include <iostream>
#include <vector>
using namespace std;

int cowPosition[101];

int main () {
    int N;
    int movingCount = 0;

    cin>>N;

    fill(cowPosition, cowPosition+101, -1);

    for (int i=0; i<N; i++) {
        int cowId;
        cin>>cowId;
        int cowPositionBefore = cowPosition[cowId];
        int cowPostitionNow;
        cin>>cowPostitionNow;

        if(cowPositionBefore != -1 && cowPositionBefore != cowPostitionNow) {
            movingCount++;
        }

        cowPosition[cowId] = cowPostitionNow;
    }

    cout<<movingCount;
}