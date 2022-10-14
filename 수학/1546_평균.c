#include <stdio.h>

int main(){
    int N;
    double max=0, sum=0, avg=0;
    double score[1000]={0.0, };
    scanf("%d", &N);

    for(int i=0;i<N;i++){
        scanf("%lf", &score[i]);
        if(score[i]>max) max=score[i];
    }

    for(int i=0;i<N;i++){
        score[i]=score[i]/max*100;
        sum+=score[i];
    }
    
    avg=sum/(double)N; // int -> double 형변환
    printf("%f", avg);
}