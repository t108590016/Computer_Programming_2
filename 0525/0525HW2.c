#include <stdio.h>
#include <math.h>

double abs_function(double x){ //回傳絕對值
    if(x<0)  return -x;
    else  return x;
}
double f1(double a,double x){
    return sqrt(a-x*x);
}
double f2(double a,double x){
    return (a*x*x*x+7*x)/(sqrt(a+x));
}

int main(){
    char op='\0';
    int n=0,index=0;
    double a,p,q,err;
    double area1=0,area2=0;
    double i=0;
    scanf(" %c",&op);
    while(op!='0'){ //當op為0時結束
        n=0;
        scanf(" %lf",&a);
        scanf(" %lf",&p);
        scanf(" %lf",&q);
        scanf(" %lf",&err);
        if(op=='1'){
            do{
                area1=area2=0;
                index = 1;
                for(i=0;i<n;i++)  index*=2;
                for(i=p+(q-p)/index;i<q;i=i+(q-p)/index) area1+=abs_function(2*abs_function(f1(a,i)));
                index=index*2;
                for(i=p+(q-p)/index;i<q;i=i+(q-p)/index) area2 += abs_function(2*abs_function(f1(a,i)));
                area1 = abs_function((abs_function(f1(a,p))+abs_function(f1(a,q))+area1)*((q-p)/(index/2))/2);
                area2 = abs_function((abs_function(f1(a,p))+abs_function(f1(a,q))+area2)*((q-p)/index/2));
                n++;
            }while(abs_function((area2-area1))>pow(10,-err));
        }
        else{
            do{
                area1=area2=0;
                index = 1;
                for(i=0;i<n;i++)  index=index*2;
                for(i=p+(q-p)/index;i<q;i=i+(q-p)/index) area1 += abs_function(2*abs_function(f2(a,i)));
                index=index*2;
                for(i=p+(q-p)/index;i<q;i=i+(q-p)/index) area2 += abs_function(2*abs_function(f2(a,i)));
                area1 = abs_function((abs_function(f2(a,p))+abs_function(f2(a,q))+area1)*((q-p)/(index/2))/2);
                area2 = abs_function((abs_function(f2(a,p))+abs_function(f2(a,q))+area2)*((q-p)/index/2));
                n++;
            }while(abs_function((area2-area1))>pow(10,-err));
        }
        printf("%.12f\n",area2); //輸出小數後12位
        scanf(" %c",&op);
    }
    return 0;
}

