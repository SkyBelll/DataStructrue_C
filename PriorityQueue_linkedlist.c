#include<stdio.h>
#include<stdlib.h>
typedef struct List 
{
	int data;
	struct List* link;
}List;

int size;
List* head;

typedef List MinPriorityQueue;


void Init(MinPriorityQueue* pq) 
{
	size = 0;
	head = NULL;
}
int IsEmpty(MinPriorityQueue* pq) 
{
	return head == NULL;
}
void InsertMinPQ(MinPriorityQueue* pq, int val)
{
	
	List* newnode = (List*)malloc(sizeof(List));
	List* cur = head;
	List* before = head;
	List* pmaxnode = NULL;
	List* maxnode = NULL;
	
	newnode->data = val;
	
	if (head ==NULL)
	{
		
		newnode->link = NULL;
		
		head = newnode;
		size++;
	}
	else
	{
		cur = cur->link;
		if (cur == NULL)
		{
			newnode->link = NULL;
			head->link = newnode;
			size++;
		}
		else {
			while (cur != NULL)
			{
				if (val < &cur->data)
				{
					break;
				}

				cur = cur->link;
				before = before->link;

			}

			
				
				newnode->link = before->link;
				before->link = newnode;
			
			size++;

		}
	}
}

int removeMinPQ(MinPriorityQueue* pq)
{
	List* before=head;
	List* cur = head;
	cur = cur->link;
	int va;
	while (cur->link== NULL)
	{
		cur = cur->link;
		before = before->link;
	}
	va = cur->data;
	before->link = NULL;
	free(cur);
	size--;
	return va;
}

int findMinPQ(MinPriorityQueue* pq)
{
	List* before = head;
	List* cur = head;
	cur = cur->link;
	int va;
	while (cur->link == NULL)
	{
		cur = cur->link;
		before = before->link;
	}
	va = cur->data;
	return va;
}

void displayMinPQ(MinPriorityQueue* pq)
{
	
	int i;
	List* p = head;
	for (i = 0; i < size; i++)
	{
		printf("%d\n", p->data);
		p = p->link;
	}
	printf("\n");
}

int main() 
{
	MinPriorityQueue que;

	Init(&que);
	
	InsertMinPQ(&que, 30);
	
	InsertMinPQ(&que, 60);
	InsertMinPQ(&que, 77);
	

	InsertMinPQ(&que, 50);
	InsertMinPQ(&que, 10);
	;
	InsertMinPQ(&que, 40);
	displayMinPQ(&que);
	removeMinPQ(&que);
	displayMinPQ(&que);
	findMinPQ(&que);
		return 0;
}