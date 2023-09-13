//中缀表达式转后缀表达式
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>//该行的作用是引入ctype.h头文件，ctype.h头文件中定义了一些用于测试和映射字符的函数原型

#define MAX 100
#define TRUE 1
#define FALSE 0

//直接把链栈的内容拿过来用
typedef struct node{
    char data;
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
    if(L->next==NULL)       
        return TRUE;
    else
        return FALSE;
}
//
int push(LinkStack* ptrL,char value){
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
char pop(LinkStack* ptrL){
    SNode* TopNode;
    char value;
    TopNode=(*ptrL)->next;              //取出第二个节点
    value=TopNode->data;                
    (*ptrL)->next=TopNode->next;        //让首节点的后继节点变成第三个节点
    free(TopNode);                      //释放第二个节点
    return value;
}
//
char getTop(LinkStack S){
    char top;
    top=S->next->data;
    return top;                         //S是指向头节点的指针(头指针)，S->next是指向第二个节点的指针(真正开始存储数据的节点)，S->next->data是第二个节点的数据域
}

//判断是否为运算符
int isOperator(char ch){
 
}
//判断是否为数字
int isDigit(char ch){
 
}
//判断是否为左括号
int isLeftParenthesis(char ch){
 
}
//判断是否为右括号
int isRightParenthesis(char ch){
 
}
//判断运算符优先级
int priority(char ch){
 
}
//中缀表达式转后缀表达式
int infixToPostfix(char infix[],char* postfix){      //为什么使用指针，而不是字符数组，
//                                                     因为字符数组是不能改变的，而指针可以改变
    LinkStack S;//用来存放操作符的栈
    initStack(&S);
    push(&S,'#');//用来统一操作，读取到#表示已经达到栈底，不需要去使用isEmpty函数
    int length=strlen(infix);
    int index=0;
    for(int i=0;i<length;i++){//遍历字符串
        if(isDigit(infix[i])){//如果infix[i]是数字
            postfix[index]=infix[i];//如果为数字，则直接放入postfix
            index++;//更新index的位置
        }
        else if(isLeftParenthesis(infix[i])){//遇到左括号直接入栈
            push(&S,infix[i]);
            continue;
        }
        else if(isRightParenthesis(infix[i])){//遇到右括号，就一直出栈，直到遇到左括号
            do{
                    postfix[index]=pop(&S);
                    index++;
                } while (infix[i]!='(');
            continue;
        }
        else if(isOperator(infix[i])){//如果infix[i]是操作符
            if(priority(infix[i])>priority(getTop(S))){//插入元素的优先级高于栈顶元素，直接插入
                push(&S,infix[i]);
            }else{                                     //插入元素的优先级低于或等于栈内元素，弹出站内优先级低或相等的所有元素
                do{
                    postfix[index]=pop(&S);
                    index++;
                } while (infix[i]>priority(getTop(S)) || isLeftParenthesis(getTop(&S)));
                push(&S,infix[i]);
            }
            
        }

    }
    return 0;
}
int main(){
    char infix[MAX];
    char postfix[MAX];
    printf("Please input the infix expression:\n");
    scanf("%s",infix);//%s是以空格为分隔符的，所以不能输入带空格的表达式
    infixToPostfix(infix,postfix);
    printf("The postfix expression is:\n");
    printf("%s",postfix);
    return 0;
}