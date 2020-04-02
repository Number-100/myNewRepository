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
	if(!L)   //�ж�L�Ƿ���� 
		return ERROR;
	(*L)=(DuLinkedList)malloc(sizeof(DuLNode));  //�����ռ� 
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
	DuLNode*pCurrent; //��������ָ��
    DuLNode*preNode;
    pCurrent=(*L)->next;
    while(pCurrent!=(*L)){   //��������,Ȼ���ͷ� 
        preNode=pCurrent;
        pCurrent=pCurrent->next;
        free(preNode);
    }
    free(*L);   //����ͷ�ͷ�ڵ� 

}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {	
	if(p==NULL)			//�ж��Ƿ�Ϊ������ 
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
	if(p==NULL)			//�ж��Ƿ�Ϊ������ 
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
	struct DuLNode *pCurrent=p->next;  //������ʱָ��   �����ɾ��ָ��ĺ�һ����ַ 
	pCurrent->prior->next=p->next;     //����ɾ���ڵ��ǰ��ڵ����� 
	pCurrent->next->prior=p->prior;
	*e=pCurrent->data;             		// assign its value to e
	printf("��һ���ڵ��������:%d",*e);
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
		while(pCurrent->next!=preNode) {//����Ϊż��ʱ����
			if(pCurrent==preNode){     //����Ϊ����ʱ����
				printf("%d\n",pCurrent->data);
				break;                 //������ζ��˫��������,�˳�ѭ��
			}
		printf("%d\n",pCurrent->data);
		printf("%d\n",preNode->data);
		
		pCurrent=pCurrent->next;
		preNode=preNode->prior;
		}
	}

}

//���� ������ݵĺ��� 
void printf_data (int a)	{
	printf("��ǰ�ڵ��������%d",a);
}
//���庯��ָ�� 
void (*visit)(int a)=printf_data;

