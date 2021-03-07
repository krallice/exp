CC=cc
CFLAGS=-g -ansi -std=gnu99 -Wall

BINS=hashchain hashchain2 binary_search_tree
all: $(BINS)

hashchain: %:%.c 
	$(CC) $(CFLAGS) $^ -o $@
hashchain2: %:%.c
	$(CC) $(CFLAGS) $^ -o $@

binary_search_tree: %:%.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	@- $(RM) $(BINS)
