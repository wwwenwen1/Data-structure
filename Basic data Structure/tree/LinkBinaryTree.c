#include<stdio.h>
#include<stdlib.h>
#include"LinkQueue(HeadNode).h"
#include"LinStack(HeadNode).h"
#define TRUE 1//定义布尔类型
#define FALSE 0

typedef char ElementType;//定义树的元素类型
typedef struct treeNode{
    ElementType data;
    treeNode* leftChild;
    treeNode* rightChild;
    //treeNode* parent; //如果需要知道父节点的话，可以加上这一行
}treeNode,*Tree;

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
    InitQueue(Q);
    Tree ptrTempNode;
    if(T!=NULL){
        EnQueue(Q,T);
        while(!IsEmpty(Q)){
            ptrTempNode=DeQueue(Q);
            visit(ptrTempNode);
            if(ptrTempNode->leftChild!=NULL)
                EnQueue(Q,ptrTempNode->leftChild);
            if(ptrTempNode->rightChild!=NULL)
                EnQueue(Q,ptrTempNode->rightChild);
        }
    }
}

//非递归先序遍历


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


    return 0;    
    
}
