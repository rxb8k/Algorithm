#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char letter[16];
char arr[16];
bool visited[27];

bool isValid (char arr[]) { // 1개 이상의 모음, 2개 이상의 자음으로 구성되었나 확인
    int consonant = 0;
    int vowel = 0;
    bool isValid = false;

    for (int i=0; i<L; i++) {
        if (arr[i] == 'a' ||
            arr[i] == 'e' ||
            arr[i] == 'i' ||
            arr[i] == 'o' ||
            arr[i] == 'u') {
                vowel++;
            }
        else consonant++;
    }
    if (vowel >= 1 && consonant >= 2) isValid = true;
    return isValid;    
}

void backTracking (int depth) {
    if (depth == L) {
        if (isValid(arr)) { // 유효한 암호일 때만 출력
            for (int i=0; i<L; i++) {
            cout<<arr[i];
        }
        cout<<'\n';
        }

    }
    else {
        for (int i=0; i<C; i++) {
            char next = letter[i];
            int nextIndex = int(next) - int('a');

            if (depth == 0) { // depth==0이면 방문하지 않은 문자에 방문
                if (!visited[nextIndex]) {
                visited[nextIndex] = true;
                arr[depth] = next;
                backTracking(depth+1);
                visited[nextIndex] = false;
                }
            }
            else if (depth > 0) {
                int beforeIndex = int(arr[depth-1]) - int('a');
                if (nextIndex >= beforeIndex) {
                    if (!visited[nextIndex]) {
                    visited[nextIndex] = true;
                    arr[depth] = next;
                    backTracking(depth+1);
                    visited[nextIndex] = false;
                    }  
                }
            }
        }
    }
}

int main () {
    cin>>L>>C;
    for (int i=0; i<C; i++) {
        cin>>letter[i];
    }
    sort(letter, letter+C); // 문자 오름차순(사전순) 정렬
    // for (int i=0; i<C; i++) cout<<letter[i];
    backTracking(0);
}