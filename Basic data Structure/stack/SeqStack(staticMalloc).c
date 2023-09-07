#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef struct stack{
    int data[MaxSize];  //数组存放栈中元素
    int top;            //栈顶指针
}SeqStack;               //SeqStack为结构体类型名，其变量类型为struct stack

//初始化栈
int initStack(SeqStack *S){ //因为要修改s的值，所以要传入结构体指针
    S->top = -1;           //->为结构体指针运算符，s->top等价于(*s).top
    return 0;
}

//判断栈是否为空
int isEmpty(SeqStack S){    //用int类型函数来代替bool类型，用1和0表示真和假
    if(S.top == -1){       //栈空时，top为-1
        return 1;
    }
    else{
        return 0;
    }
}

//判断栈是否为满
int isFull(SeqStack S){  //用int类型函数来代替bool类型，用1和0表示真和假
    if(S.top == MaxSize - 1){   //栈满时，top为MaxSize - 1
        return 1;
    }
    else{
        return 0;
    }
}

//进栈
int push(SeqStack *S, int insertValue){
    if(isFull(*S)){                       //栈满时，不能进栈
        printf("栈满，不能进栈\n");
        return 1;
    }
    else{
        S->top++;                         //栈顶指针加1
        S->data[S->top] = insertValue;    //也可将两句合并为S->data[++S->top] = insertValue;
        return 0;
    }
    return 1;
}

//出栈
int pop(SeqStack *S){ 
    if(isEmpty(*S)){
        printf("栈空，无法出栈\n");
        return 1;
    }
    else{
        S->top--;                         //栈顶指针减1
        return S->data[S->top + 1];       //也可将两句合并为return S->data[S->top--];
    }
}

//获取栈顶元素
int getTop(SeqStack S){
    if(isEmpty(S)){
        printf("栈空，无元素\n");
        return 1;
    }
    else{
        return S.data[S.top];
    }
}

int main(){
    SeqStack S;
    initStack(&S);
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
     printf("now top is %d\n", getTop(S));
    printf("remove %d\n", pop(&S));
    printf("now top is %d\n", getTop(S));
    printf("remove %d\n", pop(&S));
    printf("now top is %d\n", getTop(S));
    printf("remove %d\n", pop(&S));
    printf("now top is %d\n", getTop(S));
    
    return 0;
}