#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *data;
	struct node* next;
} llnode;

llnode* init();

int main(int argc, char const *argv[])
{
	llnode *firstList = init();
	printf("%s\n", firstList->data);
	return 0;
}

llnode* init()
{
	llnode *newList;
	newList = malloc(sizeof(llnode));
	newList->data = "\0";
	newList->next = NULL;
	return newList;
}