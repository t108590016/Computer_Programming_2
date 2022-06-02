#include <stdio.h>
#include <string.h>

int sort(char input_keyword[100][100],int keyword_len[100]){


}

int main(){
    char input_string[1000],P[100],Q[100],input_List[100][100],input_keyword[100][100];
    int i,j,k,l,count=0,count2=0,input_len[100],keyword_count[100],keyword_len[100],priority[100],pri[100][100],pri_count[100];
    gets(input_string);
    scanf("%s",&P);
    scanf("%s",&Q);
    for(i=0;i<strlen(input_string);i++){
        if(input_string[i]!=' ' && input_string!='\0'){
            input_List[count][count2]=input_string[i];
            count2++;
        }
        else if(input_string[i]==' '){
            input_len[count]=count2;
            count++;
            count2=0;
        }
    }
    if(count2>0) input_len[count]=count2;

    for(i=0;i<=count;i++){
        int same=0;
        if(strlen(P)==input_len[i]){
            for(j=0;j<input_len[i];j++)
                if(P[j]-input_List[i][j]==0) same++;
            if(same==strlen(P))
                for(j=0;j<strlen(Q);j++) printf("%c",Q[j]);
            else
                for(j=0;j<input_len[i];j++) printf("%c",input_List[i][j]);
        }
        else
            for(j=0;j<input_len[i];j++) printf("%c",input_List[i][j]);
        printf(" ");
    }
    printf("\n");
    for(i=0;i<=count;i++){
        int same=0;
        if(strlen(P)==input_len[i]){
            for(j=0;j<input_len[i];j++)
                if(P[j]-input_List[i][j]==0) same++;
            if(same==strlen(P)){
                for(j=0;j<strlen(Q);j++) printf("%c",Q[j]);
                printf(" ");
                for(j=0;j<input_len[i];j++) printf("%c",input_List[i][j]);
            }
            else
                for(j=0;j<input_len[i];j++) printf("%c",input_List[i][j]);
        }
        else
            for(j=0;j<input_len[i];j++) printf("%c",input_List[i][j]);
        printf(" ");
    }
    printf("\n");
    for(i=0;i<=count;i++){
        int same=0;
        if(strlen(P)==input_len[i]){
            for(j=0;j<input_len[i];j++)
                if(P[j]-input_List[i][j]==0) same++;
            if(same!=strlen(P)){
                for(j=0;j<input_len[i];j++) printf("%c",input_List[i][j]);
                //printf("%s ",input_List[i]);
                printf(" ");
            }
        }
        else{
            for(j=0;j<input_len[i];j++) printf("%c",input_List[i][j]);
            //printf("%s ",input_List[i]);
            printf(" ");
        }
    }


    for(i=0;i<count;i++) keyword_count[i]=0;
    int count3=1,end=0,same=0;
    for(i=0;i<=input_len[0];i++){
        input_keyword[0][i]=input_List[0][i];
    }
    keyword_len[0]=input_len[0];
    keyword_count[0]++;
    for(i=1;i<=count;i++){
        end=0;
        for(j=0;j<count3;j++){
            //printf("input_len=%d keyword_len=%d i=%d j=%d input=%s keyword=%s\n",input_len[i],keyword_len[j],i,j,input_List[i],input_keyword[j]);
            if(input_len[i]==keyword_len[j]){
                same=0;
                for(k=0;k<input_len[i];k++){
                    if(input_List[i][k]==input_keyword[j][k]) same++;
                }
                if(same==input_len[i]){
                    keyword_count[j]++;
                    end=1;
                }
                if(end==1) break;
            }
            else
                continue;
            //input_keyword[i][j]=input_List[i][j];
        }
        if(end!=1){

            for(j=0;j<input_len[i];j++){
                input_keyword[count3][j]=input_List[i][j];
            }
            keyword_len[count3]=input_len[i];
            keyword_count[count3]++;
            count3++;
        }
    }
    printf("\n");
    char temp[10];
    int count_temp,len_temp;
    memset(temp,'\0',10);
    for(i=0;i<count3;i++){
        for(j=i;j<count3;j++){
            if(strcmp(input_keyword[i],input_keyword[j])>0){
                strcpy(temp,input_keyword[i]);
                strcpy(input_keyword[i],input_keyword[j]);
                strcpy(input_keyword[j],temp);
                count_temp=keyword_count[i];
                keyword_count[i]=keyword_count[j];
                keyword_count[j]=count_temp;
                len_temp=keyword_len[i];
                keyword_len[i]=keyword_len[j];
                keyword_len[j]=len_temp;
            }
        }
    }
    int max=0;
    for(i=0;i<count3;i++){
        if(keyword_count[i]>max) max=keyword_count[i];
    }
    int count4=0,count5=0;
    while(max>0){
        for(i=0;i<count3;i++){
            if(keyword_count[i]==max){
                pri[count4][count5]=i;
                count5++;
            }
        }
        max--;
        pri_count[count4]=count5;
        count5=0;
        count4++;
    }

    for(i=0;i<count4;i++){
        for(j=0;j<pri_count[i];j++){
            printf("%s : %d\n",input_keyword[pri[i][j]],keyword_count[pri[i][j]]);
        }
    }
    return 0;
}
