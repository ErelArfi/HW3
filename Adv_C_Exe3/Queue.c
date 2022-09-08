#include "Queue.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	free(q->head);
	free(q->tail);
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* new = createIntNode(data);
	
	if (q->head == NULL)
	{
		q->head = new;
		q->tail = q->head;
	}
	else
	{
		q->tail->next = new;
		q->tail = new;
	}
}

unsigned int dequeue(Queue* q)
{
	unsigned int x = q->head->data;
	intNode* temp = q->head;
	q->head = q->head->next;

	if (!q->head)
		q->tail = NULL;

	free(temp);
	return x;
}

int isEmptyQueue(const Queue* q)
{
	return (!(q->head));
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	if (isEmptyQueue(q))
		return;

	Queue temp;
	initQueue(&temp);

	while (q->head->next)
		enqueue(&temp, dequeue(q));

	while(!isEmptyQueue(&temp))
		enqueue(q, dequeue(&temp));
}

void cutAndReplace(Queue* q)
{
	int length = queueLen(q);
	if (length % 2) 
		addAvgNum(q, length);

	Queue temp;
	initQueue(&temp);

	for (int i = 0; i < ((length+1) / 2); i++)
		enqueue(&temp, dequeue(q));

	flipQueue(q);

	for (int i = 0; i < ((length+1) / 2); i++)
		enqueue(q, dequeue(&temp));
}

void sortKidsFirst(Queue* q)
{
	Queue help;
	Queue temp;
	initQueue(&help);
	initQueue(&temp);

	while (q->head) {
		intNode* smallest = checkForSmallest(q);

			while (q->head != smallest) 
				enqueue(&help, dequeue(q));

		enqueue(&temp, dequeue(q));

			while(help.head)
				enqueue(q, dequeue(&help));
	}
	while(temp.head)
		enqueue(q, dequeue(&temp));
}


intNode* createIntNode(int data)
{
	intNode* new = calloc(1,sizeof(intNode));
	if (!new) {
		printf("Allocation Failed!");
		exit(1);
	}
	new->data = data;
	return new;
}

int queueLen(Queue* q)
{
	intNode* temp = q->head;
	int count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	free(temp);
	return count;
}

void addAvgNum(Queue* q, int length)
{
	int sum = 0, avg;
	intNode* temp = q->head;

	for (int i = 0; i < length; i++) {
		sum += temp->data;
		temp = temp->next;
	}

	avg = sum / length;
	enqueue(q, avg);
}

void flipQueue(Queue* q)
{
	Stack temp;
	initStack(&temp);
	while (!isEmptyQueue(q))
		push(&temp, dequeue(q));
	while (!isEmptyStack(&temp))
		enqueue(q, pop(&temp));
}

intNode* checkForSmallest(Queue* q)
{
	intNode* smallest = q->head;
	intNode* temp = q->head->next;
	while (temp) {
		if (smallest->data > temp->data) {
			smallest = temp;
		}
		temp = temp->next;
	}
	return smallest;
}


void printQueue(Queue* q) {
	intNode* temp = q->head;
	printf("\n");
	while (temp) {
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
	free(temp);
}