#include <iostream>
#include <string>
using namespace std;

int N;

void recursionChatbot(int n){
    string underbar="";
    for(int i=0;i<n;i++) underbar.append("____"); // i번째 호출이면 (i-1)개만큼의 언더바 추가

    cout<<underbar<<"\"재귀함수가 뭔가요?\"\n";
    if(n==N){ // 마지막 호출이면
        cout<<underbar<<"\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    } else{ // 아직 마지막 호출이 아니면
        cout<<underbar<<"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
        cout<<underbar<<"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
        cout<<underbar<<"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
        recursionChatbot(n+1);
        }
    cout<<underbar<<"라고 답변하였지.\n";
    return;
}

int main(){
    cin>>N;
    cout<<"어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    recursionChatbot(0);
}