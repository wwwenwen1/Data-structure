#include <stdio.h>
#include <stdlib.h>
//定义单链表每个节点的形式
typedef struct Lnode{
    int data;
    struct Lnode *next;
}Lnode,*LinkList;
//含有头结点链表的初始化需要定义头节点并且分配内存
//初始化链表
int initList(LinkList* pointerToList){
    *pointerToList = (Lnode*)malloc(sizeof(Lnode));         //头指针指向头节点
    if((*pointerToList)==NULL){
        printf("ERROR,Memory allocate failed.\n");
        return 1;
    }
    (*pointerToList)->data = 0;
    (*pointerToList)->next = NULL;
    return 0;
}

//按照位序插入
int insertAtPosition(LinkList* pointerToList,int position,int element){
    Lnode* currentNode,* newNode;
    int currentPosition = 0;                                        //0位序就是头结点
    currentNode = *pointerToList;
    if(position<1){                                            
        printf("Invalid position.\n");
        return 1;
    }
    if(position>(*pointerToList)->data){
        printf("ERROR,Position exceeds the length of the list.\n");
        return 1;
    }

    while(currentPosition<position-1){   //迭代使得当前位序到达插入位序的前一个位序 
        currentNode = currentNode->next;
        currentPosition++;
    }

    newNode=(Lnode*)malloc(sizeof(Lnode));
    if(newNode==NULL){
        printf("insert failed,unable to allocate memory for newNode.\n");
        return 1;
    }
    newNode->data = element;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    (*pointerToList)->data++;
    return 0;
}

//头插法
int insertAtHead(LinkList* pointerToList,int element){
    Lnode* newNode;
    newNode = (Lnode*)malloc(sizeof(Lnode));
    if(newNode==NULL){
        printf("ERROR,insert failed,unable to allocate memory for newNode.\n");
        return 1;
    }
    newNode->data = element;
    newNode->next = (*pointerToList)->next;
    (*pointerToList)->next = newNode;
    (*pointerToList)->data++;
    return 0;
}

//尾插法
int insertAtEnd(LinkList* PointerTolist,int element){
    Lnode* newNode,*currentNode;
    newNode = (Lnode*)malloc(sizeof(Lnode));
    if(newNode==NULL){
        printf("ERROR,insert failed,unable to allocate memory for newNode.\n");
        return 1;
    }
    newNode->data = element;
    newNode->next = NULL;
    currentNode = *PointerTolist;
    while(currentNode->next!=NULL){
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    (*PointerTolist)->data++;
    return 0;
}

//头插法创建链表
int createListAtHead(LinkList* pointerToList){
    int element;
    Lnode* newNode;
    printf("Please input the element of the list,enter -1 to end.\n");
    scanf("%d",&element);
    while(element!=-1){
        newNode = (Lnode*)malloc(sizeof(Lnode));
        if(newNode==NULL){
            printf("ERROR,insert failed,unable to allocate memory for newNode.\n");
            return 1;
        }
        newNode->data = element;
        newNode->next = (*pointerToList)->next;
        (*pointerToList)->next = newNode;
        (*pointerToList)->data++;
        scanf("%d",&element);
    }
    return 0;
}

//尾插法创建链表
int createListAtEnd(LinkList* pointerToList){
    int element;
    Lnode* newNode,*currentNode;
    newNode=NULL;               //新节点初始化为空,防止野指针
    currentNode = *pointerToList;
    while(currentNode->next!=NULL){
        currentNode = currentNode->next;
    }
    printf("Please input the element of the list,enter -1 to end.\n");
    scanf("%d",&element);
    while(element!=-1){
        newNode = (Lnode*)malloc(sizeof(Lnode));
        if(newNode==NULL){
            printf("ERROR,insert failed,unable to allocate memory for newNode.\n");
            return 1;
        }
        newNode->data = element;
        newNode->next = NULL;
        currentNode->next = newNode;
        currentNode = newNode;          //插入结束,把代表尾节点的currentNode更新为新插入的节点，方便下次插入
        (*pointerToList)->data++;
        scanf("%d",&element);
    }
    return 0;
}

//按位查找
Lnode* getByPosition(LinkList list,int position){
    if(position<1 || position>(list->data)){
        printf("ERROR,Invalid position.\n");
        return NULL;
    }
    Lnode* currentNode=list->next;
    int currentPosition = 1;
    while(currentPosition!=position){
        currentNode=currentNode->next;
        currentPosition++;
    }
    printf("Success,element in this position is %d.\n",currentNode->data);
    return currentNode;
}

//按值查找
Lnode* getByElement(LinkList list,int element){
    Lnode* currentNode;
    int currentPosition=1;
    currentNode = list->next;
    while(currentNode!=NULL && currentNode->data!=element){
        currentNode = currentNode->next;
        currentPosition++;
    }
    if(currentNode==NULL){
        printf("ERROR,element not found.\n");
        return NULL;
    }
    printf("Success,this element is in position %d.\n",currentPosition);
    return currentNode;
}

//按位删除
int deleteByPosition(LinkList* pointerToList,int position){
    if(position<1 || position>((*pointerToList)->data)){  //避免无效position.
        printf("ERROR,Invalid position.\n");
        return 1;
    }
    Lnode* currentNode,*previousNode;
    int currentPosition = 0;
    currentNode = (*pointerToList)->next;
    while(currentPosition!=position){   //迭代，直到当前位置就是要找的位置
        previousNode = currentNode;
        currentNode = currentNode->next;
        currentPosition++;
    }
    previousNode->next = currentNode->next;                         //将前一个节点的指针指向当前节点的下一个节点
    free(currentNode);                                              //释放当前节点的内存
    (*pointerToList)->data--;
    return 0;
}

//按值删除
int deleteByElement(LinkList* pointerToList,int element){
    Lnode* currentNode,*previousNode;
    currentNode = (*pointerToList)->next;
    while(currentNode!=NULL && currentNode->data!=element){
        previousNode = currentNode;
        currentNode = currentNode->next;
    }   

    if(currentNode==NULL){
        printf("ERROR,element not found.\n");
        return 1;
    }
    previousNode->next = currentNode->next;
    free(currentNode);
    (*pointerToList)->data--;
    return 0;
}

//打印链表
int printList(LinkList list){
    Lnode* currentNode;
    currentNode = list->next;
    //打印链表
    printf("LinkList(headNode):\n");
    printf("LinkList:    |");
    while(currentNode!=NULL){
        printf("%6d|",currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
    //打印分割
    for(int i=0;i<(list->data)+2;i++)
		printf("-------");
    printf("\n");
    //打印位序
    printf("Position:    |");
    for(int i=1;i<=(list->data);i++)
        printf("%6d|",i);
    printf("\n");
    //打印分割
    for(int i=0;i<(list->data)+2;i++)
        printf("-------");
    printf("\n");
    //打印总和
    printf("total:%d\n\n",list->data);
    return 0;
}

//逆转链表(把链表顺序颠倒,把所有指针换成指向上一个节点)
int reverseList(LinkList* pointerToList){
    Lnode *currentNode,*previousNode,*nextNode;
    currentNode = (*pointerToList)->next;
    previousNode = NULL;
    nextNode = NULL;
    while(currentNode!=NULL){
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }
    (*pointerToList)->next = previousNode;
    return 0;
}

//摧毁链表
int destroyList(LinkList* pointerToList){
    Lnode *currentNode, *tempNode;
	currentNode=*pointerToList;
	while(currentNode!=NULL){
		tempNode=currentNode;
		currentNode=currentNode->next;
        free(tempNode);
	}
	*pointerToList=NULL;
	return 0;
}

int main(){
    LinkList L1;
    LinkList L2;
    initList(&L1);
    initList(&L2);
    createListAtHead(&L1);
    createListAtEnd(&L2);
    printList(L1);
    printList(L2);
    
    return 0;
}
