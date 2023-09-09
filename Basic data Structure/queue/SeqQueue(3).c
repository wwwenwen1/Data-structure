#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
//******队列元素个数为(Q.rear-Q.front+MaxSize) % MaxSize******
//静态循环顺序队列
/*三种判断队空/队满的方法：
1.空出Q.array[MaxSize-1],然后使用(Q.rear+1) % MAXSIZE == Q.front;表示队满;Q.rear==Q.front;表示队空.
2.类型中增设表示元素个数的数据成员Q.size.
3.类型中增设tag数据成员，队列中有数据时，tag = 1;无数据时，tag = 0.                                  <------本程序采用
*/
typedef struct Queue{
    int front;
    int rear;
    int tag;            //0代表空，1代表满
    int array[MaxSize];
}SeqQueue;
//初始化队列
int initQueue(SeqQueue* ptrQ){
    ptrQ->front = 0;
    ptrQ->rear = 0;
    return 0;
}
//判断是否为空(返回1代表真，0代表假)
//空出Q.array[MaxSize-1]的位置，然后用模运算
int isEmpty(SeqQueue Q){
    if(Q.rear==Q.front && Q.tag==0)
        return 1;
    else
        return 0;
}
//判断是否为满
int isFull(SeqQueue Q){
    if(Q.rear==Q.front && Q.tag==1)
        return 1;
    else
        return 0;
}
//入队
//**用模运算实现循环插入**
int EnQueue(SeqQueue* ptrQ,int value){
    if(isFull(*ptrQ)){                              //1
        printf("队列已满，%d无法入队。\n",value);
        return 1;
    }
    ptrQ->array[ptrQ->rear]=value;                  //2
    ptrQ->rear=(ptrQ->rear+1) % MaxSize;                //3
    if(ptrQ->tag==0)
        ptrQ->tag=1;
    return 0;
}
//出队
int DeQueue(SeqQueue* ptrQ){
    if(isEmpty(*ptrQ)){
        printf("队列为空，无法出队。\n");
        return 1;
    }
    int value;
    value=ptrQ->array[ptrQ->front];
    ptrQ->front=(ptrQ->front+1) % MaxSize;
    if(ptrQ->tag==1)
        ptrQ->tag=0;
    return value;
}
//读取队头
int GetHead(SeqQueue Q){
    if(isEmpty(Q)){
        printf("队列为空，无法读取队头。\n");
        return 1;
    }
    return Q.array[Q.front];
}


int main(){
    SeqQueue Q;
    initQueue(&Q);
    EnQueue(&Q,1);
    EnQueue(&Q,2);
    EnQueue(&Q,3);
    EnQueue(&Q,4);
    EnQueue(&Q,5);
    EnQueue(&Q,6);
    EnQueue(&Q,7);
    EnQueue(&Q,8);
    EnQueue(&Q,9);
    EnQueue(&Q,10);
    EnQueue(&Q,11);
    EnQueue(&Q,12);
    EnQueue(&Q,14);
    EnQueue(&Q,15);
    printf("队头元素为：%d\n",GetHead(Q));

}