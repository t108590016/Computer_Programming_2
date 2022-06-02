#include <stdio.h>
#include <string.h>

int main(){
    int conti=0;
    while(conti==0){
        int i,x=0;
        int n,k;
        char output[30],output_r[30],gray[30];
        scanf("%d %d",&n,&k);
        while(x<n){
            output[x]=k%2+'0';
            k=k/2;
            x++;
        }
        x=0;
        for(i=n-1;i>=0;i--){
            output_r[x]=0+output[i];
            x++;
        }
        x=0;
        gray[x]=0+output_r[0];
        for(i=0;i<n-1;i++){
            x++;
            if(output_r[i]==output_r[i+1]){
                gray[x]=0+'0';
            }
            else{
                gray[x]=1+'0';
            }
        }
        for(i=0;i<n;i++){
            printf("%c",gray[i]);
        }
        printf("\n");
        scanf("%d",&conti);
    }
    return 0;
}
