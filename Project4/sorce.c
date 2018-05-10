// MIT Lisence
//Created by Takakuwa shuya
#include <stdio.h>
#include <stdlib.h>
typedef struct Cell
{
	int data;
	struct
    Cell* next;
} Cell;
int cnt = 0;
void insert_top(Cell** pTop, int d);
void delete(Cell* p);
void delete_top(Cell** Top);
void ViewListAll(Cell* Top);
void DeleteListAll(Cell** Top);
struct Cell* createCell(int data);
void insert_cell(  Cell* p, int d);
void print_list(Cell *p);

int main(void)
{
	Cell* node = malloc(sizeof(Cell));
	Cell* pNode = NULL;
	//�\���̂̒��g��ݒ�
	node->data = 10;
	node->next = NULL;

	//�\���̂̕\��
	printf("node.data:%d,\tnode.next:%p\n", node->data, node->next);
	printf("*p:%p\n", pNode);


	//�\���̃|�C���^�ւ̑�� 
	pNode = node;
	cnt++;
	ViewListAll(pNode);


	//�|�C���^�𗘗p�����\��
	printf("*p:%p,\t*(p+1):%p\n", pNode, pNode->next);

	/*new_cell��}�����Ă݂悤*/
	/*�����ɍ��*/
	insert_cell(pNode, 20);

	print_list(pNode);

	 

	insert_cell(pNode, 30);
	print_list(pNode);


	insert_cell(pNode->next, 40);
	print_list(pNode);

	//�퓬�ɑ}��
	insert_top(&pNode, 50);
	print_list(pNode);

	//�폜
	delete(pNode);
	print_list(pNode);

	delete(pNode->next);
	print_list(pNode);

	delete_top(&pNode);
	print_list(pNode);

	delete_top(&pNode);
	print_list(pNode);

	delete_top(&pNode);
	print_list(pNode);

	delete(pNode);
	print_list(pNode);

	//����ɑ}��
	insert_top(&pNode, 20);
	print_list(pNode);

	insert_top(&pNode, 25);
	print_list(pNode);


	delete(pNode->next);
	print_list(pNode);

	delete(pNode);
	print_list(pNode);

	delete(pNode);
	print_list(pNode);

	delete(pNode);
	print_list(pNode);

	//����ɑ}��
	insert_top(&pNode, 20);
	print_list(pNode);

	insert_top(&pNode, 25);
	print_list(pNode);

	//����ɑ}��
	insert_top(&pNode, 30);
	print_list(pNode);

	insert_top(&pNode, 35);
	print_list(pNode);

	DeleteListAll(&pNode);
	print_list(pNode);

	DeleteListAll(&pNode);
	print_list(pNode);

}
void DeleteListAll(Cell** Top)
{

	if (*Top == NULL)
		return;
	while (1)
	{
		delete((*Top));
		if ((*Top)->next == NULL)
			break;
			
	}
	
	delete_top(Top);
}

void print_list( Cell *p)
{
	if (p==NULL)
	{
		printf("����ȏ�̓f�[�^������܂���\n");
		return;
	}
	if (p->next == NULL) {
		printf("�A�h���X:%p, \t �f�[�^:%d\n", p, p->data);
		printf("����ȏ�̓f�[�^������܂���\n");
	}
	else {
		printf("�A�h���X:%p,\t �f�[�^:%d\n", p, p->data);
		print_list(p->next);
	}
}

void ViewListAll(Cell* Top)
{
	printf("%4d  :",cnt);
	if (cnt <= 0) 
	{
		printf("\n");
		return;
	}
	Cell* top=Top;
	int i = 1;
	while (i<=cnt)
	{
		if (top == NULL)
			break;
		printf("%d,", top->data);
		i++;
		if (top->next == NULL)
			break;
		top = top->next;
	}
	printf("\n");
}



void delete_top(Cell** Top)
{
	if (Top == NULL)
		return;
	if (*Top == NULL)
		return;
	if ((*Top)->next == NULL)
	{
		free(*Top);
		*Top = NULL;
		return;
	}
	else
	{
		Cell* pTop = (*Top)->next;
		free(*Top);
		(*Top) = pTop;
	}
}


 Cell* createCell(int data)
{
	Cell* pNewCell = (Cell*)malloc(sizeof(Cell));
	pNewCell->data = data;
	pNewCell->next = NULL;
	return pNewCell;
}

 void delete(Cell* p)
 {
	 if (cnt <= 0)
		 return;
	 if (p == NULL)
		 return;
	 if (p->next == NULL)
	 {
		 return;
	 } 
	 Cell* pNextnext = p->next->next;
	 free(p->next);
	 p->next = pNextnext;
	 cnt--;
 }


void insert_cell(Cell* p, int d)
{
	if (cnt <= 0) return;
	Cell* tmp = createCell(d);
	tmp->next = p->next;
	p->next = tmp;
	cnt++;
}

void insert_top(Cell** pTop, int d)
{
	if (cnt == 0)
	{
		Cell* tmp = createCell(d);
		*pTop = tmp;
		cnt++;
		return;
	}
	else if (cnt > 0) {
		Cell* tmp = createCell(d);
		tmp->next = *pTop;
		*pTop = tmp;
		cnt++;
	}
	else
		return;
}