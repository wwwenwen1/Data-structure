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
int isOperator(char ch){//运算对象是infix内的字符
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='(' || ch==')')
        return TRUE;
    else
        return FALSE;
}
//判断是否为数字
int isDigit(char ch){
    if(isdigit(ch)){
        return TRUE;
    }
    return FALSE;
}//函数中直接用ctype.h库的isdigit()函数来判断是否为数字
//判断是否为左括号,废物函数
int isLeftParenthesis(char ch){
    if(ch=='('){
        return TRUE;
    }
    return FALSE;
}
//判断是否为右括号，废物函数
int isRightParenthesis(char ch){
    if(ch==')'){
        return TRUE;
    }
    return FALSE;
}
//判断运算符优先级
int priority(char ch){//栈内存储时，优先级高的才能放到优先级底的上方，#和(除外
    switch(ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '#':
            return 5;//#的优先级最低
        case '(':
            return 3;//左括号的优先级最高
        case '^':
            return 4;//幂运算符的优先级最高
        default:
            printf("ERROR,invalid operator.\n");
            return -1;
    }
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
        if(isdigit(infix[i])){//如果infix[i]是数字
            postfix[index]=infix[i];//如果为数字，则直接放入postfix
            index++;//更新index的位置
        }
        else if(infix[i]=='('){//遇到左括号直接入栈
            push(&S,infix[i]);
            continue;
        }
        else if(infix[i]==')'){//遇到右括号，就一直出栈，直到遇到左括号
            if(getTop(S)!='#'){
                do{
                        postfix[index]=pop(&S);
                        index++;
                    } while (getTop(S)!='(');
                    pop(&S);//把左括号弹出
                continue;
            }
            else{
                printf("empty stack,can\'t continue.\n");
                return 0;
            }
        }
        else if(isOperator(infix[i])){//如果infix[i]是其他操作符,只能把优先级高的放到优先级小的上方
            char TOP=getTop(S);//TOP是用来减少函数调用的变量
            if(priority(infix[i])>priority(TOP) || TOP=='(' || TOP=='#'){//1.插入元素的优先级高于栈内元素，直接入栈，2.如果栈顶元素是左括号，直接入栈，3.如果栈顶元素是#，直接入栈
                push(&S,infix[i]);
            }else{                                     //插入元素的优先级低于或等于栈内元素，弹出站内优先级低于或等于的所有元素
                while(priority(infix[i])<=priority(TOP)){
                    postfix[index]=pop(&S);
                    index++;
                    TOP=getTop(S);
                    if(TOP=='(' || TOP=='#'){
                        break;//如果栈顶元素是左括号或者#，就不再弹出
                    }
                }
                push(&S,infix[i]);
            }
        }
    }
    //把S内剩余的运算符依次弹出，加入到序列postfix
    while(getTop(S)!='#'){
        postfix[index]=pop(&S);
        index++;
    }
    return 0;
}

int bracketcheck(char str[]){           //用数组来存储字符串的好处是可以用strlen()函数来获取字符串的长度，而用指针则不行，因为指针只是一个地址，不知道地址后面有多少内容
    int length=strlen(str);             
    LinkStack S;                        
    initStack(&S);                      
    for(int i=0;i<length;i++){          //遍历字符串,遇到左括号就入栈，遇到匹配的右括号就出栈，遇到不匹配的就返回0
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            push(&S,str[i]);
        }
        else if(str[i]==')'||str[i]==']'||str[i]=='}'){//遇到右括号,判断栈是否为空，如果为空就返回0，如果不为空就判断栈顶元素是否匹配，如果匹配就出栈，如果不匹配就返回0
            if(isEmpty(S)){
                printf("括号不匹配1.\n");
                return 0;
            }
            else{
                char top=getTop(S);
                if((top=='('&&str[i]==')')||(top=='['&&str[i]==']')||(top=='{'&&str[i]=='}')){
                    pop(&S);
                }
                else{
                    printf("括号不匹配2.\n");
                    return 0;
                }
            }
        }
    }
    if(isEmpty(S)){
        printf("括号匹配.\n");
        return 1;
    }
    else{
        printf("括号不匹配3.\n");
        return 0;
    }
}
int main(){
    char infix[MAX];
    char postfix[MAX];
    printf("Please input the infix expression:\n");
    scanf("%s",infix);      //%s是以空格为分隔符的，所以不能输入带空格的表达式
    //运算前先检查括号是否匹配
    if(bracketcheck(infix)==0){
        printf("输入infix的括号不匹配.\n");
        return 0;
    }
    infixToPostfix(infix,postfix);
    printf("The postfix expression is:\n");
    printf("%s",postfix);
    return 0;
}