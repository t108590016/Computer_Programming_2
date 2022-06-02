#include <stdio.h>
int main(){
    int a,b,c,d,e; //a代表網內語音通話，b代表網外語音通話，c代表市話，d代表網內簡訊數，e代表網外簡訊數
    double w1,w2,w3; //w1代表183型，w2代表383型，w3代表983型
    double p1[4]={0.08,0.1393,0.1349,1.1287,1.4803},p2[4]={0.07,0.1304,0.1217,1.1127,1.2458},p3[4]={0.06,0.1087,0.1018,0.9572,1.1243};
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);
    scanf("%d",&e);
    w1=a*0.08+b*0.1393+c*0.1349+d*1.1287+e*1.4803;
    if(w1<183){
        w1=183;
    }
    w2=a*0.07+b*0.1304+c*0.1217+d*1.1127+e*1.2458;
    if(w2<383){
        w2=383;
    }
    w3=a*0.06+b*0.1087+c*0.1018+d*0.9572+e*1.1243;
    if(w3<983){
        w3=983;
    }
    if(w1<w2 && w1<w3){
        printf("183型");
    }
    else if(w2<w1 && w2<w3){
        printf("383型");
    }
    else{
        printf("983型");
    }
    return 0;

}
