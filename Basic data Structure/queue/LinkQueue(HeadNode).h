//这个文件是LinkQueue(HeadNode).c的头文件
#include<stdio.h>
#include<stdlib.h>

#ifndef LINKQUEUE_HEADNODE_H
#define LINKQUEUE_HEADNODE_H

typedef struct QNode{
    ElementType data;
    struct QNode *next;
}QNode;

typedef struct Queue{
    QNode *front;
    QNode *rear;
}Queue,*LinkQueue,*ptrQueue;

//初始化队列
int initQueue(LinkQueue Q){
    Q->front=(QNode*)malloc(sizeof(QNode));
    Q->rear=Q->front;
    Q->front->next=NULL;
    Q->front->data = 0;

    return 0;
}

//入队
int enQueue(LinkQueue Q,ElementType value){
    QNode* ptrNewNode;
    ptrNewNode =(QNode*)malloc(sizeof(QNode));
    ptrNewNode->data=value;
    ptrNewNode->next=NULL;
    Q->rear->next=ptrNewNode;
    Q->rear=ptrNewNode;
    Q->front->data++;

    return 0;
}

//出队
ElementType deQueue(LinkQueue Q){
    if(Q->front->next==NULL){
        printf("队列为空，无法出队.\n");
        return 1;
    }
    QNode* ptrTempNode;
    int value;
    ptrTempNode=Q->front->next;//指向队头元素
    Q->front->next=Q->front->next->next;//队头元素出队
    value=ptrTempNode->data;//获取队头元素的值
    if(Q->rear==ptrTempNode)//如果队列中只有一个元素，那么出队后，队尾指针指向头结点
        Q->rear=Q->front;
    free(ptrTempNode);
    Q->front->data--;

    return value;
}

//判断是否为空
int QueueisEmpty(LinkQueue Q){
    if(Q->front->next==NULL)
        return 1;
    else 
        return 0;
}
//获取队首元素
ElementType getHead(LinkQueue Q){
    if(QueueisEmpty(Q)){
        return -1;
    }
    else 
        return Q->front->next->data;
}

#endif //LINKQUEUE_HEADNODE_H
