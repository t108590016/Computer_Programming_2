#include <stdio.h>
#include <string.h>
int main(){
    int mode,i,j,carry=0,count=0,output[1000];
    int count_i=0,count_j=0;
    char input1[100],input2[100],n1[100],n2[100],re[100];
    scanf("%d",&mode);
    scanf("%s",&input1);
    scanf("%s",&input2);
    if(mode==1){
        if(strlen(input1)<strlen(input2)){
            strcpy(re,input1);
            strcpy(input1,input2);
            strcpy(input2,re);
        }
        count=0;
        for(i=strlen(input1)-1;i>=0;i--){
            output[count]=input1[i]-'0';
            count++;
        }
        count=0;
        for(i=strlen(input2)-1;i>=0;i--){
            output[count]=output[count]+(input2[i]-'0')+carry;
            carry=output[count]/10;
            output[count]=output[count]%10;
            count++;
        }
        count=strlen(input1);
        if(carry>0){
            count++;
            output[count-1]=carry;
        }
    }

    else if(mode==2){
        int negetive=0;
        //printf("%d %d\n",strlen(input1),strlen(input2));
        if(strlen(input1)<strlen(input2)){
            negetive=1;
            //printf("part1");
        }
        else if(strlen(input1)==strlen(input2)){
            for(i=0;i<strlen(input1);i++){
                if((input1[i]-'0')==(input2[i]-'0')) continue;
                else if((input1[i]-'0')<(input2[i]-'0')){
                    negetive=1;
                    break;
                }
                else{
                    negetive=0;
                    break;
                }
            }

        }
        if(negetive==1){
            printf("-");
            strcpy(re,input1);
            strcpy(input1,input2);
            strcpy(input2,re);
        }
        count=0;
        //printf("%s %s\n",input1,input2);

        for(i=strlen(input1)-1;i>=0;i--){
            output[count]=input1[i]-'0';
            count++;
        }
        count=0;
        for(i=strlen(input2)-1;i>=0;i--){
            //printf("%d-%d\n",output[count],(input2[i]-'0'));
            output[count]=output[count]-(input2[i]-'0');
            if(output[count]<0){
                output[count+1]--;
                output[count]+=10;
            }
            //printf("%d-%d\n",output[count],(input2[i]-'0'));
            count++;
        }
        count=strlen(input1);
    }
    else if(mode==3){
        for(i=0;i<strlen(input2)+strlen(input1);i++) output[i]=0;
        for(i=strlen(input2)-1;i>=0;i--){
            count_j=0;
            for(j=strlen(input1)-1;j>=0;j--){
                output[count_i+count_j]+=(input2[i]-'0')*(input1[j]-'0');
                //printf("output[%d+%d]=%d\n",count_i,count_j,output[count_i+count_j]);
                count_j++;
            }
            count_i++;
        }
        for(i=0;i<strlen(input1)+strlen(input2);i++){
            if(output[i]>=10){
                output[i+1]+=output[i]/10;
                output[i]=output[i]%10;
            }
        }
        count=count_i+count_j+1;
        //printf("%d %d\n",count_i,count_j);
    }
    int is_zero=1;

    for(i=count-1;i>=0;i--){
        if(output[i]!=0 && (output[i]>=0 && output[i]<=9)) is_zero=0;
        if(is_zero==0)
            if(output[i]>=0 && output[i]<=9)
                printf("%d",output[i]);
    }
    if(is_zero==1) printf("0");
    printf("\n");

    return 0;
}
