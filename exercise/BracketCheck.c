#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    if(L->next==NULL)       //if(L->data=0)也可以
        return 1;
    else
        return 0;
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
    NewNode->next=(*ptrL)->next;        //先让新节点的next指向头指针，然后让头指针指向新节点
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
char getTop(LinkStack L){
    return L->next->data;               //L是指向头节点的指针(头指针)，L->next是指向第二个节点的指针(真正开始存储数据的节点)，L->next->data是第二个节点的数据域
}

//检测括号是否匹配的函数
int bracketcheck(char str[]){           //用数组来存储字符串的好处是可以用strlen()函数来获取字符串的长度，而用指针则不行，因为指针只是一个地址，不知道地址后面有多少内容
    int length=strlen(str);
    LinkStack S;
    initStack(&S);
    for(int i=0;i<length;i++){      //遍历字符串,遇到左括号就入栈，遇到匹配的右括号就出栈，遇到不匹配的就返回0
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
    char str[100];
    printf("请输入括号序列：");
    gets(str); /*gets()函数可以读取空格，但是不安全，因为不知道输入的字符串有多长，可能会造成缓冲区溢出，
                所以不推荐使用，推荐使用fgets()函数，但是fgets()函数不能读取空格，所以要用空格作为结束标
                志，但是这样就不能输入包含空格的字符串了，所以还是用gets()函数吧*/
    bracketcheck(str);
    return 0;
}

