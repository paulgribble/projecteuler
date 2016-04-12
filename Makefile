CC = gcc
OPTS = --std=c99 -Wall

all:	p001 p002 p003 p004 p005

p001:	p001.c
	$(CC) $(OPTS) -o p001 p001.c

p002:	p002.c
	$(CC) $(OPTS) -o p002 p002.c

p003:	p003.c
	$(CC) $(OPTS) -o p003 p003.c -lm

p004:	p004.c
	$(CC) $(OPTS) -o p004 p004.c

p005:	p005.c
	$(CC) $(OPTS) -o p005 p005.c

clean:
	/bin/rm -fr p001 p002 p003 p004 p005 *~

