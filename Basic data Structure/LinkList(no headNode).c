#include <stdio.h>
#include <stdlib.h>
//不含头结点
//定义了单链表每一节节点的结构，单链表的节点结构为Lnode，单链表的头指针为LinkList			
typedef struct Lnode{																	
	int data;	
	struct Lnode* next;	
}Lnode, *LinkList;											
//Lnode和*LinkList等价，仅为代码可读性					
//Lnode强调链表节点，LinkList强调链表整体(代表头指针)			
//定义链表时 Lnode *L=LinkList L					
//LinkList *L等价于Lnode **L	
//以下是上面定义的等价形式	
/*						
struct Node{
	int data;
	struct node *next;
};			
typedef struct Node LNode;      //把LNode定义为Node类型结构体的别名，使得
								//
typedef struct Node* LinkList;  //把LinkList定义为指向Node类型结构体的指针, 
*/		   			        	//广义代表指向Node类型的指针，狭义代表头指针

//初始化单链表
//不含头结点的链表，仅仅声明一个悬空的头结点就可以了，不需要分配内存
int initList(LinkList* pointerToList){		//PointerToList为指向LinkList的指针
	*pointerToList = NULL;					//把PointerToList指向的值设为NULL
	return 0;
}

//指定位置插入
//因为要修改头指针，所以要传入指向头指针的指针作为参数
//该函数涉及三种情况需要修改链表头指针的指向：1.插入位置为1 2.插入位置为1且链表为空 3.插入位置大于1且链表为空
//如果能排除这三种情况，则可以传入LinkList List作为参数，不需要修改头指针的指向
//函数想修改一个变量的值，必须传入这个变量的指针，想修改一个指针的值(头指针)，必须传入这个指针的指针
int insertAtPosition(LinkList* pointerToList,int insertPosition,int insertElement){  	//PointerToList是LinkList*类型的指针里面放头指针的地址;insertPosition代表位序（从1开始)
	Lnode *currentNode,*newNode;
	int currentPosition = 1;										
	currentNode = *pointerToList;			 											//*PointerToList是头指针，代表链表
	if(insertPosition<1)
		return 1;
	if(insertPosition==1){
		newNode = (Lnode*)malloc(sizeof(Lnode));
		if(newNode==NULL){
		printf("insert failed,unable to allocate memory for newNode.\n");
		return 1;
	}
		newNode->next=NULL;
		newNode->data=insertElement;
		*pointerToList=newNode;                                                			//直接修改头指针
		return 0;
	}
	if(insertPosition>1){
		while(currentNode->next!=NULL && insertPosition>currentPosition-1){				//当前节点的下一个指向不为空，且当前位序没有到达插入位序的前一个位序											
		currentNode=currentNode->next;
		currentPosition++;
		}
	newNode = (Lnode*)malloc(sizeof(Lnode));
	if(newNode==NULL){
		printf("insert failed,unable to allocate memory for newNode.\n");
		return 1;
	}
	newNode->data=insertElement;
	newNode->next=currentNode->next;
	currentNode->next=newNode;
	return 0;
	}
}

//头插法
int insertAtHead(LinkList* pointerToList,int insertElement){
	Lnode* newNode;
	newNode = (Lnode*)malloc(sizeof(Lnode));
	if(newNode==NULL){
		printf("insert failed,unable to allocate memory for newNode.\n");
		return 1;
	}
	newNode->next=*pointerToList;												    //让新节点的next指向头指针指向的节点
	newNode->data=insertElement;
	*pointerToList=newNode;                                                       	//直接修改头指针
	return 0;
}

//头插法创建链表
int createListAtHead(LinkList* pointerToList){
	int element;
	Lnode *newNode;
	printf("please input elements,enter -1 to end.\n");
	scanf("%d",&element);
	while(element!=-1){
		scanf("%d",&element);
		newNode = (Lnode*)malloc(sizeof(Lnode));
        if(newNode==NULL){
            printf("ERROR,insert failed,unable to allocate memory for newNode.\n");
            return 1;
        }
        newNode->data=element;
		newNode->next=*pointerToList;											//让新节点的next指向头指针指向的节点
		*pointerToList=newNode;
    }
    return 0;
}

//尾插法
int insertAtEnd(LinkList* pointerToList,int insertElement){
	Lnode* newNode,*currentNode;
	currentNode = *pointerToList;
	newNode = (Lnode*)malloc(sizeof(Lnode));
	if(newNode==NULL){
		printf("insert failed,unable to allocate memory for newNode.\n");
		return 1;
	}
	newNode->next=NULL;
	newNode->data=insertElement;
	if(currentNode==NULL){											//如果链表为空(一个节点也没有)，直接把让头指针指向新节点
		*pointerToList=newNode;
		return 0;
	}
	while(currentNode->next!=NULL){
		currentNode=currentNode->next;
	}
	currentNode->next=newNode;
	return 0;
}

//尾插法创建链表
int createListAtEnd(LinkList* pointerToList){
	Lnode *newNode,*currentNode;
	int element;
	currentNode=*pointerToList;
	while(currentNode->next!=NULL){
		currentNode=currentNode->next;
	}
	//此时currentNode指向最后一个节点(完成迭代后)
	printf("please input elements,enter -1 to end.\n");
	scanf("%d",&element);
	while(element!=-1){
		newNode = (Lnode*)malloc(sizeof(Lnode));
		if(newNode==NULL){
			printf("ERROR,insert failed,unable to allocate memory for newNode.\n");
			return 1;
		}
		newNode->data=element;					//让新节点的data域等于输入的值
		newNode->next=NULL;						//让新节点的next指向NULL
		currentNode->next=newNode;				//让当前节点的next指向新节点
		currentNode=currentNode->next;			//让当前节点前进一个节点
		scanf("%d",&element);
	}	
	return 0;
}


//按值查找
Lnode* getByElement(LinkList list,int element){
	Lnode* currentNode;
	currentNode = list;
	int currentPosition=1;
	while(currentNode!=NULL){
		if(currentNode->data==element){
			printf("Success,this element is on node %d.\n",currentPosition);
			return currentNode;
		}
		currentNode=currentNode->next;
		currentPosition++;
	}
	printf("Can't find this element.\n");
	return NULL;
}

//按位查找
Lnode* getByPosition(LinkList list,int position){
	if(position<1){
		printf("ERROR,invalid position.\n");
		return NULL;
	}
	Lnode* currentNode;
	currentNode=list;
	int currentPosition=1;
	while(currentNode!=NULL && position!=currentPosition){
		currentNode=currentNode->next;
		currentPosition++;
	}
	if(currentNode==NULL){
			printf("can't find this position.\n");
			return NULL;
		}
	printf("Success,element on this position is %d.\n",currentNode->data);
	return currentNode;
}

//按值删除
int deleteByElement(LinkList* pointerToList,int element){
	Lnode* currentNode,*previousNode;
	currentNode = *pointerToList;
	int currentPosition = 1;
	if(currentNode==NULL){
		printf("ERROR,empty list.\n");
		return 1;
	}
	while(currentNode->data!=element){
		previousNode=currentNode;
		currentNode=currentNode->next;
		currentPosition++;
		if(currentNode==NULL){
			printf("ERROR,can't find this element.\n");
			return 1;
		}
	}
	if(currentPosition==1){									//如果要删除的是第一个节点
		*pointerToList=currentNode->next;
		free(currentNode);
		return 0;
	}
	if(currentPosition>1 && currentNode->data==element){	//如果要删除的不是第一个节点
		previousNode->next=currentNode->next;
		free(currentNode);
		return 0;
	}
}

//按位删除
int deleteByPosition(LinkList* pointerToList,int position){
	if(position<1){								//检测输入
		printf("ERROR,invalid position.\n");
		return 1;
	}
	Lnode* currentNode;
	Lnode* previousNode;
	int currentPosition = 1;
	currentNode=*pointerToList;
	while(currentNode!=NULL && position!=currentPosition){	//要么链表遍历到了末尾，要么当前位置就是所需位置，才能结束循环
		previousNode=currentNode;                            
		currentNode=currentNode->next;						//这两步顺序不能错，保证previousNode是currentNode的前一个节点
		currentPosition++;
	}
	if(currentNode==NULL){									//currentNode为NULL,则链表遍历到了末尾，至此还没找到对应位置
			printf("can't find this position.\n");
			return 1;
	}
	if(currentPosition==1){									//如果要删除的是第一个节点
		*pointerToList=currentNode->next;
		free(currentNode);
		return 0;
	}
	if(currentPosition>1 && currentPosition==position){	//如果要删除的不是第一个节点
		previousNode->next=currentNode->next;
		free(currentNode);
		return 0;
	}
}

//摧毁链表
int destroyList(LinkList* pointerToList){
	Lnode *currentNode, *previousNode;
	currentNode=*pointerToList;
	if(currentNode==NULL){
		printf("ERROR,empty list.\n");
		return 1;
	}
	while(currentNode!=NULL){
		previousNode=currentNode;
		currentNode=currentNode->next;
		free(previousNode);
	}
	*pointerToList=NULL;
	return 0;
}

//打印链表(不需要修改List,故使用头指针作为参数按值传递)
int printList(const LinkList list){ 								//传入常量指针，printList无法通过指针修改链表
	Lnode* currentNode;
	currentNode = list;												//currentNode指向第一个节点
	int currentPosition = 0;
	//打印链表
	printf("LinkList:    |");
	while(currentNode!=NULL){										//当前节点不为空就打印当前节点
		printf("%6d|",currentNode->data);                 			//currentNode->data == (*currentNode).data
		currentNode = currentNode->next;
		currentPosition++;
	}
	printf("\n");
	//打印分割线
	for(int i=0;i<currentPosition+2;i++)
		printf("-------");
	printf("\n");
	//打印位序
	printf("Position:    |");
	for(int i=0;i<currentPosition;i++)
		printf("%6d|",i+1);
	printf("\n");
	//打印分割线
	for(int i=0;i<currentPosition+2;i++)
		printf("-------");
	printf("\n");
	//打印总数
	printf("total:%d\n",currentPosition);
}

//逆转链表(方法一,挨个翻转节点的指向,最后修改头指针的指向)
int reverseList1(LinkList* pointerToList){
	Lnode* currentNode,* previousNode,* nextNode;
	currentNode=*pointerToList;
	previousNode=NULL;						//1.防止野指针 2.让previousNode提前指向NULL，方便接下来翻转
	nextNode=NULL;							//防止野指针
	while(currentNode!=NULL){
		nextNode=currentNode->next;         //让nextNode成为currentNode的下一个节点
		currentNode->next=previousNode;		//翻转指针：让当前节点指向上一个节点
		previousNode=currentNode;			//让previousNode前进一个节点
		currentNode=nextNode;				//让currentNode前进一个节点
	}
	*pointerToList=previousNode;
	return 0;
}

//逆转链表(方法二,创建新链表，把原链表的节点依次用头插法插入新链表的头部)
int reverseList2(LinkList* pointerToList){
	LinkList tempList;
	initList(&tempList);
	Lnode* currentNode,* newNode;
	currentNode=*pointerToList;
	newNode=(Lnode*)malloc(sizeof(Lnode));
	if(newNode==NULL){
		printf("ERROR,unable to allocate memory for newNode.\n");
		return 1;
	}
	while(currentNode!=NULL){
		newNode=(Lnode*)malloc(sizeof(Lnode));
		newNode->data=currentNode->data;
		newNode->next=tempList;
		tempList=newNode;
		currentNode=currentNode->next;
	}
	*pointerToList=tempList;
	return 0;
}

//逆转链表(方法三,递归)
int reverseList3(LinkList* pointerToList){
	Lnode* currentNode,* nextNode;
	currentNode=*pointerToList;
	if(currentNode==NULL || currentNode->next==NULL)	//如果链表为空或者只有一个节点，直接返回
		return 0;
	nextNode=currentNode->next;							//nextNode指向当前节点的下一个节点
	reverseList3(&nextNode);						
	currentNode->next->next=currentNode;				//递归到最后一个节点，然后开始回溯，回溯时，每个节点的next指向前一个节点
	currentNode->next=NULL;								//最后一个节点的next指向NULL
	*pointerToList=nextNode;							
	return 0;
}

//关于函数的参数的选择
//使用LinkList *PointerToList的函数，可以修改头指针的指向
//使用LinkList List的函数，可以修改第一个节点的内容，但不能修改头指针的指向

int main(){
//初始化单链表
	LinkList L;   										//此处L代表头指针，也代表整个链表
	initList(&L);
	insertAtPosition(&L,1,7);
	insertAtPosition(&L,2,1);
	insertAtPosition(&L,3,0);
	insertAtPosition(&L,4,2);
	insertAtPosition(&L,5,4);
	insertAtPosition(&L,6,1);
	insertAtPosition(&L,7,4);
	insertAtPosition(&L,8,1);
	insertAtPosition(&L,9,3);
	printf("this is the original list:\n");
	printList(L);
	reverseList2(&L);
	printf("this is the reversed list:\n");
	printList(L);
	reverseList1(&L);
	printf("this is the list after reversed again:\n");
	printList(L);
	reverseList3(&L);
	printf("this is the list after reverseList3:\n");
	printList(L);
	return 0;
}
