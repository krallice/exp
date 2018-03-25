CC=cc
CFLAGS=-g -ansi -std=gnu99 -Wall

all: hashchain

hashchain: hashchain.c hashchain2.c
	$(CC) $(CFLAGS) hashchain.c -o hashchain
	$(CC) $(CFLAGS) hashchain2.c -o hashchain2
clean:
	rm -vrf hashchain hashchain2
