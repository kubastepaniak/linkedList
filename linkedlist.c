#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *data;
	struct node* next;
} llnode;

llnode *init();
void display(llnode *list);
void append(llnode *list, char *value);
int length(llnode *list);
void push(llnode **list, char *value);
char *pop(llnode *list);
void destroy(llnode *list);
llnode *copy(llnode *list);
void reverse(llnode **list);

int main(int argc, char const *argv[])
{
	llnode *firstList = init();
	append(firstList, "first");
	append(firstList, "second");
	push(&firstList, "pushed");
	display(firstList);
	printf("%d\n", length(firstList));

	char *new = pop(firstList);
	printf("\npopped: %s\n", new);
	display(firstList);
	printf("%d\n", length(firstList));

	llnode *copied = copy(firstList);
	reverse(&copied);
	printf("\n");
	display(copied);

	destroy(firstList);
	destroy(copied);
	return 0;
}

llnode *init()
{
	llnode *newList;
	newList = malloc(sizeof(llnode));
	newList->data = NULL;
	newList->next = NULL;
	return newList;
}

void display(llnode *list) 
{
	llnode *node = list;
	while(node)
	{
		printf("%s\n", node->data);
		node = node->next;
	}
}

void append(llnode *list, char *value)
{
	llnode *node = list;
	if(!node->data && node->next == NULL)
		node->data = value;
	else
	{
		while(node->next)
			node = node->next;
		node->next = init();
		node->next->data = value;
	}
}

int length(llnode *list)
{
	int len = 0;
	llnode *node = list;
	while(node)
	{
		node = node->next;
		len++;
	}
	return len;
}

void push(llnode **list, char *value)
{
	llnode *head = init();
	head->data = value;
	head->next = *list;
	*list = head;
}

char *pop(llnode *list)
{
	llnode *node = list;
	char *value;
	while(node->next->next)
		node = node->next;

	value = node->next->data;
	free(node->next);
	node->next = NULL;

	return value;
}

void destroy(llnode *list)
{
	llnode *node;
	while(list)
	{
		node = list->next;
		free(list);
		list = node;
	}
}

llnode *copy(llnode *list)
{
	llnode *copyHead;
	llnode **copy = &copyHead;
	while(list)
	{
		*copy = init();
		(*copy)->next = list->next;
		(*copy)->data = list->data;
		list = list->next;
		copy = &((*copy)->next);
	}
	return copyHead;
}

void reverse(llnode** list)
{
	llnode *previousNode, *currentNode, *nextNode;
	previousNode = (llnode*)NULL;
	currentNode = *list;
	nextNode = (llnode*)NULL;
	while(currentNode)
	{
		nextNode = currentNode->next;
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
	}
	*list = previousNode;
}