CC = gcc
OPTS = --std=c99 -Wall -O2

all:	p001 p002 p003 p004 p005 p006 p007 p008 p009 p010 p011 p012

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

p006:	p006.c
	$(CC) $(OPTS) -o p006 p006.c

p007:	p007.c
	$(CC) $(OPTS) -o p007 p007.c

p008:	p008.c
	$(CC) $(OPTS) -o p008 p008.c

p009:	p009.c
	$(CC) $(OPTS) -o p009 p009.c

p010:	p010.c
	$(CC) $(OPTS) -o p010 p010.c

p011:	p011.c
	$(CC) $(OPTS) -o p011 p011.c

p012:	p012.c
	$(CC) $(OPTS) -o p012 p012.c

clean:
	/bin/rm -fr p001 p002 p003 p004 p005 p006 p007 p008 p009 p010 p011 p012 *~

