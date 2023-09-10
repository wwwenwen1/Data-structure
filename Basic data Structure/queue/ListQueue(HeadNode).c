#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

//用含头指针的单链表来
typedef struct QNode{
    int data;
    struct QNode* next;
}QNode;

typedef struct Queue{
    QNode* front;
    QNode* rear;
}*LinkQueue;
//等价于typedef struct Queue* LinkQueue;

//初始化队列
int initQueue(LinkQueue Q){
    Q->front=(QNode*)malloc(sizeof(QNode));
    Q->rear=Q->front;
    (*Q->front).next=NULL;
    (*Q->front).data = 0;

    return 0;
}
//入队
int EnQueue(LinkQueue Q,int value){
    QNode* ptrNewNode;
    ptrNewNode =(QNode*)malloc(sizeof(QNode));
    ptrNewNode->data=value;
    ptrNewNode->next=NULL;
    Q->rear=ptrNewNode;
    (*Q->front).data++;

    return 0;
}
//出队
int DeQueue(LinkQueue Q){
    QNode* ptrTempNode;
    int value;
    ptrTempNode=(*Q->front).next;
    (*Q->front).next=(*Q->front->next).next;
    (*Q->front).data--;
    value=ptrTempNode->data;
    free(ptrTempNode);

    return value;
}
//判断是否为空
int isEmpty(LinkQueue Q){
    if(Q->front->next==NULL)
        return 1;
    else 
        return 0;
}
//获取队首元素
int GetHead(LinkQueue Q){
    if(isEmpty(Q)){
        printf("列表为空，无法获取队首元素.\n");
    }
    else 
        return (*Q->front->next).data;
}
int main(){
    LinkQueue Q;
    initQueue(Q);
    
    return 0;
}