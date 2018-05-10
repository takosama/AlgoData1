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
int main(void)
{
	Cell* node = malloc(sizeof(Cell));
	Cell* pNode = NULL;
	//\‘¢‘Ì‚Ì’†g‚ðÝ’è
	node->data = 10;
	node->next = NULL;

	//\‘¢‘Ì‚Ì•\Ž¦
	printf("node.data:%d,\tnode.next:%p\n", node->data, node->next);
	printf("*p:%p\n", pNode);

	//\‘¢‘Ìƒ|ƒCƒ“ƒ^‚Ö‚Ì‘ã“ü
	pNode = node;
	cnt++;
	ViewListAll(pNode);

	//Œã•û‚É‘}“ü
	insert_cell(pNode, 20);
	ViewListAll(pNode);

	insert_cell(pNode, 30);
	ViewListAll(pNode);


	insert_cell(pNode->next, 40);
	ViewListAll(pNode);
	//í“¬‚É‘}“ü
	insert_top(&pNode, 50);
	ViewListAll(pNode);

	//íœ
	delete(pNode);
	ViewListAll(pNode);

	delete(pNode->next);
	ViewListAll(pNode);

	delete_top(&pNode);
	ViewListAll(pNode);

	delete_top(&pNode);
	ViewListAll(pNode);

	delete_top(&pNode);
	ViewListAll(pNode);

	delete(pNode);
	ViewListAll(pNode);

	//Œã•û‚É‘}“ü
	insert_top(&pNode, 20);
	ViewListAll(pNode);

	insert_top(&pNode, 25);
	ViewListAll(pNode);


	delete(pNode->next);
	ViewListAll(pNode);

	delete(pNode);
	ViewListAll(pNode);

	delete(pNode);
	ViewListAll(pNode);

	delete(pNode);
	ViewListAll(pNode);

	//Œã•û‚É‘}“ü
	insert_top(&pNode, 20);
	ViewListAll(pNode);

	insert_top(&pNode, 25);
	ViewListAll(pNode);

	//Œã•û‚É‘}“ü
	insert_top(&pNode, 30);
	ViewListAll(pNode);

	insert_top(&pNode, 35);
	ViewListAll(pNode);

	DeleteListAll(&pNode);
	DeleteListAll(&pNode);

}
void DeleteListAll(Cell** Top)
{
	int tcnt = cnt;
	for (int i = 0; i<tcnt; i++)
	{
		delete((*Top));
		ViewListAll(*Top);

	}
	delete_top(Top);
	ViewListAll(*Top);

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
	if (cnt <= 0)
		return;
	if (Top == NULL)
		return;
	if (*Top == NULL)
		return;
	if ((*Top)->next == NULL)
	{
		free(*Top);
		cnt--;
		//(*Top)->data = NULL;
		//(*Top)->next = NULL;
		return;
	}
	else
	{
		Cell* pTop = (*Top)->next;
		free(*Top);
		(*Top) = pTop;
		cnt--;
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