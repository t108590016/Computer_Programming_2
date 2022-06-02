#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _tree{
	char data;
	struct _tree *left;
	struct _tree *right;
}tree;
typedef tree* btree;
typedef struct _list{
	char data;
	struct _list *next;
}list;
typedef list* listp;
btree createtree(char data){
	btree newtree;
	newtree=(btree)malloc(sizeof(tree));
	newtree->left=NULL;
	newtree->right=NULL;
	newtree->data=data;
	return newtree;
}
listp createlist(char data){
	listp newlist;
	newlist=(listp)malloc(sizeof(list));
	newlist->next=NULL;
	newlist->data=data;
	return newlist;
}
void insertback(listp *p,char data){
	listp current,newlist;
	newlist=(listp)malloc(sizeof(list));
	newlist->data=data;
	if(*p==NULL){
		newlist->next=NULL;
		*p=newlist;
	}
	else{
		current=*p;
		while(1){
			if(current->next==NULL){
				newlist->next=NULL;
				current->next=newlist;
				break;
			}
			current=current->next;
		}
	}
}

listp assignment(listp root,char datatype[]){
	int i,j,a;
	for(i=0;i<strlen(datatype);i++){
		insertback(&root,datatype[i]);
	}
	return root;
}
listp findleft(listp root,char data){
	listp newlist=NULL;
	while(root->data!=data){
		insertback(&newlist,root->data);
		root=root->next;
	}
	return newlist;
}
listp findright(listp root,char data){
	listp newlist=NULL;
	while(root->data!=data){
		root=root->next;
	}
	root=root->next;
	while(root!=NULL){
		insertback(&newlist,root->data);
		root=root->next;
	}
	return newlist;
}
listp findleftP(listp list,int leftnum,int rightnum){
	listp newlist=NULL;
	int i,j,a;
	for(i=0;i<leftnum;i++){
		insertback(&newlist,list->data);
		list=list->next;
	}
	return newlist;
}
listp findrightP(listp list,int leftnum,int rightnum){
	listp newlist=NULL;
	int i,j,a;
	for(i=0;i<leftnum;i++){
		list=list->next;
	}
	for(i=0;i<rightnum;i++){
		insertback(&newlist,list->data);
		list=list->next;
	}
	return newlist;
}
char findbackdata(listp list){
	while(list->next!=NULL){
		list=list->next;
	}
	return list->data;
}
btree findtree(btree tree,char data){
	btree newtree=NULL;
	if(tree==NULL) return newtree;
	else if(tree->data==data){
		newtree=createtree(data);
		newtree->left=tree->left;
		newtree->right=tree->right;
		return newtree;
	}
	else{
		newtree=findtree(tree->left,data);
		if(newtree!=NULL)return newtree;
		newtree=findtree(tree->right,data);
		if(newtree!=NULL)return newtree;
	}
}
listp deletefirst(listp list){
	listp newlist=list->next;
	free(list);
	return newlist;
}
listp deleteback(listp list,int num){
	listp newlist=NULL;
	int i,j,a;
	if(num==1)return newlist;
	else{
		for(i=0;i<num-1;i++){
			insertback(&newlist,list->data);
			list=list->next;
		}
		return newlist;
	}
}
int countlist(listp list){
	int i,j=0;
	while(list!=NULL){
		j++;
		list=list->next;
	}
	return j;
}

void printlist(listp list){
	while(list!=NULL){
		printf("%c ",list->data);
		list=list->next;
	}
	printf("\n");
}


void levelorder(btree tree,int num){
	int i=0;
	listp list=NULL;
	insertback(&list,tree->data);
	btree TREE=NULL,TREEleft=NULL,TREEright=NULL;
	while(i<num){
		printf("%c",list->data);
		TREE=findtree(tree,list->data);
		if(TREE->left!=NULL) {
			TREEleft=TREE->left;
			insertback(&list,TREEleft->data);
		}
		if(TREE->right!=NULL) {
			TREEright=TREE->right;
			insertback(&list,TREEright->data);
		}
		list=list->next;
		i++;
	}
}
void makebinarytree1(listp O,listp I,btree *tree){
	char start;
	int leftnum,rightnum,Onum;
	btree TREE=NULL;
	listp leftI=NULL,rightI=NULL,leftO=NULL,rightO=NULL;
	if(countlist(O)==1){
		*tree=createtree(O->data);
	}
	else{
		start=findbackdata(O); //findbackdata
		Onum=countlist(O);
		O=deleteback(O,Onum);
		*tree=createtree(start);
		leftI=findleft(I,start);
		rightI=findright(I,start);
		leftnum=countlist(leftI);
		rightnum=countlist(rightI);
		leftO=findleftP(O,leftnum,rightnum);
		rightO=findrightP(O,leftnum,rightnum);
		if(leftnum!=0) makebinarytree1(leftO,leftI,&((*tree)->left));
		if(rightnum!=0) makebinarytree1(rightO,rightI,&((*tree)->right));
	}
}
void makebinarytree2(listp P,listp I,btree *tree){
	char start;
	int leftnum,rightnum;
	btree TREE=NULL;
	listp leftI=NULL,rightI=NULL,leftP=NULL,rightP=NULL;
	if(countlist(P)==1){
		*tree=createtree(P->data);
	}
	else{
		start=P->data;
		P=deletefirst(P);
		*tree=createtree(start);
		leftI=findleft(I,start);
		rightI=findright(I,start);
		leftnum=countlist(leftI);
		rightnum=countlist(rightI);
		leftP=findleftP(P,leftnum,rightnum);
		rightP=findrightP(P,leftnum,rightnum);
		if(leftnum!=0) makebinarytree2(leftP,leftI,&((*tree)->left));
		if(rightnum!=0) makebinarytree2(rightP,rightI,&((*tree)->right));
	}
}

void inorder(btree root){
	if(root!=NULL){
		inorder(root->left);
		printf("%c ",root->data);
		inorder(root->right);
	}
}
int main(){
	btree TREE=NULL;
	listp P=NULL,I=NULL,O=NULL;
	int i,j,a;
	int num;
	char input[2],one[100],two[100];

	for(i=0;i<2;i++){
		scanf("%c",&input[i]);
		getchar();
		if(i==0) {
			scanf("%[^\n]",one);
			getchar();
		}
		else {
			scanf("%[^\n]",two);
			getchar();
		}
	}
	for(i=0;i<2;i++){
        if(input[i]=='P'){
            if(i==0)P=assignment(P,one);
            else P=assignment(P,two);
        }
        else if(input[i]=='I'){
            if(i==0)I=assignment(I,one);
            else I=assignment(I,two);
        }
        else{
            if(i==0)O=assignment(O,one);
            else O=assignment(O,two);
        }
	}
	num=countlist(I);
	if (P==NULL){
		makebinarytree1(O,I,&TREE);
	}
	else if (O==NULL){
		makebinarytree2(P,I,&TREE);
	}
	levelorder(TREE,num);
	return 0;
}
