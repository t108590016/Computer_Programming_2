#include <stdio.h>
#include <string.h>

void input_eq_2(int arr[100][100],char input[1000],count,int position,int len,int n){
    int i,j;
    if(input[position+1]=='2'){
        for(i=1;i<=4;i++){
            len=len/2;
            if(input[position+1]!='2'){
                for(j=position_x;j<position_x+len;j++){
                    for(k=position_y;k<position_y;k++){
                        arr[j][k]=input[position]-'0';
                    }
                }
                count++;
            }
            else{
                input_eq_2(arr,input,count+1,po)
            }
        }
    }
    else{
        position+=len;
        for(i=position;i<len;i++){
            for(j=position;j<len;j++){
                arr[i][j]=input[position]-'0';
            }
        }
    }
    count++;
    if(count==4 ){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(arr[i][j]==1) printf("%d,%d\n",i,j);
            }
        }
    }
    input_eq_2(arr,input,count,position+1,len/2,n);
}

int main(){
    char input[1000],ip[100][100];
    int n,i,j,k,len=0,u,d,count,count2,input_equal_2=0;;
    scanf("%s",&input);
    scanf("%d",&n);
    int arr[n][n];
    if(input[0]!='2'){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                arr[i][j]=input[0]-'0';
            }
        }
    }
    else{
        arr=input_eq_2(arr,input,0,0,n/2,n);
        /*
        len=n/2;
        count=0;
        for(i=1;i<strlen(input);i++){
            if(input[i]!='2'){
                for(j=0;j<len;j++){
                    arr[count+(j/2)][j%2]=input[0]-'0';
                }
                count++;
            }
            else if(input[i]=='2'){
                len=n/2;
                for(j=1;j<=4;j++){
                    if(input[i+j]!='2')
                        for(k=0;j<len;j++){
                            arr[count+(k/2)][k%2]=input[i+j]-'0';
                        }
                }
                len=len*2;
            }
        }
        */

    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[i][j]==1) printf("%d,%d\n",i,j);
        }
    }
    return 0;
}
