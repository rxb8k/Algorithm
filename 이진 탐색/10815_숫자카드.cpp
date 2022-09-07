#include <iostream> 
#include <algorithm>
using namespace std;

int binarySearch(int start, int end, int n, int* num){
    if(start>end) return 0;

    int middle=(start+end)/2; // 중간값 인덱스 설정
    // cout<<start<<" "<<middle<<" "<<end<<" "<<n<<endl;

    if(n==num[middle]) { // 중간값이 찾고자 하는 값인 경우
        return 1; // 재귀 호출 없이 바로 1 리턴하며 종료
    }
    else if(n>num[middle]) {
        return binarySearch(middle+1, end, n, &num[0]);
    }
    else if(n<num[middle]){
        return binarySearch(start, middle-1, n, &num[0]);
    }
    // 위와 같이 재귀를 반복하다보면 0 또는 1로 최종 리턴 값이 결정된다.
}

int main(){
    int N, M;
    int num[500000];
    int m[500000];

    cin>>N;
    for(int i=0;i<N;i++) cin>>num[i];
    cin>>M;
    for(int i=0;i<M;i++) cin>>m[i];

    sort(num, num+N);
    
    for(int i=0;i<M;i++){
        cout<<binarySearch(0, N-1, m[i], &num[0])<< " ";
    }
}