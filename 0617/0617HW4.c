#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct _list{
	char name1[100];
	int age,birth[3];
	struct _list *next;
}list;
typedef list* listp;
void insertfront(listp *p,char name1[],int age,int birth[]){
	int i,j,a;
	listp newlist;
	newlist=(listp)malloc(sizeof(list));
	strcpy(newlist->name1,name1);
	newlist->age=age;
	for(i=0;i<3;i++)newlist->birth[i]=birth[i];
	if(*p==NULL){
		newlist->next=NULL;
		*p=newlist;
	}
	else {
		newlist->next=*p;
		*p=newlist;
	}
}
void insertback(listp *p,char name1[],int age,int birth[]){
	int i,j,a;
	listp current,newlist;
	newlist=(listp)malloc(sizeof(list));
	newlist->next=NULL;
	newlist->age=age;
	for(i=0;i<3;i++){
		newlist->birth[i]=birth[i];
	}
	strcpy(newlist->name1,name1);
	if(*p==NULL){
		*p=newlist;
	}
	else{
		current=*p;
		while(1){
			if(current->next==NULL){
				current->next=newlist;
				break;
			}
			current=current->next;
		}
	}
}
int main(){
	int i,j,a,input=4,input2;
	listp temp=NULL,temp2=NULL;
	while(1){
		char inputname1[100]={};
		int inputage=0,inputbirth[3]={};
		scanf(" %d",&input);
		if(input==3){
			break;
		}
		else if(input==1){
            /*
            char s[20];
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
            strcpy(inputname1,s);
            */
			scanf(" \"%[^\"]",&inputname1);
			getchar();
			scanf(" %d",&inputage);
			for(i=0;i<3;i++)scanf(" %d",&inputbirth[i]);
			insertback(&temp,inputname1,inputage,inputbirth);
		}
		else if(input==2){
			scanf(" %d",&input2);
			if(temp==NULL){
				printf("The Queue is empty\n");
				continue;
			}
            else{
                if(input2==1){
					printf("%s\n",temp->name1);
					temp2=temp;
					free(temp);
					temp=temp2->next;
                }
                else if(input2==2){
					printf("%d\n",temp->age);
					temp2=temp;
					free(temp);
					temp=temp2->next;
                }
                else{
					printf("%d_%d_%d\n",temp->birth[0],temp->birth[1],temp->birth[2]);
					temp2=temp;
					free(temp);
					temp=temp2->next;
                }
            }
		}
	}
	return 0;
}
