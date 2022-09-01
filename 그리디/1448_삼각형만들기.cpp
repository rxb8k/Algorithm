#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;


int main(){
    int N;
    priority_queue<int> line_pq;
    priority_queue<int> triLineSum;
    vector<int> line;

    // key idea: 가장 긴 변의 길이는 다른 두 변의 길이의 합보다 작아야 삼각형을 그릴 수 있다
    
    cin>>N;
    for(int i=0;i<N;i++){
        int input;
        cin>>input;
        line_pq.push(input);
    }

    for(int i=0;i<N;i++){
        line.push_back(line_pq.top());
        line_pq.pop();
    }

    bool flag=false;
    for(int i=0;i<line.size()-2;i++){
        if(line[i]<line[i+1]+line[i+2]){
            flag=true;
            triLineSum.push(line[i]+line[i+1]+line[i+2]);
        }
    }

    cout<<(flag?triLineSum.top():-1);
}