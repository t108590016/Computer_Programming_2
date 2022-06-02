#include <stdio.h>
int main(){
    int n,arr[2][100000],i,j,len1,len2;
    unsigned int output=0;
    scanf("%d",&n);
    if(n%2==0){
        len1=n/2;
        len2=len1;
        for(i=0;i<2;i++){
            for(j=0;j<n/2;j++){
                scanf("%d",&arr[i][j]);
            }
        }
    }
    else{
        len1=n/2;
        len2=len1+1;
        for(i=0;i<len1;i++){
            scanf("%d",&arr[0][i]);
        }
        for(i=0;i<len2;i++){
            scanf("%d",&arr[1][i]);
        }
    }
    for(i=0;i<len1;i++){
        for(j=i;j<len1;j++){
            if(arr[0][i]>arr[0][j]) output++;
        }
    }
    for(i=0;i<len2;i++){
        for(j=i;j<len2;j++){
            if(arr[1][i]>arr[1][j]) output++;
        }
    }
    for(i=0;i<len1;i++){
        for(j=0;j<len2;j++){
            if(arr[0][i]>arr[1][j]) output++;
        }
    }
    printf("%d\n",output);
    return 0;
}
