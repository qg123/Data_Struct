#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ERROR NULL

typedef int ElenmentType;
typedef struct LNode *PtrToLNode;

struct LNode{
	ElenmentType Data;
	PtrToLNode Next;
};
typedef int Position;
typedef PtrToLNode List;

List CreateNewList(void);
int Find_List(List L, ElenmentType X);
void Insert_List(List L, ElenmentType X, ElenmentType P);
void Delete_List(List L, ElenmentType P);
void Print_List(List L);
//将链表操作与函数具体操作分层，便于切换顺序表与链式表
void Find(List L_Find);
void Insert(List L_Insert);
void Delete(List L_Delete);

int main(void)
{
	List ListTest;
	ListTest = CreateNewList();
	int Operate = 0;
	char StopFlag = 1;
	Position Pos = 0;
	printf("请选择操作\n");
	while (StopFlag) {
		printf("*****1--插入元素*****\n");
		printf("*****2--查找元素*****\n");
		printf("*****3--删除元素*****\n");
		printf("*****4--打印元素*****\n");
		printf("*****5--结束程序*****\n");
		scanf("%d", &Operate);
		system("cls");
		switch (Operate) {
		case 1:Insert(ListTest); break;
		case 2:Find(ListTest);	 break;
		case 3:Delete(ListTest); break;
		case 4:Print_List(ListTest);	break;
		case 5:StopFlag = 0; break;
		default: {
			printf("输入错误，请重新输入\n");
		}break;
		}
	}

	system("pause");

}

List CreateNewList(void)
{
	List Head;
	Head = (List)malloc(sizeof(struct LNode));
	printf("正在创建新链表，请输入表头元素：\n");
	scanf("%d", &Head->Data);
	Head->Next = NULL;
	printf("链表创建完成！");
	return Head;
}

int Find_List(List L, ElenmentType X)//查找元素
{
	List p = L;
	int pos = 0;
	while (p && p->Data != X) {
		p = p->Next;
		pos++;
	}
	if (p)
		return pos;
	else {
		return -1;
	}
		
}

void Insert_List(List L, ElenmentType X, ElenmentType P)
{
	List tmp, pre;
	tmp = L;
	pre = (List)malloc(sizeof(struct LNode));
	pre->Data = X;
	for (int i = 0; i < P && tmp != NULL; i++) {
		tmp = tmp->Next;
	}
	if (tmp != NULL) {
		pre->Next = tmp->Next;
		tmp->Next = pre;
	}
	else {
		printf("节点不存在，链表越界\n");
	}
}

void Delete_List(List L, ElenmentType P)
{
	List tmp = L, pre = L;
	for (int i = 0; i < P&&tmp != NULL; i++) {
		pre = tmp;
		tmp = tmp->Next;
	}
	if (tmp != NULL) {
		pre->Next = tmp->Next;
		free(tmp);
	}
	else {
		printf("节点不存在\n");
	}
}

void Print_List(List L)
{
	List tmp = L;
	while (tmp) {
		printf("%d ", tmp->Data);
		tmp = tmp->Next;
	}
	printf("\n");
}

void Find(List L_Find)
{
	ElenmentType NumToFind;
	Position PosFinded;
	printf("请输入要查找的元素：\n");
	scanf("%d", &NumToFind);
	PosFinded = Find_List(L_Find, NumToFind);
	if (PosFinded != -1) {
		printf("元素%d是第%d个元素\n", NumToFind, PosFinded + 1);
	}
	else {
		printf("未找到该元素\n");
	}
}
void Insert(List L_Insert)
{
	ElenmentType NumToInsert;
	Position PosToInsert;
	printf("请输入插入位置：\n");
	scanf("%d", &PosToInsert);
	printf("请输入插入的元素：\n");
	scanf("%d", &NumToInsert);
	Insert_List(L_Insert, NumToInsert, PosToInsert);
}
void Delete(List L_Delete)
{
	ElenmentType PosToDelete;
	printf("请输入要删除的元素位置：\n");
	scanf("%d", &PosToDelete);
	Delete_List(L_Delete, PosToDelete);
}