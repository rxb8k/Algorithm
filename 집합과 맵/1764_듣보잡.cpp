#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    map<string, int> neverHeard;
    vector<string> answer;

    while(n--){
        string name;
        cin>>name;
        neverHeard[name]=0; // value는 아무 값이나 넣어줌
    }
    while(m--){
        string name;
        cin>>name;
        if(neverHeard.count(name)) answer.push_back(name);
    }
    sort(answer.begin(), answer.begin()+answer.size());
    cout<<answer.size()<<'\n';
    for(int i=0;i<answer.size();i++) cout<<answer[i]<<"\n";
}