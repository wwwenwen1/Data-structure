#include<stdio.h>
#include<stdlib.h>
#define TRUE 1//定义布尔类型
#define FALSE 0
#define MAXSIZE 10
//该方法是用数组实现的二叉树，数组下标从1开始，0不用
//仅适合完全二叉树，因为数组下标对应的是完全二叉树的层序遍历的顺序，非完全二叉树会浪费空间

typedef int ElementType;//定义树的元素类型
typedef struct treeNode{
    ElementType data;
    int isEmpty; 
}treeNode;

int main(){
    treeNode T[MAXSIZE+1];//T[0]不用,对齐下标，T[1]是根节点
    for(int i=1;i<=MAXSIZE;i++){
        T[i].isEmpty=TRUE;
    }
    printf("请输入树的元素：");
}