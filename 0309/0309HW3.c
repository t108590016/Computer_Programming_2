#include <stdio.h>
int main(){
    int i,j,name[3],time[3][3],hour[3];
    for(i=0;i<3;i++){
        scanf("%d",&name[i]);
        scanf("%d",&hour[i]);
        for(j=0;j<hour[i];j++){
            scanf("%d",&time[i][j]);
        }
    }
    conflict(name[0],name[1],time[0],time[1],hour[0],hour[1]);
    conflict(name[1],name[2],time[1],time[2],hour[1],hour[2]);
    conflict(name[0],name[2],time[0],time[2],hour[0],hour[2]);
}
void conflict(int name1,int name2,int time1[3],int time2[3],int hour1,int hour2){
    int i,j;
    for(i=0;i<hour1;i++){
        for(j=0;j<hour2;j++){
            if(time1[i]==time2[j]){
                printf("%d and %d conflict on %d ",name1,name2,time1[i]);
            }
        }
    }
    return 0;
}
