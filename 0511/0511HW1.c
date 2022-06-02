#include <stdio.h>
#include <string.h>
#define SIZE 128
#define swap(x, y){char* temp = x; x = y; y = temp;} //交換

typedef struct listPtr{
    char* list[SIZE];
    int size;
}listPtr;

void Add(listPtr* sum, const listPtr* s1, const listPtr* s2) { //加入
    int i;
    for (i=0;i<s1->size;i++)
        sum->list[sum->size++] = s1->list[i];
    for (i=0; i<s2->size;i++)
        sum->list[sum->size++] = s2->list[i];
}

void Remove(listPtr* list, int index) { //移除
    for (;index < list->size - 1; index++)
        list->list[index] = list->list[index + 1];
    list->list[list->size--] = NULL;
}

void Sort(listPtr* list) { //排序
    int i,j,min;
    for (i = 0; i < list->size - 1; i++) {
        min = i;
        for (j = i + 1; j < list->size; j++)
            if (strcmp(list->list[j], list->list[min]) < 0) min = j;
        swap(list->list[i], list->list[min]);
    }
}

void removeSame(listPtr* list) { //將相同元素移除
    int i,j;
    for (i=0;i<list->size-1;i++) {
        for (j=i+1;j<list->size;) {
            if (strcmp(list->list[i],list->list[j]) == 0)
                Remove(list, j); //如果相同，移除
            else j++;
        }
    }
    Sort(list); //將List排序
}
int isComplete(const listPtr* complete, const listPtr* s1, const listPtr* s2) { //最後判斷
    int i;
    listPtr sum = {{0}, 0};
    Add(&sum, s1, s2);
    removeSame(&sum);
    if (complete->size != sum.size || sum.size != s1->size + s2->size) return 0;
    for (i = 0; i < complete->size; i++)
        if (strcmp(complete->list[i], sum.list[i])) return 0;
    return 1;
}

void split(listPtr* r, char* String, const char symbol) { //分割字串
    int len,i;
    len = strlen(String);
    r->list[r->size++] = &String[0];
    for (i = 1; i < len; i++) {
        if (String[i] == symbol) {
            String[i]='\0';
            while (String[i+1] == symbol) i++;
            if(String[i+1] != '\0') r->list[r->size++] = &String[i+1];
        }
    }
}

int main() {
    char input[SIZE] = {0}, small[SIZE][SIZE]={0};
    listPtr InputStringSet = {{0}, 0}, smallStringSet[SIZE] = {{0}, 0};
    int totalSmall,count=0;
    int i,j;
    gets(input);
    split(&InputStringSet,input,' ');//分割
    removeSame(&InputStringSet);//將重複元素刪除
    scanf("%d\n", &totalSmall);
    for (i=0;i<totalSmall;i++) {
        gets(small[i]);
        split(&smallStringSet[i],small[i],' '); //分割
        removeSame(&smallStringSet[i]); //將重複元素刪除
    }
    for (i=0;i<totalSmall-1;i++) {
        for (j=i+1;j<totalSmall;j++)
            count+=isComplete(&InputStringSet,&smallStringSet[i],&smallStringSet[j]);
    }
    printf("%d\n", count);

	return 0;
}
