#include <string>
#include <vector>
#include <iostream>
using namespace std;

int sumOfDigit (int x) {
    int sum = 0;
    while (x>0) {
        sum += x%10;
        x /= 10;
    }
    return sum;
}

bool solution(int x) {
    int sum = sumOfDigit(x);
    if (x%sum==0) return true;
    else return false;
}