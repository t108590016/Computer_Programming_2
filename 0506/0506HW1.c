#include <stdio.h>
#include <string.h>
int a[]={0};
int find(int input[10][10],int *exist,int level,int position_x,int position_y,int n,int distance,int record,int max){
    /*
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d  ",input[i][j]);
        }
        printf("\n");
    }
    */
    //printf("x=%d,y=%d,level=%d,distance=%d,record=%d\n",position_x,position_y,level,distance,record,max);
    exist[level]=position_y;
    int i,j;
    distance+=input[position_x][position_y];
    record+=position_y;
    //printf("x=%d,y=%d,level=%d,distance=%d,record=%d\n",position_x,position_y,level,distance,record,max);
    if(level==n-2 && record==max){
        int same=0;
        for(i=0;i<=level;i++){
            for(j=i+1;j<=level;j++) if(exist[i]==exist[j]) same=1;
        }
        if(same==0){
            if(*(a)==0 || *(a)>distance)  *(a)=distance;
            /*
            printf("x=%d,y=%d,distance=%d,record=%d\n",position_x,position_y,distance,record,max);
            printf("{");
            for(i=0;i<=level;i++){
                printf("%d, ",exist[i]);
            }
            printf("}\n");
            */
        }

    }
    else if(level<n-2){
        for(i=1;i<n;i++){

            if(i!=position_x) find(input,exist,level+1,position_y,i,n,distance,record,max);
        }
    }
    //else if(level==n-3) find(input,level+1,position_y,n-1,n,distance,record,max);

}
int main(){
    int n,i,j,max=0;
    scanf("%d",&n);
    int input[10][10],exist[10];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&input[i][j]);
        }
    }
    /*
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d  ",input[i][j]);
        }
        printf("\n");
    }
    */
    //find(input,0,1,0,n,0,0,max);

    for(i=0;i<n;i++) max+=i;
    //printf("max=%d\n",max);
    for(i=1;i<n;i++) find(input,exist,0,0,i,n,0,0,max);
    printf("%d\n",*(a));

    return 0;
}

