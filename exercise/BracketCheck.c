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
int bracketcheck(char str[]){
    int length=strlen(str);
    LinkStack S;
    initStack(&S);
    for(int i=0;i<length;i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            push(&S,str[i]);
        }
        else if(str[i]==')'||str[i]==']'||str[i]=='}'){
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
    scanf("%s",str);
    bracketcheck(str);
    return 0;
}