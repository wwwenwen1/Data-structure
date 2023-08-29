#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int* array;
	int length;
	int maxSize;
}DynamicList;
//动态分配

void InitList(DynamicList *L,int size){
	L->length = 0;
	L->maxSize = size;
	L->array = (int*)malloc(L->maxSize * sizeof(int));
	if (L->array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
	//判断是否成功分配内存
	}
	for(int i =0;i<L->maxSize;i++){
		L->array[i] = -1;
	}
}                                
//初始化顺序表

void IncreaseSize(DynamicList *L,int size){
	int *temp = L->array;
	L->array = (int*)malloc((L->maxSize + size)*sizeof(int));
	if(L->array == NULL){
		printf("memory increasion failed.\n");
		exit(1);                              
		//判断是否分配成功
	}
	for(int i=0;i<L->maxSize;i++){
	
		L->array[i] = temp[i];
		//printf("array[%d] = %d,temp[%d] = %d\n",i,L->array[i],i,temp[i]);
	}
	L->maxSize = L->maxSize + size;
	free(temp);        
}
//增加顺序表容量

void PrintList(DynamicList *L){
	for(int i=0;i < L->length;i++){
		printf("position %d : array[%d ] = %d \n",i+1,i,L->array[i]);
	}
	printf("--------------------\n");
}

void InsertAtBegin(DynamicList *L,int value){
	if(L->length >= L->maxSize){
		printf("List is full.Cannot insert.\n");
		return;
	}
	for(int i = L->length;i>0;i--){
		L->array[i] = L->array[i-1];
	}
	//从列表末尾开始把每一个元素移向后一个元素
	L->array[0] = value;
	L->length++;
}
//头插

void InsertAtEnd(DynamicList *L,int value){
	if(L->length >= L->maxSize){
		printf("List is full.Cannot insert.\n");
		return;
    }
	L->array[L->length] = value;
	L->length++;
}
//尾插

void InsertAtPosition(DynamicList *L,int value,int position){
	if((L->length >= L->maxSize) || (position > L->length + 1)){
		printf("Invalid position or list is full.Cannot insert.\n");
		return;
	}
	for(int i = L->length;i >= position;i--){
		L->array[i] = L->array[i-1];
	}
	L->array[position-1] = value;
	L->length++; 
}
//指定位置插入

void DeleteAtPosition(DynamicList *L,int position){ //position代表位序，position-1代表下标
	if(position > L->length){
		printf("Invalid position or list is empty.cannot delete.\n");
	}
	for(int i = position-1;i < L->length;i++){
		L->array[i] = L->array[i+1];
	}
	L->array[L->length] = -1;
	L->length--;
}
//指定位置删除

int FindAtPosition(DynamicList *L,int position){
	if(position > L->length){
		printf("Invalid position or list is empty.cannot find.\n");
	}
	printf("%d",L->array[position-1]);
	return L->array[position-1];
}

void DestroyList(DynamicList *L) {
    free(L->array);  // 释放顺序表的数组内存
    L->array = NULL; // 将指针置为 NULL，避免出现悬挂指针
    L->length = 0;   // 将顺序表长度置为 0
    L->maxSize = 0;  // 将顺序表最大容量置为 0
}

int main(){
	DynamicList L;
	InitList(&L,10);
	InsertAtBegin(&L,7);
	InsertAtEnd(&L,1);
	InsertAtPosition(&L,0,3); //插入到第三个元素的位置
	InsertAtEnd(&L,2);
	InsertAtEnd(&L,4);
	InsertAtEnd(&L,8);
	InsertAtEnd(&L,1);
	InsertAtEnd(&L,4);
	InsertAtEnd(&L,1);
	InsertAtEnd(&L,3);
	PrintList(&L);
	DeleteAtPosition(&L,6);
	PrintList(&L);
	
	FindAtPosition(&L,5);
	DestroyList(&L); 
	
	return 0;
}
