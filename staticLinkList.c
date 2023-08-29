#include <stdio.h>
#include <stdlib.h>    //malloc()函数

//定义静态链表
#define MAXSIZE 10
typedef struct SNode{
    int data;
    int next;
}SNode,staticLinkList[MAXSIZE];    //SNode为结点类型，staticLinkList为结点数组类型
/*这种定义的等价形式为：
typedef struct SNode{
    int data;
    int next;
}SNode;
typedef SNode staticLinkList[MAXSIZE];   //把staticLinkList定义存放SNode类型的数组
*/

//初始化静态链表
//0号节点为头结点，末尾节点的next为-1
//给头节点赋值next为-1，把剩余的节点的next赋值为0，表示空闲，把data赋值为0
int initList(staticLinkList L){
    L[0].next = -1;
    L[0].data = 0;
    for(int i=1;i<MAXSIZE;i++){
        L[i].next = 0;
        L[i].data = 0;
    }
}
int main