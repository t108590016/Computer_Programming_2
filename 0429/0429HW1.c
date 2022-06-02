#include <stdio.h>

int main(){
    int n,mode,arr[100][100],i,j,count=1;
    scanf("%d",&n);
    scanf("%d",&mode);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            arr[i][j]=count;
            count++;
        }
    }
    /*
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    */
    if(mode==1){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
    }
    else if(mode==2){
        for(i=0;i<n;i++){
            for(j=n-1;j>=0;j--){
                printf("%d ",arr[j][i]);
            }
            printf("\n");
        }
    }
    else if(mode==3){
        for(i=n-1;i>=0;i--){
            for(j=0;j<n;j++){
                printf("%d ",arr[j][i]);
            }
            printf("\n");
        }
    }
    else{
        for(i=n-1;i>=0;i--){
            for(j=0;j<n;j++){
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
