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
}Queue,*LinkQueue;
//等价于typedef struct Queue* LinkQueue;

//初始化队列
int initQueue(LinkQueue Q){
    Q->front=(QNode*)malloc(sizeof(QNode));
    Q->rear=Q->front;
    Q->front->next=NULL;
    Q->front->data = 0;

    return 0;
}
//入队
int enQueue(LinkQueue Q,int value){
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
int deQueue(LinkQueue Q){
    if(Q->front->next==NULL){
        printf("队列为空，无法出队.\n");
        return 1;
    }
    QNode* ptrTempNode;
    int value;
    ptrTempNode=Q->front->next;
    Q->front->next=Q->front->next->next;
    value=ptrTempNode->data;
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
int getHead(LinkQueue Q){
    if(QueueisEmpty(Q)){
        printf("列表为空，无法获取队首元素.\n");
    }
    else 
        return Q->front->next->data;
}
int main(){
    LinkQueue Q;            
    /*
    在C语言中，声明一个指针变量（例如 LinkQueue Q;）不会自动为该指针分配内存。
    当你声明 LinkQueue Q; 时，实际上只是创建了一个指向 Queue 结构的指针，但这个指针没有指向任何有效的内存地址。
    因此，你必须在使用这个指针之前手动分配内存来存储 Queue 结构。*/
    Q = (LinkQueue)malloc(sizeof(struct Queue));
    initQueue(Q);
    enQueue(Q,1);
    enQueue(Q,2);
    enQueue(Q,3);
    enQueue(Q,4);
    enQueue(Q,5);
    printf("队列是否为空:%d\n",QueueisEmpty(Q));
    printf("队首元素:%d\n",getHead(Q));
    printf("出队元素:%d\n",deQueue(Q));
    printf("队首元素:%d\n",getHead(Q));
    printf("出队元素:%d\n",deQueue(Q));
    printf("队首元素:%d\n",getHead(Q));
    printf("出队元素:%d\n",deQueue(Q));
    printf("队首元素:%d\n",getHead(Q));
    printf("出队元素:%d\n",deQueue(Q));
    printf("队首元素:%d\n",getHead(Q));
    printf("出队元素:%d\n",deQueue(Q));
    printf("队首元素:%d\n",getHead(Q));
    printf("队列是否为空:%d\n",QueueisEmpty(Q));
    return 0;
}