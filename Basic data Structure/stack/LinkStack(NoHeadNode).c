#include<stdio.h>
#include<stdlib.h>

//栈的链式存储(无头结点的单链表)
//链表的第一个节点作为栈顶
typedef struct node{
    int data;
    struct node *next;
}SNode,*LinkStack;

/*等价于：
typedef struct node SNode;
typedef struct node* LinkStack; //指针类型为struct node的指针
*/
//初始化栈
//让头指针悬空
int initStack(LinkStack* ptrL){
    *ptrL=NULL;             //ptrL为指向指针的指针，*ptrL为指针(链栈头指针)
    return 0;
}

//判断栈是否为空
int isEmpty(LinkStack L){
    if(L==NULL)
        return 1;
    else
        return 0;
}
//链式栈不会满 无isFull

//入栈
int push(LinkStack* ptrL,int value){
    SNode* NewNode;
    NewNode=(SNode*)malloc(sizeof(SNode));
    if(*NewNode==NULL){
        printf("ERROR,memory allocation failed.\n")
    return 0;
    }
    NewNode->next=*ptrL;        //先让新节点的next指向头指针，然后让头指针指向新节点
    NewNode->data=value;
    *ptrL=NewNode;                      //*ptrL（头指针）的指向就是第一个节点

    return 0;
}
int pop(LinkStack* ptrL){
    SNode* tempNode;
    int value;
    tempNode=(*ptrL);
    value=tempNode->data;
    *ptrL=(*ptrL)->next;
    free(tempNode);

    return value;
}
int getTop(LinkStack L){
    int value;
    value=L->data;

    return value;
}
int main(){
    LinkStack S;
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

    return 0;
}




