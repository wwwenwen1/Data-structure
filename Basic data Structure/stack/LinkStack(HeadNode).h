//这是LinkStack(HeadNode).c的头文件
#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef struct node{
    int data;
    struct node* next;
}SNode,*LinkStack;

/*等价于
typedef struct node Snode;
typedef struct node* LinkStack;
*/
int initStack(LinkStack *ptrL);
int isEmpty(LinkStack L);
int push(LinkStack* ptrL,int value);
int pop(LinkStack* ptrL);
int getTop(LinkStack L);

#endif //LINKSTACK_H