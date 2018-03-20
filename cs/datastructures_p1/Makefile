CC=cc

all: linked stack growingstack linkedstack

linked: linked.c
	$(CC) -g -ansi -std=gnu99 -Wall linked.c -o linked
stack: stack.c
	$(CC) -g -ansi -std=gnu99 -Wall stack.c -o stack
growingstack: growingstack.c
	$(CC) -g -ansi -std=gnu99 -Wall growingstack.c -o growingstack

linkedstack: linkedstack.c
	$(CC) -g -ansi -std=gnu99 -Wall linkedstack.c -o linkedstack
clean:
	rm -vrf stack linked growingstack linkedstack
