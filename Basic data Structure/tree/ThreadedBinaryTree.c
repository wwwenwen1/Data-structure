// #include "../queue/LinkQueue(HeadNode).h"//链式队列的头文件
// #include "../stack/LinkStack(HeadNode).h"//链式栈的头文件
#include<stdio.h>
#include<stdlib.h>

//线索二叉树的创建和遍历
#define TRUE 1//定义布尔类型
#define FALSE 0

typedef char ElementType;//定义树的元素类型
typedef struct ThreadedNode{
    ElementType data;
    struct ThreadedNode* LChild;
    struct ThreadedNode* RChild;
    int LTag,RTag;//左右标志域
}ThreadedNode,*ThreadedTree;

//访问节点的函数
void visit(ThreadedTree T){
    printf("%c ",T->data);
}

//先序遍历
void PreOrder(ThreadedTree T){
    if (T != NULL && T->LTag==0 && T->RTag==0) {
        visit(T);
        PreOrder(T->LChild);
        PreOrder(T->RChild);
    }
}

//中序遍历
void InOrder(ThreadedTree T){
    if (T != NULL && T->LTag==0 && T->RTag==0) {
        InOrder(T->LChild);
        visit(T);
        InOrder(T->RChild);
    }
}

//后序遍历
void PostOrder(ThreadedTree T){
    if (T != NULL && T->LTag==0 && T->RTag==0) {
        PostOrder(T->LChild);
        PostOrder(T->RChild);
        visit(T);
    }
}
 
//中序线索化(递归调用部分)
//对应中序遍历的三步，visit变为（2.线索化当前节点）
void InThread(ThreadedTree T,ThreadedTree* Ptrpre){
    if(T!=NULL){
        //传入Ptrpre是为了让Pre是一个全局变量，这样在递归的过程中，每次递归都可以访问到上一次递归的结果
        InThread(T->LChild,Ptrpre);     //1.递归左子树线索化

                                        //2.线索化当前节点
        if(T->LChild==NULL){            //左子树为空，建立前驱线索
            T->LChild=*Ptrpre;
            T->LTag=1;
        }
        if((*Ptrpre)!=NULL && (*Ptrpre)->RChild==NULL){//前驱节点的后继为空，建立后继线索
            (*Ptrpre)->RChild=T;
            (*Ptrpre)->RTag=1;
        }
        *Ptrpre=T;//更新前驱节点的指向

        InThread(T->RChild,Ptrpre);     //3.递归右子树线索化
    }
}
//中序线索化函数
void CreateInThread(ThreadedTree T){
    ThreadedTree pre=NULL; //pre指向当前节点的前驱，在之后通过模拟引用传递的方式传递给InThread函数，当成全局变量使用
    if(T!=NULL){
        InThread(T,&pre);//开始递归
        pre->RChild=NULL;//此时pre指向最后一个节点，即中序遍历的最后一个节点，将其后继指针指向NULL
        pre->RTag=1;
    }
}

//前序线索化(递归调用部分)
//对应前序遍历的三步，visit变为（1.线索化当前节点）
void PreThread(ThreadedTree T,ThreadedTree* Ptrpre){

    if(T!=NULL){                        //1.线索化当前节点
        if(T->LChild==NULL){            //左子树为空，建立前驱线索
            T->LChild=*Ptrpre;
            T->LTag=1;
        }
        if((*Ptrpre)!=NULL && (*Ptrpre)->RChild==NULL){//前驱节点的后继为空，建立后继线索
            (*Ptrpre)->RChild=T;
            (*Ptrpre)->RTag=1;
        } 
        *Ptrpre=T;//更新前驱节点的指向

        if(T->LTag==0)    //如果左子树不是线索，才有必要递归(防止爱的魔力转圈圈情况出现)
            PreThread(T->LChild,Ptrpre);     //2.递归左子树线索化
        PreThread(T->RChild,Ptrpre);     //3.递归右子树线索化
    }
}
//前序线索化函数
void CreatePreThread(ThreadedTree T){
    ThreadedTree pre=NULL; //pre指向当前节点的前驱，在之后通过模拟引用传递的方式传递给InThread函数，当成全局变量使用
    if(T!=NULL){
        PreThread(T,&pre);//开始递归
        pre->RChild=NULL;//此时pre指向最后一个节点，即中序遍历的最后一个节点，将其后继指针指向NULL
        pre->RTag=1;
    }
}

//后序线索化(递归调用部分)
//对应后序遍历的三步，visit变为（3.线索化当前节点）
void PostThread(ThreadedTree T,ThreadedTree* Ptrpre){
    if(T!=NULL){                        //1.递归左子树线索化
        PostThread(T->LChild,Ptrpre);     
        PostThread(T->RChild,Ptrpre);     //2.递归右子树线索化

        //3.线索化当前节点
        if(T->LChild==NULL){            //左子树为空，建立前驱线索
            T->LChild=*Ptrpre;
            T->LTag=1;
        }
        if((*Ptrpre)!=NULL && (*Ptrpre)->RChild==NULL){//前驱节点的后继为空，建立后继线索
            (*Ptrpre)->RChild=T;
            (*Ptrpre)->RTag=1;
        }
        *Ptrpre=T;//更新前驱节点的指向
    }
}
//后序线索化函数
void CreatePostThread(ThreadedTree T){
    ThreadedTree pre=NULL; //pre指向当前节点的前驱，在之后通过模拟引用传递的方式传递给InThread函数，当成全局变量使用
    if(T!=NULL){
        PostThread(T,&pre);//开始递归
        pre->RChild=NULL;//此时pre指向最后一个节点，即中序遍历的最后一个节点，将其后继指针指向NULL
        pre->RTag=1;
    }
}


//中序线索二叉树的后继节点
ThreadedTree InNextNode(ThreadedTree T){
    ThreadedTree p;
    p=T->RChild;
    if(T->RTag==0){//如果右标志域为0，说明右子树不是线索，直接返回右子树的最左节点
        while(p->LTag==0)
            p=p->LChild;
    }else{//如果右标志域为1，说明右子树是线索，直接返回右子树
        p=T->RChild;
    }
    return p;
}

//中序线索二叉树的正序遍历
void InOrderTraverse(ThreadedTree T){//非递归 该算法的时间复杂度为O(n)，空间复杂度为O(1)
    ThreadedTree p;
    p=T;
    //找到中序遍历的第一个节点
    while(p->LTag==0)
        p=p->LChild;
    for(;p!=NULL;p=InNextNode(p))
        printf("%c ",p->data);
}

//中序线索二叉树的前驱节点
ThreadedTree InPreNode(ThreadedTree T){
    ThreadedTree p;
    p=T->LChild;
    if(T->LTag==0){//如果左标志域为0，说明左子树不是线索，直接返回左子树的最右节点
        while(p->RTag==0)
            p=p->RChild;
    }else{//如果左标志域为1，说明左子树是线索，直接返回左子树
        p=T->LChild;
    }
    return p;
}

//中序线索二叉树的逆序遍历
void InOrderTraverseReverse(ThreadedTree T){
    ThreadedTree p;
    p=T;
    //找到中序遍历的最后一个节点
    while(p->RTag==0)
        p=p->RChild;
    for(;p!=NULL;p=InPreNode(p))
        printf("%c ",p->data);
}

int main (){
    //创建树
    ThreadedTree A=(ThreadedTree)malloc(sizeof(ThreadedNode));
    A->data='A';
    A->LTag=0;
    A->RTag=0;
    ThreadedTree B=(ThreadedTree)malloc(sizeof(ThreadedNode));
    B->data='B';
    B->LTag=0;
    B->RTag=0;
    ThreadedTree C=(ThreadedTree)malloc(sizeof(ThreadedNode));
    C->data='C';
    C->LTag=0;
    C->RTag=0;
    ThreadedTree D=(ThreadedTree)malloc(sizeof(ThreadedNode));
    D->data='D';
    D->LTag=0;
    D->RTag=0;
    ThreadedTree E=(ThreadedTree)malloc(sizeof(ThreadedNode));
    E->data='E';
    E->LTag=0;
    E->RTag=0;
    ThreadedTree F=(ThreadedTree)malloc(sizeof(ThreadedNode));
    F->data='F';
    F->LTag=0;
    F->RTag=0;
    ThreadedTree G=(ThreadedTree)malloc(sizeof(ThreadedNode));
    G->data='G';
    G->LTag=0;
    G->RTag=0;


    A->LChild=B;
    A->RChild=C;
    B->LChild=D;
    B->RChild=E;
    C->LChild=F;
    C->RChild=NULL;
    D->LChild=NULL;
    D->RChild=G;
    E->LChild=NULL;
    E->RChild=NULL;
    F->LChild=NULL;
    F->RChild=NULL;
    G->LChild=NULL;
    G->RChild=NULL;

    InOrder(A);
    printf("\n");
    PreOrder(A);

    CreateInThread(A);
    printf("\n线索化完成");
    printf("\n中序线索二叉树的正序遍历:");
    InOrderTraverse(A);
    printf("\n中序线索二叉树的逆序遍历:");
    InOrderTraverseReverse(A);

    return 0;
}