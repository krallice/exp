#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 8

typedef struct cbuffer {
	int readindex;
	int writeindex;
	int data[BUFFERSIZE];
} cbuffer;

cbuffer *create_cbuffer(void) {
	// Init and zeroise:
	cbuffer *cb = (cbuffer*)malloc(sizeof(cbuffer));
	memset(cb, 0, sizeof(cbuffer));
	return cb;
}

void write_buffer(cbuffer *cbuf, int value) {
	cbuf->data[cbuf->writeindex] = value;
	cbuf->writeindex++;
	cbuf->writeindex = cbuf->writeindex % BUFFERSIZE;
}

int read_buffer(cbuffer *cbuf) {
	int retval = cbuf->data[cbuf->readindex];
	cbuf->readindex++;
	cbuf->readindex = cbuf->readindex % BUFFERSIZE;
	return retval;
}

int main(void) {
	cbuffer *cb = create_cbuffer();
	// Write to buffer:
	for (int i = 0; i < 13; i++) {
		write_buffer(cb, i);
	}
	// Read from buffer:
	for (int i = 0; i < BUFFERSIZE; i++) {
		int index = cb->readindex;
		printf("ReadIndex: %d Value: %d\n", index, read_buffer(cb));
	}
	return 0;
}