#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    int mode,n,i,x=0,op=0,b1,b2;
    char output[30];
    scanf("%d",&mode);
    if(mode==1){
        scanf("%d",&n);
        while(n>=1){
            output[x]=n%2+'0';
            n=n/2;
            x++;
        }
        for(i=x-1;i>=0;i--){
            printf("%c",output[i]);
        }
    }
    else if(mode==2){
        scanf("%d",&n);
        while(n>=1){
            op+=(n%10)*(pow(2,x));
            n=n/10;
            x++;
        }
        printf("%d",op);
    }
    else{
        scanf("%d",&b1);
        scanf("%d",&b2);
        scanf("%d",&n);
        while(n>=1){
            op+=(n%10)*(pow(b1,x));
            n=n/10;
            x++;
        }
        x=0;
        while(op>=1){
            output[x]=op%b2+'0';
            op=op/b2;
            x++;
        }
        for(i=x-1;i>=0;i--){
            printf("%c",output[i]);
        }
    }
    return 0;
}
