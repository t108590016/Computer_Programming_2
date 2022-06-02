#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct info{
    char name[20];
    int age;
    int year;
    int month;
    int day;
}info_t;
struct node {
    //info_t data;
    char name[20];
    int age;
    int year;
    int month;
    int day;
    struct node *next;
};

typedef struct node Node;
Node* creates(void);         // 建立堆疊
int isEmpty(Node*);           // 堆疊已空
void stacktop_name(Node*);   // 傳回頂端元素
void stacktop_age(Node*);   // 傳回頂端元素
void stacktop_birthday(Node*);   // 傳回頂端元素
Node* add(Node*,info_t);   // 新增元素
Node* delete(Node*);     // 刪除元素

int main(void) {
    Node* sTop;
    int input, select=0;
    int select2;
    sTop = creates();

    while(select!=3) {
        scanf("%d", &select);
        if(select==1){
            info_t input;
            char temp;
            char s[100];
            char name[20];
            int age,year,month,day;
            int time=0,count=0;

            while(time<2){
                scanf("%c",&temp);
                if(temp=='"')time++;
                if(time==1&&temp!='"'){
                    s[count]=temp;
                    count++;
                }
            }
            s[count]='\0';
            strcpy(input.name,s);

            scanf("%d",&input.age);
            scanf("%d",&input.year);
            scanf("%d",&input.month);
            scanf("%d",&input.day);
            sTop=add(sTop,input);
        }
        else{
            scanf("%d",&select2);
            if(!isEmpty(sTop)){
                if(select2==1) stacktop_name(sTop);
                if(select2==2) stacktop_age(sTop);
                else stacktop_birthday(sTop);
            }
            else{
                printf("The Stack is empty\n");
            }
            sTop = delete(sTop);
        }
    }

    printf("\n");

    return 0;
}

Node* creates() {
    return NULL;
}

int isEmpty(Node* top) {
    return (top == NULL);
}

void stacktop_name(Node* top) {
    printf("%s\n",top->name);
}
void stacktop_age(Node* top) {
    printf("%d\n",top->age);
}
void stacktop_birthday(Node* top) {
    printf("%d_%d_%d\n",top->year,top->month,top->day);
}
Node* add(Node* top,info_t input) {
    Node* newnode;
    newnode = (Node*) malloc(sizeof(Node));
    /*
    if(newnode == NULL) {
        printf("\n記憶體配置失敗！");
        exit(1);
    }
    */
    while(newnode->name!='\0'){
        newnode->name = input.name;
    }

    newnode->age=input.age;
    newnode->year=input.year;
    newnode->month=input.month;
    newnode->day=input.day;
    newnode->next = top;
    top = newnode;
    return top;
}

Node* delete(Node* top) {
    Node* tmpnode;

    tmpnode = top;
    top = top->next;
    free(tmpnode);

    return top;
}

