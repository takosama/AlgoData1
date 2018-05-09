#include <stdio.h>
#include <stdlib.h>
typedef struct Cell
{
	int data;
	struct  Cell* next;
} Cell;
void insert_top(Cell** pTop, int d);
void delete(Cell* p);
void delete_top(Cell** Top);
void ViewList(Cell* Top);
struct Cell* createCell(int data);
void insert_cell(struct Cell* p, int d);
int main(void)
{
	Cell* node = malloc(sizeof(Cell));
	Cell* pNode = NULL;
	//構造体の中身を設定
	node->data = 10;
	node->next = NULL;

	//構造体の表示
	printf("node.data:%d,\tnode.next:%p\n", node->data, node->next);
	printf("*p:%p\n", pNode);

	//構造体ポインタへの代入
	pNode = node;
	ViewList(pNode);

	//後方に挿入
	insert_cell(pNode, 20);
	ViewList(pNode);

	insert_cell(pNode, 30);
	ViewList(pNode);


	insert_cell(pNode->next, 40);
	ViewList(pNode);
	//戦闘に挿入
	insert_top(&pNode, 50);
	ViewList(pNode);

	//削除
	delete(pNode);
	ViewList(pNode);

	free(pNode->next);
	//	delete_topCell(&pNode);
}

void ViewList(Cell* Top)
{
	Cell* top=Top;
	while (1)
	{
		if (top == NULL)
			break;
		printf("%d,", top->data);
		if (top->next == NULL)
			break;
		top = top->next;
	}
	printf("\n");
}



void delete_top(Cell** Top)
{
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
	 {
		 return;
	 } 
	 p->next = p->next->next;
 }


void insert_cell(Cell* p, int d)
{
	Cell* tmp = createCell(d);
	tmp->next = p->next;
	p->next = tmp;
}

void insert_top(Cell** pTop, int d)
{
	Cell* tmp = createCell(d);
	tmp->next = *pTop;
	*pTop =  tmp;
}