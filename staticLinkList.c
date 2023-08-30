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
    return 0;
}

//按照位置插入
//1.判断插入位置2.找到一个空的节点3.找到插入位置的前一个节点4.修改插入位置前一个节点的next为新节点的位序5.修改新节点的next为插入位置的位序
int insertAtPosition(staticLinkList L,int insertPosition,int insertData){//insertPosition代表位序，从1开始
    int priorPoniter = 0;//存储插入位置的前一个节点的位序
    //判断链表是否已满
    if(L[0].data==MAXSIZE-1){
        printf("链表已满\n");
        return 1;
    }
    //判断插入位置是否合法
    if(insertPosition<1 || insertPosition>MAXSIZE){
        printf("插入位置不合法\n");
        return 1;
    }
    //判断插入位置时候存在
    if(L[0].data<=insertPosition){
        printf("插入位置不存在\n");
        return 1;
    }
   //找到一个空的位序
   for(int newPointer=1;newPointer<MAXSIZE;newPointer++){
       if(L[newPointer].next==0){
            L[newPointer].data = insertData;
            L[newPointer].next = insertPosition;

            while(L[priorPoniter].next!=insertPosition){//找到插入位置的前一个节点的位序
                priorPoniter = L[priorPoniter].next;
            }
            L[priorPoniter].next = newPoniter;//修改插入位置前一个节点的next为新节点的位序
            L[0].data++;
            return 0;
       }
    }
    return 1;
}
//插入到某个元素值之后
//1.判断链表是否已满2.找到这个元素3.找到一个空位序，填入数据4.修改新元素的next指向目标元素的后继元素，修改目标元素的next指向新元素
int insertAfterValue(staticLinkList L,int value,int insertData){
    int currentPointer = 0;
    //判断链表是否已满
    if(L[0].data==MAXSIZE-1){
        printf("链表已满，无法插入！\n");
        return 1;
    }
    //找到目标元素元素
    while(L[currentPointer].data!=value){
        if(L[currentPointer].next==-1){
            printf("遍历结束,没有找到目标元素!\n");
            return 1;
        }
        currentPointer=L[currentPointer].next;
    }
    //找到空的位序，空位序的next被初始化为0
    for(int i=1;i<MAXSIZE;i++){
        if(L[i].next==0){
            L[i].data=insertData;
            L[i].next=L[currentPointer].next;
            L[currentPointer].next=i;
            L[0].data++;
            return 0;
        }
    }
    return 1;
}
//按位删除
//1.检查输入位置2.找到删除节点的前缀节点3.把前缀节点的next改为目标节点的后缀节点的next,把目标节点的data设为0
int deleteAtPosition(staticLinkList L,int deletePosition){
    int priorPoniter = 0;//存储删除位置的前一个节点的位序
    if(L[0].data==0){
        printf("链表位空\n");
        return 1;
    }
    //判断删除位置是否合法
    if(deletePosition<1 || deletePosition>MAXSIZE){
        printf("删除位置不合法\n");
        return 1;
    }
    //判断删除位置时候存在
    if(L[0].data<=deletePosition){
        printf("删除位置不存在\n");
        return 1;
    }
    //找到删除位置的前一个节点的位序
    while(L[priorPoniter].next!=deletePosition){
        priorPoniter = L[priorPoniter].next;
    }
    L[priorPoniter].next = L[deletePosition].next;
    L[deletePosition].next = 0;
    L[deletePosition].data = 0;
    L[0].data--;

    return 0;
}
//按值删除
//1.检查链表是否为空 2.找到目标节点的前缀节点 3.把前缀节点的next改为目标节点的后继节点 4.把后继节点
int deleteAtValue(staticLinkList L,int value){
    int priorPointer = 0;
    if(L[0].data==0){
        printf("链表为空\n");
        return 1;
    }
    //寻找目标元素的前缀节点
    while(L[priorPointer].data!=value){
        if(L[priorPointer].next==-1){
            printf("遍历结束,没有找到目标元素!\n");
            return 1;
        }
        priorPointer=L[priorPointer].next;
    }
    L[priorPointer].next = L[L[priorPointer].next].next;
    L[L[priorPointer].next].next = 0;
    L[L[priorPointer].next].data = 0;
    L[0].data--;

    return 0;
}
//按位查找
int getByposition(staticLinkList L,int Position){
    int currentPointer = 0;
    if(L[0].data==0){
        printf("链表为空\n");
        return 1;
    }
    //判断查找位置是否合法
    if(Position<1 || Position>MAXSIZE){
        printf("查找位置不合法\n");
        return 1;
    }
    //判断查找位置时候存在
    if(L[0].data<=Position){
        printf("查找位置不存在\n");
        return 1;
    }
    //找到查找位置的节点
    for(int i=0;i<Position;i++){
        currentPointer = L[currentPointer].next;
    }
    return L[currentPointer].data;
}
//按值查找
int getByValue(staticLinkList L,int value){
    int currentPointer = 0;
    if(L[0].data==0){
        printf("链表为空\n");
        return 1;
    }
    //找到查找位置的节点
    while(L[currentPointer].data!=value){
        if(L[currentPointer].next==-1){
            printf("遍历结束,没有找到目标元素!\n");
            return 1;
        }
        currentPointer=L[currentPointer].next;
    }
    return currentPointer;
}
//打印链表
int printList(staticLinkList L){
    int currentPointer = 0;
    if(L[0].data==0){
        printf("链表为空\n");
        return 1;
    }
    while(L[currentPointer].next!=-1){
        printf("%d ",L[currentPointer].data);
        currentPointer = L[currentPointer].next;
    }
    printf("%d\n",L[currentPointer].data);
    return 0;
}
//摧毁链表
int destroyList(staticLinkList L){
    for(int i=0;i<MAXSIZE;i++){
        L[i].next = 0;
        L[i].data = 0;
    }
    return 0;
}
//判断链表是否为空
int isEmpty(staticLinkList L){
    if(L[0].data==0){
        return 1;
    }
    return 0;
}
//求链表长度
int getLength(staticLinkList L){
    return L[0].data;
}


int main(){
    staticLinkList L;
    initList(L);

    return 0;
}