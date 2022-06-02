#include <stdio.h>
#include <string.h>
int function(int arr[10][10]) {
	int x,y,i,j,count0=0,count1=0,Possibility_count=0,temp1=-1,temp2=-1;
	for (y=0;y<6;y++) {
		for (x=0;x<10;x++) {
			count1=count0=0;
			temp2=-1;
			for (i=y;i<y+5;i++) {
				if (arr[i][x]==1) count1++;
				else {
					count0++;
					temp2=i;
				}
				if (count0==2) break;
			}
			if (count1==4) {
				if (temp2==-1) arr[i-1][x] = 2;
				else arr[temp2][x]=2;
				Possibility_count++;
			}
		}
	}
	for (y=0;y<10;y++) {
		for (x=0;x<6;x++) {
			count1=count0=0;
			temp1=-1;
			for (j=x;j<x+5;j ++) {
				if (arr[y][j]==1) count1++;
				else {
					count0++;
					temp1=j;
				}
				if (count0==2) break;
			}
			if (count1==4) {
				if (temp1==-1) arr[y][j-1] = 2;
				else arr[y][temp1] = 2;
				Possibility_count ++;
			}
		}
	}

	for (y=0;y<6;y++){
		for (x=0;x<6;x++) {
			count1=count0=0;
			temp1=temp2=-1;
			for (i=y,j=x;i<y+5 && j<x+5;i++,j++) {
				if (arr[i][j]==1) count1++;
				else {
					count0++;
					temp1=j;
					temp2=i;
				}
				if (count0==2) break;
			}
			if (count1==4) {
				if (temp1==-1) arr[i-1][j-1]=2;
				else arr[temp2][temp1] = 2;
				Possibility_count++;
			}

			count1=count0=0;
			temp1=temp2=-1;
			for (i=y,j=x+4;i<y+5 && j>=x;i++,j--) {
				if (arr[i][j]==1) count1++;
				else {
					count0++;
					temp1=j;
					temp2=i;
				}
				if (count0==2) break;
			}
			if (count1==4) {
				if (temp1==-1) arr[i-1][j+1]=2;
				else arr[temp2][temp1]=2;
				Possibility_count++;
			}
		}
	}
	return Possibility_count;
}

int main() {
	int input[10][10],i,j;
	for (i=0;i<10;i++){
        for (j=0;j<10;j++) scanf("%d",&input[i][j]);
	}
	int possibility=function(input);
	//printf("%d\n",possibility);
	if (possibility>0){
        for (i=0;i<10;i++){
            for (j=0;j<10;j++){
                if (input[i][j]==2) printf("%d %d\n", i, j);
            }
        }
	}
	else printf("impractical attempt!\n");

	return 0;
}
