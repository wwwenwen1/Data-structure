#include <stdio.h>

#define MaxSize 10     //通过宏定义来声明变量

typedef struct{
	int array[MaxSize];
	int length;
}StaticList;                     
//静态分配

void InitList(StaticList* L){
	for(int i=0;i<MaxSize-1;i++){
		L->array[i] = 0;
	}
	L->length = 0;
}
//初始化顺序表

void PrintList(StaticList* L){
	for(int i=0;i<MaxSize-1;i++){
		printf("array[%d] = %d\n",i,L->array[i]);
	}
}
//打印顺序表

int main(){
	StaticList L;
	InitList(&L);
	PrintList(&L);
}

