#include <list>
#include <iostream>
using namespace std;

int main(){
    list<int> l = {1, 2};
    list<int>::iterator t= l.begin(); // == auto t=l.begin()
    l.push_front(10);
    cout<<*t<<'\n';
    t++;
    l.push_back(5);
    l.insert(t,6); // t가 가리키는 곳 앞에 6 삽입
    t++;
    t=l.erase(t);
    cout<<*t<<'\n';

    for(auto i:l)
        cout<<i<<' ';

    cout<<'\n';

    for(list<int>::iterator it=l.begin(); it!=l.end();it++){
        cout<<"*it"<<' ';
    }
}