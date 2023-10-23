#include "../Basic data Structure/queue/LinkQueue(HeadNode).h"
#include "../Basic data Structure/stack/LinkStack(HeadNode).h"
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1//定义布尔类型
#define FALSE 0

int main(){
    LinkStack S;
    initStack(&S);
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    printf("now top is %d\n", getTop(S));
    printf("remove %d\n", pop(&S));
    push(&S, 4);
    printf("push %d in.\n",4);
    printf("now top is %d\n", getTop(S));
    printf("remove %d\n", pop(&S));
    printf("now top is %d\n", getTop(S));
    printf("remove %d\n", pop(&S));
    printf("——————————————————————————————————————————————————\n");

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
