#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    char conti[3];
    conti[0]='0';
    while(conti[0]=='0'){
        int input,x=0,n=0,time=0;
        scanf("%d",&input);
        while(input>=1){
            n+=(input%10)*(pow(2,x));
            input=input/10;
            x++;
        }
        //printf("%d\n",n);
        time=circuit(n,0);
        int i;
        x=0;
        char output[4];
        while(time>=1){
            output[x]=time%2+'0';
            time=time/2;
            x++;
        }
        if(x<4){
            for(i=x;i<4;i++){
                output[i]=0+'0';
            }
        }

        for(i=3;i>=0;i--){
            printf("%c",output[i]);
        }

        printf("\n");
        //printf("%d\n",time);
        scanf("%s",&conti);
    }

    return 0;
}
int circuit(int n,int time){
    if(n==0) return time+0;
    else if(n==1) return time+0;
    else if(n%2==0){
        time+=1;
        return circuit(n/2,time);
    }
    else{
        time+=1;
        return circuit((n+1)/2,time);
    }
}
