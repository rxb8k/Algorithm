#include <iostream>
#include <string>
#include <map>
using namespace std;

int main () {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin>>N>>M;

    map<string, string> password;

    for (int i=0; i<N; i++) {
        string site;
        string pwd;
        cin>>site>>pwd;
        password.insert(make_pair(site, pwd));
    }

    for (int i=0; i<M; i++) {
        string siteInput;
        cin>>siteInput;
        cout<<password[siteInput]<<'\n';
    }
}