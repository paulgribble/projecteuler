CC = gcc
OPTS = --std=c99

all:	p001 p002

p001:	p001.c
	$(CC) $(OPTS) -o p001 p001.c

p002:	p002.c
	$(CC) $(OPTS) -o p002 p002.c

clean:
	/bin/rm -fr p001 p002

