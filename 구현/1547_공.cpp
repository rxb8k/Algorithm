#include <iostream>
using namespace std;

bool cup[4] = {0, 1, 0, 0};

void swap (int x, int y) {
    bool x_copy = cup[x];
    cup[x] = cup[y];
    cup[y] = x_copy;
}

int main () {
    int M;

    cin>>M;

    while (M--) {
        int x, y;
        cin>>x>>y;
        swap(x, y);
    }

    for (int i=1; i<=3; i++) {
        if (cup[i]) cout<<i;
    }
}