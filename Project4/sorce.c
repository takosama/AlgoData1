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
	//insert_top(&pNode, 10);

	//�|�C���^�𗘗p�����\��
	printf("*p:%p,\t*(p+1):%p\n", pNode, pNode->next);

	/*new_cell��}�����Ă݂悤*/
	/*�����ɍ��*/
	insert_cell(pNode, 20);
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
	 if (p == NULL)
		 return;
	 if (p->next == NULL)
		 return;
	 Cell* pNextnext = p->next->next;
	 free(p->next);
	 p->next = pNextnext;
 }


void insert_cell(Cell* p, int d)
{
	if (p == NULL)
		return;
	Cell* tmp = createCell(d);
	tmp->next = p->next;
	p->next = tmp;
}

void insert_top(Cell** pTop, int d)
{
	if (pTop == NULL)
	{
		Cell* tmp = createCell(d);
		*pTop = tmp;
		return;
	}
	else {
		Cell* tmp = createCell(d);
		tmp->next = *pTop;
		*pTop = tmp;
	}
}