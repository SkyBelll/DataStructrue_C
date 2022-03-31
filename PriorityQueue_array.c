#include<stdio.h>
#define MAX 200

typedef struct MaxPriorityQueue {
	 int elem[MAX];
int size;
}MaxPriorityQueue;

void error(char* msg)
{
	printf("%s\n", msg);
	return -1;
}
void init(MaxPriorityQueue* pq)
{
	pq->size = 0;
}
int IsEmpty(MaxPriorityQueue* pq)
{
	return pq->size == 0;
}
int IsFull(MaxPriorityQueue* pq)
{
	return pq->size == MAX - 1;
}
void insertMaxPQ(MaxPriorityQueue* pq, int val)
{
	if (IsFull(pq))
	{
		error("Å¥°¡ ²ËÂü!");
	}
	pq->elem[pq->size++] = val;
}

int removeMaxPQ(MaxPriorityQueue* pq)
{
	if (IsEmpty(pq))
	{
		error("Å¥°¡ ºö!");
	}
	int max = pq->elem[0];
	int maxid;
	for (int i = 1; i < pq->size; i++)
	{
		if (pq->elem[i] > max)
		{
			max = pq->elem[i];
			maxid = i;
		}

	}
	pq->size--;
	for (int i = maxid; i < pq->size; i++)
	{
		pq->elem[i] = pq->elem[i + 1];
	}
	return max;
}

int findMaxPQ(MaxPriorityQueue* pq)
{
	if (IsEmpty(pq))
	{
		error("Å¥°¡ ºö!");
	}
	int max = pq->elem[0];
	for (int i=0; i < pq->size; i++)
	{
		if (pq->elem[i] > max)
			max = pq->elem[i];
	}
	return max;
}

void displayMaxPQ(MaxPriorityQueue* pq)
{
	if (IsEmpty(pq))
	{
		error("Å¥°¡ ºö!");
	}
	for (int i = 0; i < pq->size; i++)
		printf("ÀÎµ¦½º%d : %d \n", i, pq->elem[i]);
}

int main()
{
	MaxPriorityQueue que;
	init(&que);
	insertMaxPQ(&que, 40);
	insertMaxPQ(&que, 18);
	insertMaxPQ(&que, 22);
	insertMaxPQ(&que, 70);
	insertMaxPQ(&que, 35);
	insertMaxPQ(&que, 4);
	displayMaxPQ(&que);
	printf("»èÁ¦¿¬»êÀ» ±¸ÇöÇÕ´Ï´Ù\n");
	removeMaxPQ(&que);
	findMaxPQ(&que);
	displayMaxPQ(&que);
	return 0;
}