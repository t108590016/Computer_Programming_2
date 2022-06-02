#include <stdio.h>
int main(){
    int h1=0,h2=0,x=0; //x代表時薪，y代表最低工資
    float a=0,b=0,c=0,y=0; //a代表實際所得，b代表勞保費，c代表稅金
    scanf("%d",&h1);
    scanf("%d",&h2);
    scanf("%d",&x);
    scanf("%f",&y);

    b=y*0.05;
    c=(h1+h2)*x*0.08;
    a=(h1+h2)*x-b-c;

    printf("%.1f\n",a);
    printf("%.1f\n",b);
    printf("%.1f\n",c);


    return 0;
}

