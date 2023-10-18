#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef char ElementType;//定义树的元素类型
// 定义树节点结构体
typedef struct TreeNode{
    datatype data;
    struct TreeNode *Lchild;
    struct TreeNode *Rchild;
}TreeNode,*Tree;


//中序遍历
void InOrder(Tree T) {
    if (T != NULL) {
        InOrder(T->Lchild);
        visit(T);
        InOrder(T->Rchild);
    }
}
void 

int main(){
//创建树

}
