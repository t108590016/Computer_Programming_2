#include <stdio.h>
#include <string.h>
int main(){
    char input[10000];
    int i,j,k,change_to_U=0,change_to_L=0,upper=0,lower=0,len=0;
    scanf("%d",&k);
    scanf("%s",&input);
    for(i=0;i<strlen(input)-k;i++){
        upper=lower=0;
        for(j=i;j<strlen(input);j++){
            printf("i=%d,char=%c\n,change_to_U=%d,change_to_L=%d,upper=%d,lower=%d,len=0",i,input[i]);
            if(change_to_L==1 && (input[j]>='A' && input[j]<='Z')){
                if((len==0 || len<upper+lower)&&(lower%k==0 && upper%k==0)) len=upper+lower;
                else if((len==0 || len<lower)&&(lower%k==0 && upper%k!=0)) len=lower;
                else if((len==0 || len<upper)&&(lower%k!=0 && upper%k==0)) len=upper;
                upper=lower=0;
                break;
            }
            else if(change_to_U==1 && (input[j]>='a' && input[j]<='z')){
                if((len==0 || len<upper+lower)&&(lower%k==0 && upper%k==0)) len=upper+lower;
                else if((len==0 || len<lower)&&(lower%k==0 && upper%k!=0)) len=lower;
                else if((len==0 || len<upper)&&(lower%k!=0 && upper%k==0)) len=upper;
                upper=lower=0;
                break;
            }
            else{
                if(input[j]>='A' && input[j]<='Z'){
                    change_to_L=0;
                    upper++;
                    if(upper%k==0) change_to_L=1;
                }
                else if(input[j]>='a' && input[j]<='z'){
                    change_to_U=0;
                    lower++;
                    if(lower%k==0) change_to_U=1;
                }
            }

        }
    }
    printf("%d",len);
    return 0;
}
