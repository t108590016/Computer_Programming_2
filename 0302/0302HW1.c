#include <stdio.h>
int main(){
    int a=0,b=0,c=0;
    double x1=0,x2=0;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    x1= ((-b)+sqrt(b*b-4*a*c))/(2*a);
    x2= ((-b)-sqrt(b*b-4*a*c))/(2*a);
    printf("%.1f\n",x1);
    printf("%.1f\n",x2);
    return 0;
}
