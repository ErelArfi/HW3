#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;

}

void destroyStack(Stack* s)
{
	free(s->head);
}

void push(Stack* s, char data)
{
	charNode* new = createCharNode(data);
	s->head = addToHead(s->head, new);
}


charNode* createCharNode(char data)
{
	charNode* new = malloc(sizeof(charNode));
	if (!new){
		printf("Allocation Failed!");
		exit(1);
	}
	new->data = data;
	return new;
}


char pop(Stack* s)
{
		char x = s->head->data;
		s->head = s->head->next;
		return x;
}


int isEmptyStack(const Stack* s)
{
	return (!(s->head));
}

charNode* addToHead(charNode* head, charNode* toAdd) {
	toAdd->next = head;
	head = toAdd;
	return head;
}


/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	if (!sentence)
		return;

	Stack s;
	initStack(&s);
	int length = strlen(sentence);

	for (int i = 0; i < length; i++) {

		char x = sentence[i];

		if (x != '#')
			printf("%c", x);

		else
		{
			do{
				i++;
				x = sentence[i];
				if (x == '#')
					continue;
				push(&s, x);
			} while (x != '#');

			while(!isEmptyStack(&s))
			printf("%c", pop(&s));
		}
	}
	printf("\n");

}

int isPalindrome(Stack* s)
{
	Stack compare, test;
	initStack(&compare);
	initStack(&test);
	Stack temp = *s;
	int counter = 0;

	while (!isEmptyStack(&temp)) {
		push(&compare, pop(&temp));
		counter++;
		temp.head = temp.head->next;
	}
	
	for (int i = 0; i < counter / 2; i++) {
		push(&test, pop(&compare));
	}

	if (counter % 2 != 0)
		pop(&compare);

	while (!isEmptyStack(&compare)) {
		char x = compare.head->data;
		char y = test.head->data;
		if (x != y)
			return 0;
		compare.head = compare.head->next;
		test.head = test.head->next;
	}
	return 1;
}

void rotateStack(Stack* s, int n)
{
	if (n < 0)
		return;
	Stack first,sec;
	initStack(&first);
	initStack(&sec);
	Stack temp = *s;
	int count = 0;

	while (temp.head != NULL) {
		count++;
		temp.head = temp.head->next;
	}
	
	if (n > count)
		return;

	for (int i = 0; i < (count - n); i++) {
		push(&first, pop(s));
	}

	for (int i = 0; i < n; i++) {
		push(&sec, pop(s));
	}

	for (int i = 0; i < (count - n); i++) {
		push(s, pop(&first));
	}

	for (int i = 0; i < n; i++) {
		push(s, pop(&sec));
	}

}


void printStack(Stack* s) {
	Stack temp = *s;
	printf("\n");
	while (temp.head != NULL) {
		printf("%c->", temp.head->data);
		temp.head = temp.head->next;
	}
	printf("NULL\n");
}