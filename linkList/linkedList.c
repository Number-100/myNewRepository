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
Status InitList(LinkedList *L) {          //����ֻ��һ��ͷ�ڵ�Ŀ�����
	if(!L) //�ж�L�Ƿ����
	return ERROR;
	(*L)=(LinkedList)malloc(sizeof(LNode));//�����ռ�
	(*L)->next=NULL;
	return SUCCESS;
}



void EmptyList(LinkedList *L) {			// �ÿ�����
	if(*L==NULL)
		printf("LΪ������\n");
	//������ʱָ��
	else{
		struct LNode *pCurrent=(*L)->next;
		while(pCurrent){
			//�ȱ����ɾ���ڵ����Ľڵ�
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
void DestroyList(LinkedList *L) {			// ����һ�������ͷ����нڵ�
	if(*L==NULL)
		printf("LΪ������\n");
	//������ʱָ��
	else{
		struct LNode *pCurrent=(*L)->next;
		while(pCurrent){
			//�ȱ����ɾ���ڵ����Ľڵ�
				struct LNode * nextNode=pCurrent->next;
				free(pCurrent);
				pCurrent=nextNode;
		}
		//�ͷ�ͷ�ڵ�
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

	if(p==NULL)   //�ж��Ƿ�Ϊ������
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
	//������ʱָ��
	struct LNode *pCurrent=p;
	p=pCurrent->next;
	//�ȱ����ɾ���ڵ����Ľڵ�
	p=pCurrent->next;
	*e=pCurrent->data;
	printf("��һ���ڵ��������:%d\n",*e);
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
	//�ж��Ƿ�Ϊ������
	if(L==NULL)
		printf("������Ϊ������\n");
	else{
		while (L!=NULL){
			visit(L->data);   //����visit�����������
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
 */      										 //����e�ҵ������еĵ�һ���ڵ�
Status SearchList(LinkedList L, ElemType e) {
		if(L==NULL)
	 	return ERROR;
	struct LNode *pCurrent=L->next;
	// ѭ����ֹ������
	while (pCurrent !=NULL){
		int i=1;
		// �ҵ�Ҫ�ҵĽڵ�
		if(pCurrent->data==e){
			printf("��ǰ�ڵ��λ����%d\n",i);
		printf("%d",pCurrent->data);
		pCurrent=pCurrent->next;
		i++;
		break;
		}
	else
		printf("�����в����ڸ�����\n");
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
	//�ж��Ƿ�Ϊ������
	if(*L==NULL)
		return ERROR;
	preNode=(*L)->next;
	(*L)->next=NULL;
	//����whileѭ���ҵ����һ���ڵ�
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
	//�������ָ��
	struct LNode *slowNode=L->next;
	struct LNode *fastNode=(L->next)->next;
	//�жϵ�����ָ���Ƿ�NULL
	while(slowNode!=NULL && fastNode!=NULL){
		fastNode=(fastNode->next)->next;
		slowNode=slowNode->next;
	//�������ָ������
	if(fastNode==slowNode)
		printf("������ɻ�\n");
	else
		printf("�������ɻ�\n") ;
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
	struct LNode *pCurrent=*L;     //����������ʱָ��,һ�����������ڵ��ַ,һ������ż���ڵ��ַ
	struct LNode *oddNode=(*L)->next;
	struct LNode *evenNode=oddNode->next;
	//ȷ����һ����ڵ�,��һ��ż�ڵ�
	pCurrent=evenNode->next;
	evenNode=oddNode->next;
	while(oddNode&&evenNode){
		//��ż�������
		oddNode=evenNode->next;
		evenNode=oddNode->next;
		//����ż��������
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
		//�������ָ��
		struct LNode *slowNode=(*L)->next;
		struct LNode *fastNode=((*L)->next)->next;
		while(fastNode!=NULL){      //��ָ���ߵı�������������,���������ߵ�ĩβʱ.��ָ������λ�þ����м�ڵ�
			int i=0;
			slowNode=slowNode->next;
			fastNode=(fastNode->next)->next;
			i++;
			//����м�ڵ��λ��
			if(fastNode==NULL){
				printf("��%d���ڵ����м�ڵ�\n",i);
				break;
			}
		}
	}
}


//���� ������ݵĺ���
void printf_data (int a)	{
	printf("��ǰ�ڵ��������%d\n",a);
}
//���庯��ָ��
void (*visit)(int a)=printf_data;

//�������д�������
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

