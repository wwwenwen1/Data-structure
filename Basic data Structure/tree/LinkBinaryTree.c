#include "../queue/LinkQueue(HeadNode).h"//链式队列的头文件  //待修改，数据类型有问题
#include "../stack/LinkStack(HeadNode).h"//链式栈的头文件    //待修改，数据类型有问题
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1//定义布尔类型
#define FALSE 0

typedef char ElementType;//定义树的元素类型
typedef struct TreeNode{
    ElementType data;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
    //treeNode* parent; //如果需要知道父节点的话，可以加上这一行
}TreeNode,*Tree;
//Tree是指向treeNode的指针，Tree是树的类型，Tree和treeNode是两个不同的类型

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
        enQueue(Q,T);                //结点入队
        while(!QueueisEmpty(Q)){          //队列不为空时循环
            ptrTempNode=deQueue(Q);  //结点出队,让其左右孩子入队
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
    
}
//非递归中序遍历
void InOrder2(Tree T){
    
}
//非递归后序遍历
void PostOrder2(Tree T){
    
}


int main(){
    //创建树
    Tree A=(Tree)malloc(sizeof(TreeNode));
    A->data='A';
    Tree B=(Tree)malloc(sizeof(TreeNode));
    B->data='B';
    Tree C=(Tree)malloc(sizeof(TreeNode));
    C->data='C';
    Tree D=(Tree)malloc(sizeof(TreeNode));
    D->data='D';
    Tree E=(Tree)malloc(sizeof(TreeNode));
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
