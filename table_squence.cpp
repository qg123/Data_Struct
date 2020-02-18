#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define  MAXSIZE 256
#define  ERROR	 -1	
typedef int ElenmentType;
typedef int Position;
typedef struct LNode *List;

struct LNode {
	ElenmentType Data[MAXSIZE];
	Position Last;
};

List MakeEmpty_Squence();
Position Find_Squence(List L, ElenmentType X);
bool Insert_Squence(List L, ElenmentType X, Position P);
bool Delete_Squence(List L, Position P);
void Show_Squence(List L);

//����������뺯����������ֲ㣬�����л�˳�������ʽ��
void Find(List L_Find);
void Insert(List L_Insert);
void Delete(List L_Delete);

int main(void)
{
	List ListTest;
	ListTest =  MakeEmpty_Squence();
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
		case 4:Show_Squence(ListTest);	break;
		case 5:StopFlag = 0; break;
		default: {
			printf("�����������������\n");
		}break;
		}
	}

	system("pause");
	
}

List MakeEmpty_Squence()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;

	return L;
}

Position Find_Squence(List L, ElenmentType X)
{
	Position i = 0;
	while (i <= L->Last && L->Data[i] != X) {
		i++;
	}
	if (i > L->Last) return ERROR;
	else			 return i;
}

bool Insert_Squence(List L, ElenmentType X, Position P)
{
	Position i;
	if (L->Last == MAXSIZE - 1) {
		printf("����\n");
		return false;
	}
	if (P<0 || P>(L->Last + 1)) {
		printf("λ�ò��Ϸ�\n");
		return false;
	}
	for (i = L->Last; i >= P; i--) {
		L->Data[i + 1] = L->Data[i];
	}
	L->Data[P] = X;
	L->Last++;
	return true;
}

bool Delete_Squence(List L, Position P)
{
	Position i;
	if (P < 0 || P>L->Last) {
		printf("λ��%d������Ԫ��\n", P);
		return false;
	}
	for (i = P + 1; i <= L->Last; i++) {
		L->Data[i - 1] = L->Data[i];
	}
	L->Last--;
	return true;
}

void Show_Squence(List L)
{
	Position i;
	if (L->Last == -1) {
		printf("This table is empty.\n");
	}
	else {
		for (i = 0; i <= L->Last; i++) {
			printf("%d ", L->Data[i]);
		}
	}
	printf("\n");
}

void Find(List L_Find)
{
	ElenmentType NumToFind;
	Position PosFinded;
	printf("������Ҫ���ҵ�Ԫ�أ�\n");
	scanf("%d", &NumToFind);
	PosFinded = Find_Squence(L_Find, NumToFind);
	if (PosFinded != ERROR) {
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
	Insert_Squence(L_Insert, NumToInsert, PosToInsert);
}
void Delete(List L_Delete)
{
	ElenmentType PosToDelete;
	printf("������Ҫɾ����Ԫ��λ�ã�\n");
	scanf("%d", &PosToDelete);
	Delete_Squence(L_Delete, PosToDelete);
}








