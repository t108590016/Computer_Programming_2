#include <stdio.h>
#include <string.h>

void Game(int count_times,char required_data[100],int m){
    int Otimes=0,i,state=0,score=0,address=0,input,a=0,b=0;
    //printf("%s\n",required_data);
    for(i=0;i<count_times;i++){
        if(required_data[i]=='O'){
            input=0;
            Otimes+=1;
        }
        else if(required_data[i] == 'H')
            input=4;
        else
            input=required_data[i]-'0';
        if(address>0) address+=input;
        //printf("input=%d\n",input);
        state=state<<input|1<<(input-1);
        //printf("%d %d %d %d %d %d %d\n",state&1,(state>>1)&1,(state>>2)&1,(state>>3)&1,(state>>4)&1,(state>>5)&1,(state>>6)&1);
        score+=(state>>3)&1;
        score+=(state>>4)&1;
        score+=(state>>5)&1;
        score+=(state>>6)&1;

        if((i+1)%9==m){
            if(required_data[i]!='O') a++;
            address=input;
            //printf("a=%d,b=%d\n",a,b);
        }
        if(address>=4){
            b++;
            address=0;
        }
        state=state&7;
        //printf("state=%d\n",state);
        //printf("score=%d\n",score);
        if(input=='O'){
            Otimes+=1;
        }
        if(Otimes==3){
            state=0;
            Otimes=0;
        }


    }
    printf("%d\n",score);
    printf("%d,%d",a,b);
    //printf("Total score=%d\n",score);
    //printf("state=",state);
    //printf("%d\n",Otimes);
}
int main(){
    int d,m,state,Otimes_total=0,count_required_data=0;;
    char input_data[100];
    int a,i,j,count=0;
    char arr[11][12],a_arr[9],required_data[100];
    for(i=0;i<11;i++){
        char input_data[6];
        memset(input_data,'\0',6);
        while(input_data[0]<'0' && input_data>'9')scanf("%c",&input_data[0]);
        arr[count][0]=input_data[0];
        if(count<9){
            for(j=1;j<=input_data[0]-'0';j++){
                scanf("%c",&input_data[j]);
                while(input_data[j]==' ') scanf("%c",&input_data[j]);
            }
        }
        strcpy(arr[i],input_data);
        //printf("count=%d\n,input_data=%s\n,arr[i]=%s\n",count,input_data,arr[i]);
        count++;
    }
    d=arr[9][0]-'0';
    m=arr[10][0]-'0';
    //printf("d=%d,m=%d",d,m);
    count=1;
    while(Otimes_total<d){
        for(i=0;i<9;i++){
            required_data[count_required_data]=arr[i][count];
            if(arr[i][count]=='O') Otimes_total++;
            if(Otimes_total>=d) break;
            count_required_data++;
        }
        count++;
    }
    //printf("Otimes_total=%d\ncount=%d\n%s\n",Otimes_total,count,required_data);
    Game(strlen(required_data),required_data,m);
    return 0;
}
