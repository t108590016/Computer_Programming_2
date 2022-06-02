#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _tree {
	int data;
	struct _tree *left;
	struct _tree *right;
} tree;
typedef tree* btree;
btree createtree(int data) {
	btree newtree;
	newtree=(btree)malloc(sizeof(tree));
	newtree->data=data;
	newtree->left=NULL;
	newtree->right=NULL;
	return newtree;
}
void inserttree(btree *TREE,int data) {
	btree newtree=createtree(data);
	if(*TREE==NULL) {
		*TREE=newtree;
	} else {
		btree current=*TREE;
		while(1) {
			if(data<current->data) {
				if(current->left==NULL) {
					current->left=newtree;
					break;
				}
				current=current->left;
			} else {
				if(current->right==NULL) {
					current->right=newtree;
					break;
				}
				current=current->right;
			}
		}
	}
}
void preorder(btree TREE,int *num) {
	if(TREE!=NULL) {
		printf("%d",TREE->data);
		if(*num!=0)printf(",");
		*num=*num-1;
		preorder(TREE->left,num);
		preorder(TREE->right,num);
	}
}
void inorder(btree TREE,int *num) {
	if(TREE!=NULL) {
		inorder(TREE->left,num);
		printf("%d",TREE->data);
		if(*num!=0)printf(",");
		*num=*num-1;
		inorder(TREE->right,num);
	}
}
void postorder(btree TREE,int *num) {
	if(TREE!=NULL) {
		postorder(TREE->left,num);
		postorder(TREE->right,num);
		printf("%d",TREE->data);
		if(*num!=0)printf(",");
		*num=*num-1;
	}
}
btree findtree(btree tree,int data) {
	btree newtree=NULL;
	if(tree==NULL) return newtree;
	else if(tree->data==data) {
		newtree=createtree(data);
		newtree->left=tree->left;
		newtree->right=tree->right;
		return newtree;
	} else {
		newtree=findtree(tree->left,data);
		if(newtree!=NULL)return newtree;
		newtree=findtree(tree->right,data);
		if(newtree!=NULL)return newtree;
	}
}
void findbiggest(btree tree,int *data) {
	if(tree!=NULL) {
		if(tree->data>*data)*data=tree->data;
		findbiggest(tree->left,data);
		findbiggest(tree->right,data);
	}
}
void findsmallest(btree tree,int *data) {
	if(tree!=NULL) {
		if(tree->data<*data)*data=tree->data;
		findsmallest(tree->left,data);
		findsmallest(tree->right,data);
	}
}
int findleftleaf(btree tree,int list[],int *changeitem) {
	int max=tree->data;
	findbiggest(tree,&max);
	btree change=findtree(tree,max);
	if(change->left==NULL&&change->right==NULL) {
		*changeitem=max;
		return 1;
	}
}
int findrightleaf(btree tree,int list[],int *changeitem) {
	int min=tree->data;
	findsmallest(tree,&min);
	btree change=findtree(tree,min);
	if(change->left==NULL&&change->right==NULL) {
		*changeitem=min;
		return 1;
	}
}
int findnonleftleaf(btree tree,btree *changetree,int list[],int *changeitem){
	int max=tree->data;
	findbiggest(tree,&max);
	*changetree=findtree(tree,max);
	btree change=*changetree;
	if(change->left!=NULL||change->right!=NULL) {
		*changeitem=max;
		return 1;
	}
}
int findnonrightleaf(btree tree,btree *changetree,int list[],int *changeitem){
	int min=tree->data;
	findsmallest(tree,&min);
	*changetree=findtree(tree,min);
	btree change=*changetree;
	if(change->left!=NULL||change->right!=NULL) {
		*changeitem=min;
		return 1;
	}
}
void deleteleaf(btree *tree,btree *pre,int data) {
	btree current=*tree;
	btree previous=*pre;
	if(current!=NULL) {
		if(current->data==data){
			if(previous->data>current->data)previous->left=NULL;
			else if(previous->data<current->data)previous->right=NULL;
			free(current);
		}
		else {
			deleteleaf(&current->left,&current,data);
			deleteleaf(&current->right,&current,data);
		}
	}
}

void deleteparent(btree *tree,btree *pre,btree changetree,int data){
	btree current=*tree;
	btree previous=*pre;
	if(current!=NULL) {
		if(current->data==data){
			if(previous->data>current->data)previous->left=changetree->left;
			else if(previous->data<current->data)previous->right=changetree->left;
			free(current);
		}
		else {
			deleteparent(&current->left,&current,changetree,data);
			deleteparent(&current->right,&current,changetree,data);
		}
	}
}

void deleteparent1(btree *tree,btree *pre,btree changetree,int data){
	btree current=*tree;
	btree previous=*pre;
	if(current!=NULL) {
		if(current->data==data){
			if(previous->data>current->data)previous->left=changetree->right;
			else if(previous->data<current->data)previous->right=changetree->right;
			free(current);
		}
		else {
			deleteparent1(&current->left,&current,changetree,data);
			deleteparent1(&current->right,&current,changetree,data);
		}
	}
}
void deletetree(btree *TREE,int data) {
	btree current=*TREE;
	btree previous=*TREE;
	btree changetree=NULL;
	int ans[100]= {},check=0,changeitem;
	while(current!=NULL) {
		if(current->data==data) {
			if(current->left==NULL&&current->right==NULL) {
				if(previous->data>current->data)previous->left=NULL;
				else if(previous->data<current->data)previous->right=NULL;
				free(current);
				break;
			}
			else {
				if(current->left!=NULL){
					check=findleftleaf(current->left,ans,&changeitem);
					if(check==1) {
						deleteleaf(TREE,TREE,changeitem);
						current->data=changeitem;
						break;
					}
					check=0; //有問題 65,70 刪65*/
				}
				check=findrightleaf(current->right,ans,&changeitem);
				if(check==1) {
					deleteleaf(TREE,TREE,changeitem);
					current->data=changeitem;
					break;
				}
				check=0;
				if(current->left!=NULL){
					check=findnonleftleaf(current->left,&changetree,ans,&changeitem);
					if(check==1) {
						deleteparent(TREE,TREE,changetree,changeitem); //原本指到changeitem 改成指到changetree;
						current->data=changeitem;
						break;
					}
					check=0;
				}
				check=findnonrightleaf(current->right,&changetree,ans,&changeitem);
				if(check==1) {
					deleteparent1(TREE,TREE,changetree,changeitem); //原本指到changeitem 改成指到changetree;
					current->data=changeitem;
					break;
				}
				check=0;
			}
		}
		else {
			if(data<current->data) {
				previous=current;
				current=current->left;
			} else if(data>current->data) {
				previous=current;
				current=current->right;
			}
		}
	}
}
int main() {
	btree TREE=NULL;
	int i=0,j=0;
	int a,deletedata,c,num;
	int input[100]={};
	while(1) {
		j++;
		scanf("%d",&input[i]);
		c=getchar();
		if(c==10)break;
		i++;
	}
	scanf("%d",&deletedata);
	getchar();
	for(i=0; i<j; i++) {
		inserttree(&TREE,input[i]);
	}
	num=j-2;
	deletetree(&TREE,deletedata);
	printf("preorder:");
	preorder(TREE,&num);
	printf("\n");
	num=j-2;
	printf("inorder:");
	inorder(TREE,&num);
	printf("\n");
	num=j-2;
	printf("postorder:");
	postorder(TREE,&num);
	return 0;

}
