#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
typedef struct stack{
    int* array;
    int top;
    int capacity;
}SeqStack;

int initStack(SeqStack *S,int size){
    S->top = -1;
    S->array = (int*)malloc(size * sizeof(int));
    if(S->array == NULL){
        printf("Memory allocation failed.\n");
        return 1; 
    }
    S->capacity=size;
    return 0;
}

//判断栈是否为空
int isEmpty(SeqStack S){
    if(S.top==-1)
        return 1;
    else
        return 0;
}
//判断栈是否满
int isFull(SeqStack S){
    if(S.top==S.capacity-1)
        return 1;
    else
        return 0;
}
//拓展容量
void increaseCapacity(SeqStack* S,int size){
    int *temp=S->array;
    S->array=(int*)malloc((S->capacity+size)*sizeof(int));
    for(int i=0;i<S->capacity;i++){
        S->array[i]=temp[i];
    }
    S->capacity+=size;
    free(temp);
}
//出栈
int pop(SeqStack* S){
    if(isEmpty){
        printf("栈空，没有值\n");
        return 1;
    }
    else
        return S->array[S->top--];
}
//进栈
int push(SeqStack *S,int value){
    if(isEmpty){
        printf("栈满，无法插入\n");
        return 1;
    }
    else{
        S->array[++S->top]=value;
        return 0;
    }
}
//查栈顶元素值
int getTop(){

}
void DestroyStack(){

}
