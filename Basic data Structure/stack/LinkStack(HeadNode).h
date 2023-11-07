//这是LinkStack(HeadNode).c的头文件
#include<stdio.h>
#include<stdlib.h>
#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef struct node{
    ElementType data;
    struct node* next;
}SNode,*LinkStack;

/*等价于
typedef struct node Snode;
typedef struct node* LinkStack;
*/
int initStack(LinkStack *ptrL){
    *ptrL=(SNode*)malloc(sizeof(SNode));
    if(*ptrL==NULL){
        printf("ERROR,memory allocation failed.\n");
        return 0;
    }
    (*ptrL)->data=0;
    (*ptrL)->next=NULL;
    return 0;
}
//
int StackisEmpty(LinkStack L){
    if(L->next==NULL)       //if(L->data=0)也可以
        return 1;
    else
        return 0;
}
//
int push(LinkStack* ptrL,ElementType value){
    SNode* NewNode;
    SNode* headNode;
    headNode=(*ptrL)->next;
    NewNode=(SNode*)malloc(sizeof(SNode));
    if(NewNode==NULL){                           //NULL是void*类型，所以不需要解引用NewNode
        printf("ERROR,memory allocation failed.\n");
    return 0;
    }
    NewNode->next=(*ptrL)->next;        //先让新节点的next指向头指针，然后让头指针指向新节点
    NewNode->data=value;
    (*ptrL)->next=NewNode;                      //*ptrL（头指针的指向）是头结点，
    (*ptrL)->data=(*ptrL)->data+1;            //头结点的数据域存储栈的长度

    return 0;
}
//
ElementType pop(LinkStack* ptrL){
    SNode* TopNode;
    ElementType value;
    TopNode=(*ptrL)->next;              //取出第二个节点
    value=TopNode->data;                
    (*ptrL)->next=TopNode->next;        //让首节点的后继节点变成第三个节点
    free(TopNode);                      //释放第二个节点
    (*ptrL)->data=(*ptrL)->data-1;      //头结点的数据域存储栈的长度
    return value;
}
//
ElementType getTop(LinkStack L){
    return L->next->data;               //L是指向头节点的指针(头指针)，L->next是指向第二个节点的指针(真正开始存储数据的节点)，L->next->data是第二个节点的数据域
}

#endif //LINKSTACK_H