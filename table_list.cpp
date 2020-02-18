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
//����������뺯����������ֲ㣬�����л�˳�������ʽ��
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
	printf("��ѡ�����\n");
	while (StopFlag) {
		printf("*****1--����Ԫ��*****\n");
		printf("*****2--����Ԫ��*****\n");
		printf("*****3--ɾ��Ԫ��*****\n");
		printf("*****4--��ӡԪ��*****\n");
		printf("*****5--��������*****\n");
		scanf("%d", &Operate);
		system("cls");
		switch (Operate) {
		case 1:Insert(ListTest); break;
		case 2:Find(ListTest);	 break;
		case 3:Delete(ListTest); break;
		case 4:Print_List(ListTest);	break;
		case 5:StopFlag = 0; break;
		default: {
			printf("�����������������\n");
		}break;
		}
	}

	system("pause");

}

List CreateNewList(void)
{
	List Head;
	Head = (List)malloc(sizeof(struct LNode));
	printf("���ڴ����������������ͷԪ�أ�\n");
	scanf("%d", &Head->Data);
	Head->Next = NULL;
	printf("��������ɣ�");
	return Head;
}

int Find_List(List L, ElenmentType X)//����Ԫ��
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
		printf("�ڵ㲻���ڣ�����Խ��\n");
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
		printf("�ڵ㲻����\n");
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
	printf("������Ҫ���ҵ�Ԫ�أ�\n");
	scanf("%d", &NumToFind);
	PosFinded = Find_List(L_Find, NumToFind);
	if (PosFinded != -1) {
		printf("Ԫ��%d�ǵ�%d��Ԫ��\n", NumToFind, PosFinded + 1);
	}
	else {
		printf("δ�ҵ���Ԫ��\n");
	}
}
void Insert(List L_Insert)
{
	ElenmentType NumToInsert;
	Position PosToInsert;
	printf("���������λ�ã�\n");
	scanf("%d", &PosToInsert);
	printf("����������Ԫ�أ�\n");
	scanf("%d", &NumToInsert);
	Insert_List(L_Insert, NumToInsert, PosToInsert);
}
void Delete(List L_Delete)
{
	ElenmentType PosToDelete;
	printf("������Ҫɾ����Ԫ��λ�ã�\n");
	scanf("%d", &PosToDelete);
	Delete_List(L_Delete, PosToDelete);
}