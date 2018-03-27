CC=cc
CFLAGS=-g -ansi -std=gnu99 -Wall

BINS=linked stack growingstack linkedstack queue lqueue
all: $(BINS)

# Basic Linked List Datastructure:
linked:	%:%.c
	$(CC) $(CFLAGS) $^ -o $@

# Stacks (Arrays and Linkedlists):
stack: %:%.c
	$(CC) $(CFLAGS) $^ -o $@
growingstack: %:%.c
	$(CC) $(CFLAGS) $^ -o $@
linkedstack: %:%.c
	$(CC) $(CFLAGS) $^ -o $@

# Queues:
queue: %:%.c
	$(CC) $(CFLAGS) $^ -o $@
lqueue: %:%.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY : clean
clean:
	@- $(RM) $(BINS)
