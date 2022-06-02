#include <stdio.h>
#include <string.h>
int main(){
    char input[100];
    int i,j,k,m,same=0,a=0;
    scanf("%s",&input);
    scanf("%d",&m);
    for(i=0;i<strlen(input)-m+1;i++){
        same=0;
        for(j=i;j<i+m-1;j++){
            if(same==1) break;
            for(k=j;k<i+m-1;k++){
                //printf("i=%d,j=%d,k=%d\n",i,j,k);
                //printf("%c %c\n",input[j],input[k+1]);
                if(input[j]==input[k+1]){
                    same=1;
                    break;
                }
                //if(j==m+i-2 && k==i+m-2) a++;

            }
            //printf("%d\n",a);
        }
        if(same==0) a++;
        //printf("%d\n",a);
    }
    printf("%d",a);
    return 0;
}
