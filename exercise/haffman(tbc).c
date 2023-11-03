#include<stdio.h>
#include<stdlib.h>

typedef char ElementType;//定义树的元素类型
typedef struct TreeNode{
    ElementType data;
    float weight;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
    //treeNode* parent; //如果需要知道父节点的话，可以加上这一行
}TreeNode,*Tree;
//Tree是指向treeNode的指针，Tree是树的类型，Tree和treeNode是两个不同的类型

//找两个最小的元素

//创建哈夫曼树
Tree createHaffmanTree(Tree lettles[],int n){
    //n是叶子节点的个数
    //lettles是叶子节点的数组
    //返回值是哈夫曼树的根节点
    //创建哈夫曼树的过程是不断地找两个最小的元素，然后合并，再找两个最小的元素，再合并，直到只剩下一个元素
    //这个过程可以用一个数组来表示，数组的每个元素是一个指针，指向一个树节点
    //数组的长度是2n-1，因为n个叶子节点，n-1个合并节点
    //数组的前n个元素是叶子节点，后面的元素是合并节点
    //数组的前n个元素是已经排好序的，从小到大
    //数组的第n个元素是最小的元素，数组的第n-1个元素是第二小的元素
    //数组的第2n-1个元素是根节点
}
//创建哈夫曼编码

int main(){
    TreeNode A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z;
    Tree lettles[26]={&A,&B,&C,&D,&E,&F,&G,&H,&I,&J,&K,&L,&M,&N,&O,&P,&Q,&R,&S,&T,&U,&V,&W,&X,&Y,&Z};
    float lettlesWeight[26]={8.19,1.47,3.83,3.91,12.25,2.26,1.71,4.57,7.10,0.14,0.41,3.77,3.34,7.06,7.26,2.89,0.09,6.85,6.36,9.41,2.58,1.09,1.59,0.21,1.58,0.08};
    for(int i=0;i<26;i++){
        lettles[i]->data='A'+i;
        lettles[i]->weight=lettlesWeight[i];
        lettles[i]->leftChild=NULL;
        lettles[i]->rightChild=NULL;
    }

    printf("Hello World!\n");
    return 0;
}