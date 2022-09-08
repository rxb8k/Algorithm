#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int bag[51];

int binarySearch(int start, int end, int target){
    if(start>end) return -1;
    int middle=(start+end)/2;
    cout<<bag[middle]<<" ";
    
    if(bag[middle]==target) { cout<<"\n"; return 0;}
    else if(bag[middle]<target){
        return binarySearch(middle+1, end, target);
    }
    else if(bag[middle]>target){
        return binarySearch(start, middle-1, target);
    }
}

int main(){
    vector<int> input;
    for(int i=1;i<=50;i++) bag[i]=i;


    for(int i=0;i<100;i++){
        int num;
        cin>>num;
        if(num==0) break;
        else input.push_back(num);
    }

    for(int i=0;i<input.size();i++) {
      binarySearch(1, 50, input[i]);
    }
}