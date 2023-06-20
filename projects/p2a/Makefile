# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -g -ggdb

# Target binaries
TARGETS = fork-demo exec-demo fork-exec-demo mysh hello

all: $(TARGETS)

fork-demo: fork-demo.c
	$(CC) $(CFLAGS) -o $@ $<

exec-demo: exec-demo.c
	$(CC) $(CFLAGS) -o $@ $<

fork-exec-demo: fork-exec-demo.c
	$(CC) $(CFLAGS) -o $@ $<

mysh: mysh-demo.c linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -o $@ mysh-demo.c linkedlist.c

hello: hello.c
	$(CC) $(CFLAGS) -o $@ $<

helloplay2: hello
	./hello > hello.out 2>&1

clean:
	rm -f $(TARGETS)
