#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node
{
	char *data;
	struct node* next;
} llnode;

llnode *init();
void display(llnode *list);
void append(llnode *list, char *value);
int length(llnode *list);
int ifEmpty(llnode *list);
void push(llnode **list, char *value);
char *pop(llnode *list);
void destroy(llnode *list);
llnode *copy(llnode *list);
void reverse(llnode **list);
void sort(llnode *list);

#endif
