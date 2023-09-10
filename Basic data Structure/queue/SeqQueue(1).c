#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
//******队列元素个数为(Q.rear-Q.front+MaxSize) % MaxSize******
//静态循环顺序队列
//front代表队头(出队端)，rear代表队尾(入队端)
/*三种判断队空/队满的方法：
1.空出数组的最后一个位置,然后使用(Q.rear+1) % MAXSIZE == Q.front;表示队满;Q.rear==Q.front;表示队空.<------本程序选择
2.类型中增设表示元素个数的数据成员Q.size.
3.类型中增设tag数据成员，队列中有数据时，tag = 1;无数据时，tag = 0.
*/
/*两种rear指针的指向：
1.rear指向最后一个元素的位置，入队时先移动指针，再赋值,初始化时Q.rear=-1        
2.rear指向最后一个元素的后面的位置，入队时先赋值，再移动指针,初始化时Q.rear=0   <------本程序采用
*/
typedef struct Queue{
    int front;
    int rear;
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
    if(Q.rear==Q.front)
        return 1;
    else
        return 0;
}
//判断是否为满
int isFull(SeqQueue Q){
    if((Q.rear+1) % MaxSize == Q.front)    //
        return 1;
    else
        return 0;
}
//入队
//**用模运算实现循环插入**
//1.判断是否为满 2.在队尾指针指向的空间插入值 3.更新队尾指针
int EnQueue(SeqQueue* ptrQ,int value){
    if(isFull(*ptrQ)){                              //1
        printf("队列已满，%d无法入队。\n",value);
        return 1;
    }
    ptrQ->array[ptrQ->rear]=value;                  //2
    ptrQ->rear=(ptrQ->rear+1) % MaxSize;                //3
    
    return 0;

}
//出队
//1.判断是否为空 2.删除队头指针指向的值 3.更新队头指针
int DeQueue(SeqQueue* ptrQ){
    int value;
    value=ptrQ->array[ptrQ->front];
    if(isEmpty(*ptrQ)){
        printf("队列为空，无法出队。\n");
        return 1;
    }
    ptrQ->array[ptrQ->front] = 0;
    ptrQ->front=(ptrQ->front+1) % MaxSize;

    return value;
}
//读取队头
int GetHead(SeqQueue Q){
    if(isEmpty(Q)){
        printf("队列为空，查询失败。\n");
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
    printf("队头元素为：%d\n",GetHead(Q));
}