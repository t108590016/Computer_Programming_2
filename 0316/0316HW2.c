#include <stdio.h>
int main(){
    int i,j,graph,n;
    scanf("%d", &graph);
    scanf("%d", &n);
    if(graph==1){
        for(i=1;i<=n;i++){
            print_j_positive(1,i);
            printf("\n");
        }
        for(i=n;i>=1;i--){
            print_j_negation(1,i);
            printf("\n");
        }
        for(i=1;i<=n;i++){
            print_mark_positive(1,i,i+'0');
            printf("\n");
        }
    }
    else if(graph==2){
        for(i=1;i<=n;i++){
            print_j_positive(1,i);
            print_j_negation(1,i-1);
            printf("\n");
        }
        for(i=1;i<n;i++){
            print_mark_positive(i,n-2,'_');
            print_j_negation(1,i);
            print_j_positive(2,i);
            print_mark_positive(i,n-2,'_');
            printf("\n");
        }
        for(i=n-1;i>=1;i--){
            print_mark_positive(i,n-2,'_');
            print_j_negation(1,i);
            print_j_positive(2,i);
            print_mark_positive(i,n-2,'_');
            printf("\n");
        }
    }
    return 0;
}
void print_j_positive(int start,int end){
    int i;
    for(i=start;i<=end;i++){
        printf("%d",i);
    }
}
void print_j_negation(int start,int end){
    int i;
    for(i=end;i>=start;i--){
        printf("%d",i);
    }
}
void print_mark_positive(int start,int end,char mark){
    int i;
    for(i=start;i<=end;i++){
        printf("%c",mark);
    }
}
void print_mark_negation(int start,int end,char mark){
    int i;
    for(i=end;i>=start;i--){
        printf("%c",mark);
    }
}
