#include <stdio.h>
#include <string.h>
int main(){
    char x1[2],x2[2],x3[2],y1[2],y2[2],y3[2];
    double score_x=0,score_y=0;
    scanf("%s",&x1);
    if(x1[0]=='J'||x1[0]=='Q'||x1[0]=='K'){
        score_x+=0.5;
    }
    scanf("%s",&x2);
    if(x2[0]=='J'||x2[0]=='Q'||x2[0]=='K'){
        score_x+=0.5;
    }
    scanf("%s",&x3);
    if(x3[0]=='J'||x3[0]=='Q'||x3[0]=='K'){
        score_x+=0.5;
    }
    scanf("%s",&y1);
    if(y1[0]=='J'||y1[0]=='Q'||y1[0]=='K'){
        score_y+=0.5;
    }
    scanf("%s",&y2);
    if(y2[0]=='J'||y2[0]=='Q'||y2[0]=='K'){
        score_y+=0.5;
    }
    scanf("%s",&y3);
    if(y3[0]=='J'||y3[0]=='Q'||y3[0]=='K'){
        score_y+=0.5;
    }
    score_x=score_x+check(x1)+check(x2)+check(x3);
    score_y=score_y+check(y1)+check(y2)+check(y3);
    if(score_x>10.5){
        score_x=0;
    }
    if(score_y>10.5){
        score_y=0;
    }
    printf("%.1lf\n",score_x);
    printf("%.1lf\n",score_y);
    if((10.5-score_x)<(10.5-score_y)){
        printf("A贏");
    }
    else if((10.5-score_x)>(10.5-score_y)){
        printf("B贏");
    }
    else{
        printf("平手");
    }
    return 0;
}

int check(char s[2]){
    if(s[0]=='A'){
        return 1;
    }
    else if(s[0]=='1' && s[1]=='0'){
        return 10;
    }
    else if(s[0]=='J'||s[0]=='Q'||s[0]=='K'){
        return 0;
    }
    else{
        return (int)s[0]-48;
    }
}
