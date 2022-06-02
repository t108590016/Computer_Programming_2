#include <stdio.h>
int main(){
    int N,i,j,counter=1;
    scanf("%d",&N);
    for(i=2;i<=N;i++){
        for(j=2;j<i;j++){
            if(i%j==0){
                break;
            }
            else if(j==i-1){
                counter++;
                if(counter%3==0){
                    printf("%d",i);
                    printf("\n");
                }
                break;
            }
        }
    }
    if(counter<3){
        printf("含括的質數未達三個");
    }
    return 0;
}
