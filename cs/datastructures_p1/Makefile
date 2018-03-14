CC=cc

.PHONY: all linked stack

all: linked stack

linked:
	$(CC) -g -ansi -std=gnu99 -Wall linked.c -o linked
stack:
	$(CC) -g -ansi -std=gnu99 -Wall stack.c -o stack
clean:
	rm -vrf stack linked
