#include <stdio.h>
int main(){
    int state=0,Otimes=0;
    char input;
    scanf("%c",&input);
    if(input=='O'){
        Otimes+=1;
    }
    input=check(input);
    state=state<<input|1<<(input-1);
    //printf("%d %d %d\n",state&1,(state>>1)&1,(state>>2)&1);

    scanf(" %c",&input);
    if(input=='O'){
        Otimes+=1;
    }
    input=check(input);
    state=state<<input|1<<(input-1);
    //printf("%d %d %d\n",state&1,(state>>1)&1,(state>>2)&1);

    scanf(" %c",&input);
    if(input=='O'){
        Otimes+=1;
    }
    if(Otimes==3){
        state=0;
        Otimes=0;
    }
    input=check(input);
    state=state<<input|1<<(input-1);
    //printf("%d %d %d\n",state&1,(state>>1)&1,(state>>2)&1);

    scanf(" %c",&input);
    if(input=='O'){
        Otimes+=1;
    }
    if(Otimes==3){
        state=0;
        Otimes=0;
    }
    input=check(input);
    state=state<<input|1<<(input-1);
    //printf("%d %d %d\n",state&1,(state>>1)&1,(state>>2)&1);

    scanf(" %c",&input);
    if(input=='O'){
        Otimes+=1;
    }
    if(Otimes==3){
        state=0;
        Otimes=0;
    }
    input=check(input);
    state=state<<input|1<<(input-1);
    //printf("%d %d %d\n",state&1,(state>>1)&1,(state>>2)&1);
    printf("%d\n",state&1);
    printf("%d\n",(state>>1)&1);
    printf("%d\n",(state>>2)&1);

    //printf("%d\n",Otimes);
    return 0;
}
void check(char x){
    if(x == 'H'){
        x=(int)x;
        x-=68;
    }
    else if(x!='O'){
        x=(int)x;
        x-=48;
    }
    else{
        x=(int)x;
        x-=79;
    }
    return x;
}
