CC=cc

all: linked stack stack_overflow

linked: linked.c
	$(CC) -g -ansi -std=gnu99 -Wall linked.c -o linked
stack: stack.c
	$(CC) -g -ansi -std=gnu99 -Wall stack.c -o stack
stack_overflow: stack_overflow.c
	$(CC) -g -ansi -std=gnu99 -Wall stack_overflow.c -o stack_overflow
clean:
	rm -vrf stack linked stack_overflow
