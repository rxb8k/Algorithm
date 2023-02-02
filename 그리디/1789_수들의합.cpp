#include <iostream>
using namespace std;

int main () {
    long long s;
    cin>>s;

    int i = 1;
    int n = 1;

    while (s >= 0) {
        s -= i;
        if (s==0) break;
        if (s<0) {
            i -= 1;
            n -= 1;
            break;
        }
        i += 1;
        n += 1;
        cout<<s<<' '<<i<<" "<<n<<endl;
    }

    cout<<n;
}