#include <iostream>

int main () {
    int N;
    std::cin>>N;

    // 홀수면 SK 승리, 짝수면 CY 승리

    std::cout<<(N%2==0?"CY":"SK");
}