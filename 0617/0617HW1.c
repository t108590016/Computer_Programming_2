#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _list{
	int data;
	struct _list *next;
}list;
typedef list* listp;
listp create(int data){
	listp newlist;
	newlist=(listp)malloc(sizeof(list));
	newlist->data=data;
	newlist->next=NULL;
	return newlist;
}
void putdatainlist(listp *list,int num,int data){
	int i,n=0;
	listp current=*list;
	for(i=0;i<num;i++){
		current=current->next;
	}
	current->data+=data;
}
void insertfront(listp *p,int data){
	listp newlist=create(data);
	if((*p)==NULL){
		newlist->next=NULL;
		(*p)=newlist;
	}
	else{
		newlist->next=(*p);
		(*p)=newlist;
	}
}
void insertback(listp *p,int data){
	listp newlist=create(data);
	listp current=(*p);
	if((*p)==NULL){
		(*p)=newlist;
	}
	else{
		while(current->next!=NULL){
			current=current->next;
		}
		current->next=newlist;
	}
}
void makenull(listp *p,int num){
	int i;
	for(i=0;i<num;i++){
		insertfront(p,0);
	}
}

void align(listp *p,int num,int until){
	listp current=(*p);
	while(num!=until){
		insertback(&current,0);
		num++;
	}
}
void add(listp *p1,listp *p2,int n1,int n2,int nlarge,int ans[]){
	int i,j,a;
	listp func1=*p1;
	listp func2=*p2;
	for(i=0;i<nlarge;i++){
		ans[i]=func1->data+func2->data;
		func1=func1->next;
		func2=func2->next;
	}
}
void sub(listp *p1,listp *p2,int n1,int n2,int nlarge,int ans[]){
	int i,j,a;
	listp func1=*p1;
	listp func2=*p2;
	for(i=0;i<nlarge;i++){
		ans[i]=func1->data-func2->data;
		func1=func1->next;
		func2=func2->next;
	}
}
void mul(listp *p1,listp *p2,int n1,int n2,int nlarge,listp *ans){
	int i,j,a;
	listp func1=*p1;
	listp func2=*p2;
	for(i=0;i<nlarge;i++){
		for(j=0;j<nlarge;j++){
			putdatainlist(ans,99-(i+j),func1->data*func2->data);
			func2=func2->next;
		}
		func2=*p2;
		func1=func1->next;
	}
}


void print(int list[],int num){
	int a=1,i;
	for(i=num;i>=0;i--){
		if(list[i]!=0)a=0;
		if(a==1&&i==0)printf("%d",0);
		if(a==1)continue;
		printf("%d ",list[i]);
	}
	printf("\n");
}
void printlist(listp list){
	int a=0;
	while(list!=NULL){
		if(list->data!=0||a==1){
			printf("%d ",list->data);
			a=1;
			}
		if(list->next==NULL&&a==0)printf("0");
		list=list->next;

	}
	printf("\n");
}
int main(){
	int n,n1=0,n2=0;
	int c;
	int ans1[100]={},ans2[100]={};
	int i,j;
	listp func1=NULL,func2=NULL,ans3=NULL;
	int nlarge,a;
	makenull(&ans3,100);
	while(1){
		scanf(" %d",&n);
		insertfront(&func1,n);
		n1++;
		c=getchar();
		if(c==10)break;
	}
	while(1){
		scanf(" %d",&n);
		insertfront(&func2,n);
		n2++;
		c=getchar();
		if(c==10)break;
	}
	if(n1<n2){
		align(&func1,n1,n2);
		nlarge=n2;
	}
	else if(n2<n1){
		align(&func2,n2,n1);
		nlarge=n1;
	}
	else nlarge=n1;
	add(&func1,&func2,n1,n2,nlarge,ans1);
	print(ans1,nlarge-1);
	sub(&func1,&func2,n1,n2,nlarge,ans2);
	print(ans2,nlarge-1);
	mul(&func1,&func2,n1,n2,nlarge,&ans3);
	printlist(ans3);

	return 0;
}
