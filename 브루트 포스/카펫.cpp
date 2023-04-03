#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int yw=1; yw<=yellow; yw++) {
        if (yellow%yw == 0) {
            int yh = yellow / yw;
            int bw = yw + 2;
            int bh = yh + 2;
            if (bw*bh - yw*yh == brown) {
                answer.push_back(bh);
                answer.push_back(bw);
                break;
            }
        }
    }
    return answer;
}