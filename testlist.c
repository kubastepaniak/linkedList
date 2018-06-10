#include <stdio.h>
#include "linkedlist.h"

int main(int argc, char const *argv[])
{
	llnode *list;
	list = init();
	append(list, "first");
	append(list, "second");
	append(list, "third");
	push(&list, "pushed");
	display(list);

	printf("\npopped: %s\n", pop(list));
	display(list);
	printf("%d\n", length(list));

	printf("\n");
	llnode *copied = copy(list);
	display(copied);

	printf("\n");
	reverse(&copied);
	display(copied);

	printf("\n");
	sort(copied);
	display(copied);

	return 0;
}