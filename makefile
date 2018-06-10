all: testlist

testlist: testlist.o linkedlist.o
	gcc -g $^ -o $@ -lm

.c.o: 
	gcc -g -Wall -pedantic -std=c99 -c -D_REENTRANT $<

linkedlist.o: linkedlist.c linkedlist.h

testlist.o: testlist.c linkedlist.h

clean:
	-rm testlist.o linkedlist.o testlist