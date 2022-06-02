#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct stu{
    int name;
    float grade;
}stu_t;

int main(){
    char *G[]={"A+","A","A-","B+","B","B-","C+","C","C-","F"};
    char *GPA[]={"4.3","4.0","3.7","3.3","3.0","2.7","2.3","2.0","1.7","0"};
    char *S[]={"90-100","85-89","80-84","77-79","73-76","70-72","67-69","63-66","60-62","59以下"};
    float grade[10]={95.0,87.0,82.0,78.0,75.0,70.0,68.0,65.0,60.0,50.0};
    char *p[10];
    int M,N;
    int i,j,k;
    int index=0,max=0,x=0;
    scanf(" %d",&M);
    char *score_type[M][10];
    for(i=0;i<M;i++) scanf(" %s",score_type+i);
    scanf(" %d",&N);
    stu_t student[N];
    for(i=0;i<N;i++){
        scanf(" %d",&student[i].name);
        student[i].grade = 0;
        for(j=0;j<M;j++){
            scanf(" %s",p);
            if(strcmp(score_type+j,"G")==0){
                for(k=0;k<10;k++) if(strcmp(p,*(G+k))==0) index = k;
            }
            if(strcmp(score_type+j,"GPA")==0){
                for(k=0;k<10;k++) if(strcmp(p,*(GPA+k))==0) index = k;
            }
            if(strcmp(score_type+j,"S")==0){
                for(k=0;k<10;k++) if(strcmp(p,*(S+k))==0) index = k;
            }
            student[i].grade += grade[index];
        }
    }
    for(i=0;i<3;i++){
        max = 0;
        for(j=0;j<N;j++){
            if(max<student[j].grade){
                max=student[j].grade;
                index = j;
            }
        }
        x=round((student[index].grade)/M);
        printf("%d\n%d\n",student[index].name,x);
        student[index].grade = 0;
    }
    return 0;
}
