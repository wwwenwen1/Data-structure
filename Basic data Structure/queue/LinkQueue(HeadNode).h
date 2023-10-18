//这个文件是LinkQueue(HeadNode).c的头文件

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

typedef struct QNode{
    int data;
    struct QNode *next;
}QNode;

typedef struct{
    QNode *front;
    QNode *rear;
}Queue,ListQueue;

int initQueue(ListQueue *Q);
int destroyQueue(ListQueue *Q);
int enQueue(ListQueue *Q,int e);
int deQueue(ListQueue *Q,int *e);
int isEmpty(ListQueue Q);
int getHead(ListQueue Q,int *e);

#endif //LINKQUEUE_H
