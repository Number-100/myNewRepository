#include "../head/duLinkedList.h"
#include<stdlib.h>
#include<stdio.h> 
/*	struct DuLNode *pCurrent;
	struct DuLNode *preNode; 
	struct DuLNode *nextNode;
*/
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	if(!L)   //判断L是否存在 
		return ERROR;
	(*L)=(DuLinkedList)malloc(sizeof(DuLNode));  //创建空间 
	(*L)->prior=(*L);
	(*L)->next=NULL;

}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLNode*pCurrent; //创建两个指针
    DuLNode*preNode;
    pCurrent=(*L)->next;
    while(pCurrent!=(*L)){   //遍历链表,然后释放 
        preNode=pCurrent;
        pCurrent=pCurrent->next;
        free(preNode);
    }
    free(*L);   //最后释放头节点 

}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {	
	if(p==NULL)			//判断是否为空链表 
		return ERROR;	
	q->next=p;
	q=p->prior;
	
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if(p==NULL)			//判断是否为空链表 
		return ERROR;	
	p->next=q;
	p=q->prior;

}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if(p==NULL)
		return ERROR;
	struct DuLNode *pCurrent=p->next;  //创建临时指针   保存待删除指针的后一个地址 
	pCurrent->prior->next=p->next;     //将待删除节点的前后节点相连 
	pCurrent->next->prior=p->prior;
	*e=pCurrent->data;             		// assign its value to e
	printf("第一个节点的数据是:%d",*e);
	free(pCurrent);
	
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	if(L==NULL)
		printf("linked list is  not found");
	else{
		DuLNode*pCurrent=L;
		DuLNode*preNode=L;
		while(pCurrent->next!=preNode) {//链表为偶数时交叉
			if(pCurrent==preNode){     //链表为奇数时相遇
				printf("%d\n",pCurrent->data);
				break;                 //相遇意味着双向遍历完成,退出循环
			}
		printf("%d\n",pCurrent->data);
		printf("%d\n",preNode->data);
		
		pCurrent=pCurrent->next;
		preNode=preNode->prior;
		}
	}

}

//定义 输出数据的函数 
void printf_data (int a)	{
	printf("当前节点的数据是%d",a);
}
//定义函数指针 
void (*visit)(int a)=printf_data;

