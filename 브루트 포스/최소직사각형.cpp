#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int maxWidth = 0;
    int maxHeight = 0;
    
    for (int i=0; i<sizes.size(); i++) {
        if (sizes[i][0] < sizes[i][1]) { // w < h이면 회전(swap)
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
        if (maxWidth < sizes[i][0]) maxWidth = sizes[i][0];
        if (maxHeight < sizes[i][1]) maxHeight = sizes[i][1];
    }
    
    return answer = maxWidth * maxHeight;
}