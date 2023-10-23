#include<stdio.h>
#include<stdlib.h>
#define TRUE 1//定义布尔类型
#define FALSE 0
#define MAXSIZE 10

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