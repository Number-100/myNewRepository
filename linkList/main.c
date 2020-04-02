//#include "../head/linkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"

struct LNode *one ;
struct LNode *two;
void func1(LNode *one);
void func2(LNode *two);


int main(){
	int number;
	printf("1,创建链表\n") ;
	printf("2,置空链表\n") ;
	printf("3,销毁操作\n") ;
	printf("4,插入操作\n") ;
	printf("5,删除操作\n") ;
	printf("6,遍历链表\n") ;
	printf("7,查询链表中是否存在某数\n") ;
	printf("8,反转链表\n") ;
	printf("9,判断链表是否成环\n") ;
	printf("10,奇偶逆序\n") ;
	printf("11,找到中间节点\n") ;
	printf("0,退出操作\n") ;
	printf("请输入你的选择:\n");

	scanf("%d",&number);
	if(number==1){
		Status InitList(LinkedList *L);
	}
	else(number==2){
		void EmptyList(LNode *one);
		while (one){
			printf("%d",one->data);
			one=one->next;
		}
		printf("LNode *one已置空\n");
	}
	else(number==3){
		void DestroyList(LNode **one);
		if(one==NULL)
			printf("链表已销毁\n");
		else
			printf("链表未销毁\n");
	}
	else(number==4){
		Status InsertList(LNode *one, LNode *two);
		while (one){
			printf("%d",one->data);
			one=one->next;
		}
		printf("插入完成\n");
	}
	else(number==5){
		Status DeleteList(LNode *one, ElemType *e);
	}
	else(number==6){
		void TraverseList(LNode *one, void (*visit)(ElemType e));
	}
	else(number==7){
		int e =0;
		printf("请输入一个整数:\n");
		scanf("%d",&e);
		Status SearchList(LNode *one, ElemType e);
	}
	else(number==8){
		Status ReverseList(LNode **one);
		while (!one){
			printf("%d",one->data);
			one=one->next;
		}
	}
	else(number==9){
		Status IsLoopList(LNode *one);
	}
	else(number==10){
		LNode* ReverseEvenList(LNode **one);
		while (!one){
			printf("%d",one->data);
			one=one->next;
		}
	}
	else(number=11){
		LNode* FindMidNode(LNode **one) ;
	}
	else if(number==0){
		printf("退出成功\n");
	}
	printf("本次操作结束\n");
	return 0;


}



