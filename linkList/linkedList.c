//#include "../head/linkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"
	struct LNode *pCurrent;
	struct LNode *preNode;
	struct LNode *nextNode;



/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {          //创建只有一个头节点的空链表
	if(!L) //判断L是否存在
	return ERROR;
	(*L)=(LinkedList)malloc(sizeof(LNode));//创建空间
	(*L)->next=NULL;
	return SUCCESS;
}



void EmptyList(LinkedList *L) {			// 置空链表
	if(*L==NULL)
		printf("L为空链表\n");
	//创建临时指针
	else{
		struct LNode *pCurrent=(*L)->next;
		while(pCurrent){
			//先保存待删除节点后面的节点
				struct LNode * nextNode=pCurrent->next;
				free(pCurrent);
				pCurrent=nextNode;
		}
	}
}
/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {			// 销毁一个链表，释放所有节点
	if(*L==NULL)
		printf("L为空链表\n");
	//创建临时指针
	else{
		struct LNode *pCurrent=(*L)->next;
		while(pCurrent){
			//先保存待删除节点后面的节点
				struct LNode * nextNode=pCurrent->next;
				free(pCurrent);
				pCurrent=nextNode;
		}
		//释放头节点
		free(*L);
		(*L)=NULL;
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {

	if(p==NULL)   //判断是否为空链表
		return ERROR;
	p->next=q;

}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if(p==NULL)
		return ERROR;
	//创建临时指针
	struct LNode *pCurrent=p;
	p=pCurrent->next;
	//先保存待删除节点后面的节点
	p=pCurrent->next;
	*e=pCurrent->data;
	printf("第一个节点的数据是:%d\n",*e);
	pCurrent->next=NULL;
		free(p);

}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	//判断是否为空链表
	if(L==NULL)
		printf("该链表为空链表\n");
	else{
		while (L!=NULL){
			visit(L->data);   //利用visit函数输出数据
			L=L->next;
		}
	}

}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */      										 //根据e找到链表中的第一个节点
Status SearchList(LinkedList L, ElemType e) {
		if(L==NULL)
	 	return ERROR;
	struct LNode *pCurrent=L->next;
	// 循环终止的条件
	while (pCurrent !=NULL){
		int i=1;
		// 找到要找的节点
		if(pCurrent->data==e){
			printf("当前节点的位置是%d\n",i);
		printf("%d",pCurrent->data);
		pCurrent=pCurrent->next;
		i++;
		break;
		}
	else
		printf("链表中不存在该数据\n");
	}

}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	//判断是否为空链表
	if(*L==NULL)
		return ERROR;
	preNode=(*L)->next;
	(*L)->next=NULL;
	//利用while循环找到最后一个节点
	while(preNode){
		pCurrent=preNode->next;
		preNode->next=*L;
		*L=preNode;
		preNode=pCurrent;

	}
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	//定义快慢指针
	struct LNode *slowNode=L->next;
	struct LNode *fastNode=(L->next)->next;
	//判断当快慢指针是否NULL
	while(slowNode!=NULL && fastNode!=NULL){
		fastNode=(fastNode->next)->next;
		slowNode=slowNode->next;
	//如果快慢指针相遇
	if(fastNode==slowNode)
		printf("该链表成环\n");
	else
		printf("该链表不成环\n") ;
	}
}


/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	if((*L)&&(*L)->next)
		return NULL;
	struct LNode *pCurrent=*L;     //创建三个临时指针,一个保存奇数节点地址,一个保存偶数节点地址
	struct LNode *oddNode=(*L)->next;
	struct LNode *evenNode=oddNode->next;
	//确定第一个奇节点,第一个偶节点
	pCurrent=evenNode->next;
	evenNode=oddNode->next;
	while(oddNode&&evenNode){
		//奇偶往后遍历
		oddNode=evenNode->next;
		evenNode=oddNode->next;
		//将奇偶调换相连
		pCurrent=evenNode->next;
		evenNode=oddNode->next;
 	}
}


/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	if(*L==NULL)
		printf("list is not found\n");
	else{
		//定义快慢指针
		struct LNode *slowNode=(*L)->next;
		struct LNode *fastNode=((*L)->next)->next;
		while(fastNode!=NULL){      //快指针走的比慢制作快两倍,当快制作走到末尾时.慢指针所在位置就是中间节点
			int i=0;
			slowNode=slowNode->next;
			fastNode=(fastNode->next)->next;
			i++;
			//输出中间节点的位置
			if(fastNode==NULL){
				printf("第%d个节点是中间节点\n",i);
				break;
			}
		}
	}
}


//定义 输出数据的函数
void printf_data (int a)	{
	printf("当前节点的数据是%d\n",a);
}
//定义函数指针
void (*visit)(int a)=printf_data;

//往链表中传入数据
void func1(LNode *one){
	int i;
	for(i=1;i<5;i++){
		one->data=i;
		one=one->next;
		printf("%d\n",one->data);
	}
}
void func2(LNode *two){
	int i;
	for(i=5;i<9;i++){
		two->data=i;
		two=two->next;
		printf("%d\n",two->data);
	}

}

