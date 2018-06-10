#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

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

void reverse(llnode **list)
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

void sort(llnode *list)
{
	llnode *node;
	int size = length(list);

	for(int i = 0; i < size - 1; i++)
	{
		node = list;
		while(node->next)
		{
			if(strcmp(node->data, node->next->data) > 0)
			{
				char *swap;
				swap = node->data;
				node->data = node->next->data;
				node->next->data = swap;
			}
			node = node->next;
		}
	}
}