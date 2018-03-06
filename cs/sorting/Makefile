CC=cc

.PHONY: all insertion merge quick

all: insertion merge quick

insertion:
	$(CC) -g -ansi -std=gnu99 -Wall insertion.c -o insertion

merge:
	$(CC) -g -ansi -std=gnu99 -Wall merge.c -o merge

quick:
	$(CC) -g -ansi -std=gnu99 -Wall quick.c -o quick

clean:
	rm -rf insertion merge
