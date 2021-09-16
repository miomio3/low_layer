CC = gcc
CFLAGS = -g -static
SRCS = $(wildcard *.c)
OBJS = $(SRCS: .c = .o ) 

9cc: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o 9cc

clean:
	rm -f 9cc tmp*

.PHONY: clean test

