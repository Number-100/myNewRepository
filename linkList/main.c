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
	printf("1,��������\n") ;
	printf("2,�ÿ�����\n") ;
	printf("3,���ٲ���\n") ;
	printf("4,�������\n") ;
	printf("5,ɾ������\n") ;
	printf("6,��������\n") ;
	printf("7,��ѯ�������Ƿ����ĳ��\n") ;
	printf("8,��ת����\n") ;
	printf("9,�ж������Ƿ�ɻ�\n") ;
	printf("10,��ż����\n") ;
	printf("11,�ҵ��м�ڵ�\n") ;
	printf("0,�˳�����\n") ;
	printf("���������ѡ��:\n");

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
		printf("LNode *one���ÿ�\n");
	}
	else(number==3){
		void DestroyList(LNode **one);
		if(one==NULL)
			printf("����������\n");
		else
			printf("����δ����\n");
	}
	else(number==4){
		Status InsertList(LNode *one, LNode *two);
		while (one){
			printf("%d",one->data);
			one=one->next;
		}
		printf("�������\n");
	}
	else(number==5){
		Status DeleteList(LNode *one, ElemType *e);
	}
	else(number==6){
		void TraverseList(LNode *one, void (*visit)(ElemType e));
	}
	else(number==7){
		int e =0;
		printf("������һ������:\n");
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
		printf("�˳��ɹ�\n");
	}
	printf("���β�������\n");
	return 0;


}



