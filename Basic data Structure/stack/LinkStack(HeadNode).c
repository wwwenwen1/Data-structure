#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}SNode,*LinkStack;
/*等价于
typedef struct node Snode;
typedef struct node* LinkStack;
*/
int initStack(LinkStack *ptrL){
    *ptrL=(SNode*)malloc(sizeof(SNode));
    if(*ptrL==NULL){
        printf("ERROR,memory allocation failed.\n")
    return 0;
    }
    (*ptrL)->data=0;
    return 0;
}
int isEmpty(LinkStack L){
    if(L->next==NULL)       //if(L->data=0)也可以
        return 1;
    else
        return 0;
}

int push(LinkStack* ptrL,int value){
    SNode* NewNode;
    SNode* headNode;
    headNode=(*ptrL)->next;
    NewNode=(SNode*)malloc(sizeof(SNode));
    if(*NewNode==NULL){
        printf("ERROR,memory allocation failed.\n")
    return 0;
    }
    NewNode->next=(*ptrL)->next;        //先让新节点的next指向头指针，然后让头指针指向新节点
    NewNode->data=value;
    (*ptrL)->next=NewNode;                      //*ptrL（头指针的指向）是头结点

    return 0;
}

int pop(LinkStack* ptrL){

}

int getTop(LinkStack L){

    return Link
}
