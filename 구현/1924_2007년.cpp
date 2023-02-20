#include <iostream>
#include <string>
using namespace std;

int main () {
    int x, y;
    int lengthOfMonth[13] = { 0, 31, 28, 31,
        30, 31, 30, 
        31, 31, 30,
        31, 30, 31
        };
    string day[366];
    cin>>x>>y;

    for (int i=1; i<=365; i++) {
        switch (i % 7) {
            case 0: day[i] = "SUN"; break;
            case 1: day[i] = "MON"; break;
            case 2: day[i] = "TUE"; break;
            case 3: day[i] = "WED"; break;
            case 4: day[i] = "THU"; break;
            case 5: day[i] = "FRI"; break;
            case 6: day[i] = "SAT"; break;
        }
    }

    int index = 0;
    for (int i=1; i<x; i++) {
        index += lengthOfMonth[i];
    }
    index += y;

    cout<<day[index];
}