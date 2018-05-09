#include <stdio.h>
#include <stdlib.h>
typedef struct Cell
{
	int data;
	struct  Cell* next;
} Cell;
void insert_top(Cell** pTop, int d);

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

	insert_cell(pNode, 20);
	insert_top(pNode, 30);

	free(pNode->next);
//	delete_topCell(&pNode);
}




 Cell* createCell(int data)
{
	Cell* pNewCell = (Cell*)malloc(sizeof(Cell));
	pNewCell->data = data;
	pNewCell->next = NULL;
	return pNewCell;
};

void insert_cell(Cell* p, int d)
{
	Cell* tmp = createCell(d);
	p->next = tmp;
};

void insert_top(Cell** pTop, int d)
{
	Cell* tmp = createCell(d);
	tmp->next = (*pTop)->next;
	pTop = &tmp;
}