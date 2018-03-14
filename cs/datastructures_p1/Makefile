CC=cc

all: linked stack growingstack

linked: linked.c
	$(CC) -g -ansi -std=gnu99 -Wall linked.c -o linked
stack: stack.c
	$(CC) -g -ansi -std=gnu99 -Wall stack.c -o stack
growingstack: growingstack.c
	$(CC) -g -ansi -std=gnu99 -Wall growingstack.c -o growingstack
clean:
	rm -vrf stack linked growingstack
