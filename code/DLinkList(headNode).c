#include<stdlib.h>
#include<stdio.h>
typedef struct DLnode{
    int data;
    struct DLnode *prior,*next;
}DLnode,*DLinkList;

//初始化双链表
int initList(DLinkList* pointerToList){
    *pointerToList = (DLnode*)malloc(sizeof(DLnode));
    if(*pointerToList==NULL){
        printf("ERROR,Memory allocate failed.\n");
        return 1;
    }
    (*pointerToList)->data = 0;
    (*pointerToList)->next = NULL;                      //双链表头结点的next暂时指向NULL，因为双链表暂时为空
    (*pointerToList)->prior = NULL;                     //双链表头结点的prior永远指向NULL，因为双链表永远没有前驱
    return 0;
}

//按位序插入
int insertAtPosition(DLinkList* pointerToList,int position,int element){
    DLnode* currentNode,* newNode,*previousNode;
    int currentPosition = 1;
    currentNode=(*pointerToList)->next;
    newNode=NULL;
    if(position>(*pointerToList)->data){                 //防止要插入的位置超出链表长度
        printf("ERROR,wrong position.\n");
        return 1;
    }
    while(currentPosition<position){
        previousNode=currentNode;
        currentNode=currentNode->next;
        currentPosition++;
    }   
    //经过迭代后，currentNode就是position位置的节点，previousNode就是position前一个位置的节点
    newNode=(DLnode*)malloc(sizeof(DLnode));
    if(newNode==NULL){
        printf("ERROR,Memory allocate failed.\n");
        return 1;
    }
    (*pointerToList)->data++;                              //双链表长度加一
    newNode->data=element;                                 //新节点的数据域赋值
    newNode->next=previousNode->next;                      //新节点的next指向position位置的节点
    newNode->prior=previousNode;                           //新节点的prior指向position前一个位置的节点
    previousNode->next=newNode;                            //position前一个位置的节点的next指向新节点
    currentNode->prior=newNode;                            //position位置的节点的prior指向新节点  
    return 0;
}

//头插法
int insertAtHead(DLinkList* pointerToList,int element){
    DLnode* newNode,*currentNode;
    currentNode=(*pointerToList)->next;             //currentNode指向头结点的next，即第一个节点
    newNode=(DLnode*)(malloc(sizeof(DLnode)));
    if(newNode==NULL){
        printf("ERROR,insert failed,unable to allocate memory for newNode.\n");
        return 1;
    }
    newNode->data=element;                  //新节点的数据域赋值
    newNode->next=currentNode;              //新节点的next指向第一个节点
    newNode->prior=currentNode->prior;      //新节点的prior指向头结点
    currentNode->prior=newNode;             //第一个节点的prior指向新节点
    (*pointerToList)->next=newNode;         //头结点的next指向新节点
    (*pointerToList)->data++;
    return 0;
}

//尾插法
int insertAtEnd(DLinkList* pointerToList,int element){
    DLnode* newNode,*currentNode;
    currentNode=(*pointerToList);
    newNode = (DLnode*)malloc(sizeof(DLnode));
    if(newNode==NULL){
        printf("ERROR,insert failed,unable to allocate memory for newNode.\n");
        return 1;
    }
    newNode->data=element;
    newNode->next=NULL;
    while(currentNode->next!=NULL){
        currentNode=currentNode->next;
    }
    currentNode->next=newNode;
    newNode->prior=currentNode;
    (*pointerToList)->data++;
    return 0;
}

//头插法创建双链表
int createListAtHead(DLinkList* pointerToList){
    int element;
    DLnode* newNode,*headNode,*firstNode;
    firstNode=NULL;                             //第一个节点初始化为空,防止野指针
    newNode=NULL;                               //新节点初始化为空,防止野指针
    headNode=*pointerToList;                    //currentNode指向头结点
    if(headNode->next!=NULL){                   //如果头结点的next不为空，说明双链表不为空，那么firstNode指向第一个节点
        firstNode=headNode->next;
    }
    printf("Please input the element of the list,enter -1 to end.\n");
    scanf("%d",&element);
    while(element!=-1){
        newNode=(DLnode*)malloc(sizeof(DLnode));
        if(newNode==NULL){                      //如果内存分配成功，newNode指向新分配的内存，否则newNode为空
            printf("ERROR,Memory allocate failed.\n");
            return 1;
        }
        newNode->data=element;              //新节点的数据域赋值
        newNode->next=headNode->next;       //新节点的next指向第一个节点
        newNode->prior=*pointerToList;      //新节点的prior指向头结点//第一个节点与头结点是双向连接的
        headNode->next=newNode;             //头结点的next指向新节点
        if(firstNode!=NULL)                 //如果插入前第一个节点不为空，那么第一个节点的prior指向新节点
            firstNode->prior=newNode;
        (*pointerToList)->data++;           //双链表长度加一
        scanf("%d",&element);
    }
    return 0;
}

//尾插法创建双链表
int createListAtEnd(DLinkList* pointerToList){
    int element;
    DLnode* newNode,*currentNode;
    newNode=NULL;                               //新节点初始化为空,防止野指针
    currentNode=*pointerToList;                 //currentNode指向第一个节点
    while(currentNode->next!=NULL){             //迭代，使得currentNode指向最后一个节点
        currentNode=currentNode->next;
    }
    printf("Please input the element of the list,enter -1 to end.\n");
    scanf("%d",&element);
    while(element!=-1){
        newNode=(DLnode*)malloc(sizeof(DLnode));
        if(newNode==NULL){                      //如果内存分配成功，newNode指向新分配的内存，否则newNode为空
            printf("ERROR,Memory allocate failed.\n");
            return 1;
        }
        newNode->data=element;              //新节点的数据域赋值
        newNode->next=NULL;                 //新节点的next指向NULL
        currentNode->next=newNode;
        newNode->prior=currentNode;         //新节点的prior指向最后一个节点
        currentNode=newNode;                //插入结束,把代表尾节点的currentNode更新为新插入的节点，方便下次插入
        (*pointerToList)->data++;           //双链表长度加一
        scanf("%d",&element);
    }
    return 0;
}

//按值删除
int deleteByElement(DLinkList* pointerToList,int element){
    DLnode* currentNode,* previousNode,* nextNode;
    currentNode = (*pointerToList)->next;
    previousNode=NULL;                      //初始化指针，防止野指针
    nextNode=NULL;                          //初始化指针，防止野指针
    while(currentNode!=NULL && currentNode->data!=element){
        //previousNode=currentNode;
        currentNode=currentNode->next;
    }

    if(currentNode==NULL){
        printf("ERROR,element not found.\n");
        return 1;
    }
    previousNode=currentNode->prior;        //直接通过prior获取前继节点
    nextNode=currentNode->next;             //直接通过next获取后继节点 
    if(previousNode!=NULL) 
        previousNode->next=nextNode;        //前继节点的next指向后继节点
    if(nextNode!=NULL)
        nextNode->prior=previousNode;       //后继节点的prior指向前继节点
    (*pointerToList)->data--;               //双链表长度减一
    free(currentNode);                      //释放内存,会自动释放数据域，还有next和prior指针
    return 0;
}

//按位删除
int deleteByPosition(DLinkList* pointerToList,int position){
    if(position<1 || position>(*pointerToList)->data){
        printf("ERROR,Invalid position.\n");
        return 1;
    }
    DLnode*currentNode,*previousNode,*nextNode;
    int currentPosition = 1;
    currentNode = (*pointerToList)->next;   //currentNode指向第一个节点
    previousNode=NULL;                      //初始化指针，防止野指针
    nextNode=NULL;                          //初始化指针，防止野指针
    while(currentPosition!=position){       //迭代，直到当前位置就是要找的位置
        //previousNode=currentNode;         //双链表有prior指针，不需要不断记录前继节点
        currentNode=currentNode->next;
        currentPosition++;
    }
    previousNode=currentNode->prior;        //直接通过prior获取前继节点
    nextNode=currentNode->next;             //直接通过next获取后继节点
    //if(previousNode!=NULL)            //前继节点的不可能为空，因为双链表的第一个节点的prior指向头结点
    previousNode->next=nextNode;        //前继节点的next指向后继节点
    if(nextNode!=NULL)
        nextNode->prior=previousNode;       //后继节点的prior指向前继节点//双链表第一个节点的
    (*pointerToList)->data--;               //双链表长度减一
    free(currentNode);                      //释放内存,会自动释放数据域，还有next和prior指针
    return 0;
}

//按位查找
DLnode* getByPosition(DLinkList list,int position){
    if(position<1 || position>(list->data)){
        printf("ERROR,Invalid position.\n");
        return NULL;
    }
    DLnode* currentNode=list->next;
    int currentPosition = 1;
    while(currentPosition!=position){
        currentNode=currentNode->next;
        currentPosition++;
    }
    //经过迭代后，currentNode就是position位置的节点,且因为经过if判断，currentNode不可能为空
    printf("The element in this position is %d.\n",position,currentNode->data);
    return currentNode;
}

//按值查找
DLnode* getByElement(DLinkList list,int element){
    DLnode* currentNode;
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

//打印双链表(附带检查链表各个指针是否正确)
int printList(DLinkList list){
    DLnode* currentNode;
    DLnode* tempNode;
    currentNode = list->next;
    list->next->prior=NULL;           //第一个节点的prior指向NULL,该操作不会影响链表结构，因为该函数传入的是指针的值，不是指针本身
    //打印链表
    printf("DoubleLinkList(headNode):\n");
    //正序打印链表
    printf("DLinkListF2B:|");
    while(currentNode!=NULL){
        printf("%6d|",currentNode->data);
        tempNode = currentNode;
        currentNode = currentNode->next;
    }
    printf("\n");

    //逆向打印链表
    //打印前先让第一个节点的prior指向NULL，方便逆向打印
    printf("DLinkListB2F:|");
    currentNode = tempNode;
    while(currentNode!=NULL){
        printf("%6d|",currentNode->data);
        currentNode = currentNode->prior;
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

//销毁双链表
int destroyList(DLinkList* pointerToList){
    DLnode *currentNode, *tempNode;
	currentNode=*pointerToList;
	while(currentNode!=NULL){               //循环释放内存
		tempNode=currentNode;               //tempNode指向当前节点
		currentNode=currentNode->next;      //currentNode指向下一个节点
        free(tempNode);                     //释放tempNode指向的内存
	}
	*pointerToList=NULL;                    //头指针指向NULL
    printf("Success,destroyed.\n");
	return 0;
}

//双链表的逆置(通过修改next指针和prior指针，把链表顺序颠倒)
int reverseList(DLinkList* pointerToList){
    DLnode *currentNode,*previousNode,*nextNode;
    currentNode=(*pointerToList)->next;     //currentNode指向第一个节点,从第一个节点开始逆置
    previousNode=(*pointerToList);          //previousNode指向头结点
    nextNode=NULL;                          //初始化指针，防止野指针
    while(currentNode!=NULL){
        nextNode=currentNode->next;         //后继节点
        currentNode->next=previousNode;     //当前节点的next指向前驱节点
        currentNode->prior=nextNode;        //当前节点的prior指向后继节点
        previousNode=currentNode;           //previousNode指向当前节点
        currentNode=nextNode;               //currentNode指向后继节点
    }   
    (*pointerToList)->next=previousNode;    //头结点的next指向最后一个节点
    return 0;
}

//双链表的排序
int sortList(DLinkList* pointerToList){
    //用冒泡法从大到小排序element

}

int main(){
    DLinkList L;
    initList(&L);
    createListAtHead(&L);
    printf("createListAtHead:\n");
    printList(L);
    reverseList(&L);
    printf("reverseList:\n");
    printList(L);
    insertAtEnd(&L,100);
    printf("insertAtEnd:\n");
    printList(L);
    insertAtHead(&L,200);
    printf("insertAtHead:\n");
    printList(L);
    deleteByElement(&L,100);
    printf("deleteByElement:\n");
    printList(L);
    deleteByPosition(&L,1);
    printf("deleteByPosition:\n");
    printList(L);

    destroyList(&L);
    return 0;
}



