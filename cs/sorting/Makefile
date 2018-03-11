CC=cc

.PHONY: all insertion merge quick counting

all: insertion merge quick counting

insertion:
	$(CC) -g -ansi -std=gnu99 -Wall insertion.c -o insertion

merge:
	$(CC) -g -ansi -std=gnu99 -Wall merge.c -o merge

quick:
	$(CC) -g -ansi -std=gnu99 -Wall quick.c -o quick

counting:
	$(CC) -g -ansi -std=gnu99 -Wall counting.c -o counting

clean:
	rm -rf insertion merge quick counting
