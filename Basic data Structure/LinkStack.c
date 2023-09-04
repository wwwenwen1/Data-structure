#include<stdio.h>
#include<stdlib.h>

//栈的链式存储使用无头结点的单链表
typedef struct node{
    int data;
    struct node *next;
}Lnode,*LinkStack;

/*等价于：
typedef struct node Lnode;
typedef struct node* LinkStack;
*/
//初始化栈
int initStack(LinkStack *pointerToList){
    
    return 0;
}

//判断栈是否为空
int isEmpty(LinkStack )