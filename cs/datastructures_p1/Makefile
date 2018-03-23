CC=cc
CFLAGS=-g -ansi -std=gnu99 -Wall

all: linked stack growingstack linkedstack queue lqueue


# Basic Linked List Datastructure:
linked: linked.c
	$(CC) $(CFLAGS) linked.c -o linked


# Stacks (Arrays and Linkedlists):
stack: stack.c
	$(CC) $(CFLAGS) stack.c -o stack
growingstack: growingstack.c
	$(CC) $(CFLAGS) growingstack.c -o growingstack
linkedstack: linkedstack.c
	$(CC) $(CFLAGS) linkedstack.c -o linkedstack


# Queues:
queue: queue.c
	$(CC) $(CFLAGS) queue.c -o queue
lqueue: lqueue.c
	$(CC) $(CFLAGS) lqueue.c -o lqueue

clean:
	rm -vrf stack linked growingstack linkedstack
	rm -vrf queue lqueue
