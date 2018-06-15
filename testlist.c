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

	printf("\nAFTER POP\npopped: %s\n", pop(list));
	display(list);
	printf("%d\n", length(list));

	printf("\nAFTER COPY\n");
	llnode *copied = copy(list);
	display(copied);

	printf("\nAFTER REVERSE\n");
	reverse(&copied);
	push(&copied, "reversePush");
	display(copied);

	printf("\nAFTER SORTING\n");
	sort(copied);
	display(copied);
	
	printf("\nONE ELEMENT LIST\n");
	llnode *oneelement = init();
	printf("pop on empty: %s\n", pop(oneelement));

	push(&oneelement, "onlyOne");
	printf("pop after push: %s\n", pop(oneelement));
	display(oneelement);

	append(oneelement, "appendOne");
	printf("pop after append: %s\n", pop(oneelement));
	display(oneelement);
	
	destroy(copied);
	destroy(list);
	destroy(oneelement);
	return 0;
}
