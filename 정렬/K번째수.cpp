#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cutSort(vector<int> array, int i, int j, int k){
    vector<int> cutArray;
    for(int index=i-1;index<j;index++) cutArray.push_back(array[index]);
    sort(cutArray.begin(), cutArray.end());
    return cutArray[k-1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0;i<commands.size();i++){
        int result=cutSort(array, commands[i][0], commands[i][1], commands[i][2]);
        answer.push_back(result);
    }
    return answer;
}