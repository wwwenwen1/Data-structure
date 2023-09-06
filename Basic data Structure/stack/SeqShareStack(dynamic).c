#include<stdio.h>
#include<stdlib.h>

#define INITSIZE 10

typedef struct stack{
    int* array;
    int top1;
    int top2;
    int capacity;
}SeqShareStack;

int initstack(SeqShareStack* S){
    S->array=(int*)malloc(INITSIZE * sizeof(int));
    S->capacity = INITSIZE;
    S->top1=-1;
    S->top2=S->capacity;  //第二个指针指向数组的尾巴，0~19个位置，指向20

    return 0;
}

int isEmpty1(SeqShareStack S){
    if(S.top1==-1) 
        return 1;
    else 
        return 0;
}

int isEmpty2(SeqShareStack S){
    if(S.top2==S.capacity) 
        return 1;
    else 
        return 0;
}

int isFull1(SeqShareStack S){  //当两个栈顶指针相贴的时候，就是栈满的时候
    if((S.top1+1)==S.top2)
        return 1;
    else
        return 0;
}

int isFull2(SeqShareStack S){  //当两个栈顶指针相贴的时候，就是栈满的时候
    if((S.top1+1)==S.top2)
        return 1;
    else
        return 0;
}

//isFull1和isFull2完全相同

int push1(SeqShareStack* S,int value){
    if(isFull1(*S)){
        printf("空间已满，%d无法入栈1\n",value);
        return 1;
    }
        S->top1++;
        S->array[S->top1]=value;
}

int push2(SeqShareStack* S,int value){
    if(isFull2(*S)){
        printf("空间已满，%d无法入栈2\n",value);
        return 1;
    }
        S->top2--;
        S->array[S->top2]=value;
        return 0;
}
//
int pop1(SeqShareStack* S){
    if(isEmpty1(*S)){
        printf("栈1为空。\n");
        return 0;
    }
    else{
        return S->array[S->top1--];
    }
}
//
int pop2(SeqShareStack* S){
    if(isEmpty2(*S)){
        printf("栈2为空。\n");
        return 0;
    }
    else
        return S->array[S->top2++];
}
//
int getTop1(SeqShareStack S){
    if(isEmpty1(S)){
        printf("栈1为空。\n");
        return 0;
    }
    else
        return S.array[S.top1];
}

int getTop2(SeqShareStack S){
    if(isEmpty2(S)){
        printf("栈2为空。\n");
        return 0;
    }
    else
        return S.array[S.top2];
}

int main(){
    SeqShareStack S;
    initstack(&S);
    push1(&S, 1);
    push1(&S, 2);
    push1(&S, 3);
    push1(&S, 4);
    push1(&S, 5);
    push2(&S, 6);
    push2(&S, 7);
    push2(&S, 8);
    push2(&S, 9);
    push2(&S, 0);
    push1(&S, 11);
    printf("now top1 is %d\n", getTop1(S));
    printf("remove top1 %d\n", pop1(&S));
    printf("now top1 is %d\n", getTop1(S));
    printf("remove top1 %d\n", pop1(&S));
    printf("now top1 is %d\n", getTop1(S));
    printf("remove top1 %d\n", pop1(&S));
    printf("now top1 is %d\n", getTop1(S));
    printf("================================\n");
    printf("now top2 is %d\n", getTop2(S));
    printf("remove top2 %d\n", pop2(&S));
    printf("now top2 is %d\n", getTop2(S));
    printf("remove top2 %d\n", pop2(&S));
    printf("now top2 is %d\n", getTop2(S));
    printf("remove top2 %d\n", pop2(&S));
    printf("now top2 is %d\n", getTop2(S));
    return 0;
}