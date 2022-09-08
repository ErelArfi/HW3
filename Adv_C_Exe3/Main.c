#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
	//////////// Part A - Stack ///////////
	printf("\n\n\tPart A - Stack\n\n");

	char str[] = "Im che#kc#ing now";
	flipBetweenHashes(str);
	
	Stack stack;
	initStack(&stack);
	push(&stack, 'a');
	push(&stack, 'b');
	push(&stack, 'c');
	push(&stack, 'd');
	push(&stack, 'e');
	push(&stack, 'f');
	if (isPalindrome(&stack))
		printf("Palindrom!\n");
	else
		printf("Not a Palindrom\n");

	printStack(&stack);
	rotateStack(&stack, 4);
	printStack(&stack);

	//////////// Part B - Queue ///////////
	printf("\n\n\tPart B - Queue\n\n");

	Queue queue;
	initQueue(&queue);
	enqueue(&queue, 5);
	enqueue(&queue, 4);
	enqueue(&queue, 3);
	enqueue(&queue, 2);
	enqueue(&queue, 1);
	enqueue(&queue, 0);
	printQueue(&queue);
	rotateQueue(&queue);
	printQueue(&queue);
	cutAndReplace(&queue);
	printQueue(&queue);
	sortKidsFirst(&queue);
	printQueue(&queue);
}