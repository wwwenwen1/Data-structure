#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//直接把链栈的内容拿过来用
typedef struct node{
    int data;
    struct node* next;
}SNode, *LinkStack;

/*等价于
typedef struct node Snode;
typedef struct node* LinkStack;
*/

int initStack(LinkStack *ptrL){
    *ptrL=(SNode*)malloc(sizeof(SNode));
    if(*ptrL==NULL){
        printf("ERROR,memory allocation failed.\n");
        return 0;
    }
    //(*ptrL)->data=0;  头指针的data不再存储栈的长度
    (*ptrL)->next=NULL;        //头指针的next指向NULL,表示栈为空
    return 0;
}
//
int isEmpty(LinkStack L){
    if(L->next==NULL)       //if(L->data=0)也可以
        return 1;
    else
        return 0;
}
//
int push(LinkStack* ptrL,int value){
    SNode* NewNode;
    SNode* headNode;
    headNode=(*ptrL)->next;
    NewNode=(SNode*)malloc(sizeof(SNode));
    if(NewNode==NULL){                           //NULL是void*类型，所以不需要解引用NewNode
        printf("ERROR,memory allocation failed.\n");
    return 0;
    }
    NewNode->next=(*ptrL)->next;                //先让新节点的next指向头指针，然后让头指针指向新节点
    NewNode->data=value;
    (*ptrL)->next=NewNode;                      //*ptrL（头指针的指向）是头结点，

    return 0;
}
//
int pop(LinkStack* ptrL){
    SNode* TopNode;
    char value;
    TopNode=(*ptrL)->next;              //取出第二个节点
    value=TopNode->data;                
    (*ptrL)->next=TopNode->next;        //让首节点的后继节点变成第三个节点
    free(TopNode);                      //释放第二个节点
    return value;
}
//
int getTop(LinkStack S){
    char top;
    top=S->next->data;
    return top;                         //S是指向头节点的指针(头指针)，S->next是指向第二个节点的指针(真正开始存储数据的节点)，S->next->data是第二个节点的数据域
}

int calculateRPN(char* RPN){//不用数组，直接用指针，因为数组是指针常量，不能修改数组的值
    LinkStack S;
    initStack(&S);
    char ch;
    int a,b;
    while(*RPN!='\0'){
        ch=*RPN;
        if(ch>='0'&&ch<='9'){
            push(&S,ch-'0');//把字符转换成数字,因为字符'0'的ASCII码是48，所以减去48就是数字本身
        }
        else{
            a=pop(&S);
            b=pop(&S);
            switch(ch){
                case '+':push(&S,a+b);break;
                case '-':push(&S,a-b);break;
                case '*':push(&S,a*b);break;
                case '/':push(&S,a/b);break;
            }
        }
        RPN++;
    }
    return getTop(S);
}
int main(){
    char RPN[100];
    printf("请输入逆波兰表达式：");
    scanf("%s",RPN);
    printf("计算结果为：%d\n",calculateRPN(RPN));
    return 0;
}