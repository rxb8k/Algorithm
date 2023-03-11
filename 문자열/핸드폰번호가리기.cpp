#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string phone_number) {
    if (phone_number.size()==4) return phone_number;
    for (int i=0; i<phone_number.size()-4; i++) {
        phone_number[i] = '*';
    }
    return phone_number;
}