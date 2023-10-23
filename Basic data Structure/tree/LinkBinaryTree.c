#include"../Queue/LinkQueue(HeadNode).h"
#include"../stack/LinkStack(HeadNode).h"
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1//定义布尔类型
#define FALSE 0

typedef char ElementType;//定义树的元素类型
typedef struct treeNode{
    ElementType data;
    struct treeNode* leftChild;
    struct treeNode* rightChild;
    //treeNode* parent; //如果需要知道父节点的话，可以加上这一行
}treeNode,*Tree;

//访问节点的函数
void visit(Tree T){
    printf("%c ",T->data);
}

//先序遍历
void PreOrder(Tree T) {
    if (T != NULL) {
        visit(T);
        PreOrder(T->leftChild);
        PreOrder(T->rightChild);
    }
}
//中序遍历
void InOrder(Tree T) {
    if (T != NULL) {
        InOrder(T->leftChild);
        visit(T);
        InOrder(T->rightChild);
    }
}
//后序遍历
void PostOrder(Tree T) {
    if (T != NULL) {
        PostOrder(T->leftChild);
        PostOrder(T->rightChild);
        visit(T);
    }
}
//层序遍历//需要借助队列
void LevelOrder(Tree T){
    LinkQueue Q;
    initQueue(&Q);
    Tree ptrTempNode;
    if(T!=NULL){
        enQueue(Q,T);
        while(!isEmpty(Q)){
            ptrTempNode=deQueue(Q);
            visit(ptrTempNode);
            if(ptrTempNode->leftChild!=NULL)
                enQueue(Q,ptrTempNode->leftChild);
            if(ptrTempNode->rightChild!=NULL)
                enQueue(Q,ptrTempNode->rightChild);
        }
    }
}

//非递归先序遍历
void PreOrder2(Tree T){
    LinkStack S;
    InitStack(S);
    Tree ptrTempNode=T;
    while(ptrTempNode!=NULL||!IsEmpty(S)){
        if(ptrTempNode!=NULL){
            visit(ptrTempNode);
            Push(S,ptrTempNode);
            ptrTempNode=ptrTempNode->leftChild;
        }
        else{
            Pop(S,ptrTempNode);
            ptrTempNode=ptrTempNode->rightChild;
        }
    }
}
//非递归中序遍历
void InOrder2(Tree T){
    LinkStack S;
    InitStack(S);
    Tree ptrTempNode=T;
    while(ptrTempNode!=NULL||!IsEmpty(S)){
        if(ptrTempNode!=NULL){
            Push(S,ptrTempNode);
            ptrTempNode=ptrTempNode->leftChild;
        }
        else{
            Pop(S,ptrTempNode);
            visit(ptrTempNode);
            ptrTempNode=ptrTempNode->rightChild;
        }
    }
}
//非递归后序遍历
void PostOrder2(Tree T){
    LinkStack S;
    InitStack(S);
    Tree ptrTempNode=T;
    Tree ptrLastVisit=NULL;
    while(ptrTempNode!=NULL||!IsEmpty(S)){
        if(ptrTempNode!=NULL){
            Push(S,ptrTempNode);
            ptrTempNode=ptrTempNode->leftChild;
        }
        else{
            GetTop(S,ptrTempNode);
            if(ptrTempNode->rightChild!=NULL&&ptrTempNode->rightChild!=ptrLastVisit){
                ptrTempNode=ptrTempNode->rightChild;
            }
            else{
                Pop(S,ptrTempNode);
                visit(ptrTempNode);
                ptrLastVisit=ptrTempNode;
                ptrTempNode=NULL;
            }
        }
    }
}


int main(){
    //创建树
    Tree A=(Tree)malloc(sizeof(treeNode));
    A->data='A';
    Tree B=(Tree)malloc(sizeof(treeNode));
    B->data='B';
    Tree C=(Tree)malloc(sizeof(treeNode));
    C->data='C';
    Tree D=(Tree)malloc(sizeof(treeNode));
    D->data='D';
    Tree E=(Tree)malloc(sizeof(treeNode));
    E->data='E';

    A->leftChild=B;
    A->rightChild=C;
    B->leftChild=D;
    B->rightChild=E;
    C->leftChild=NULL;
    C->rightChild=NULL;
    D->leftChild=NULL;
    D->rightChild=NULL;
    E->leftChild=NULL;
    E->rightChild=NULL;
    LevelOrder(A);
    


    return 0;    
    
}
