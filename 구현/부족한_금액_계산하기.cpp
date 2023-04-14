#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    long long priceSum = 0;
    for (int i=1; i<=count; i++) priceSum += price*i;
    cout<<priceSum;
    
    if (priceSum>money) return answer = priceSum - money;
    else return 0;
}