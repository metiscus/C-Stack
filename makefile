CFLAGS=-Wall -Wextra
CC=gcc

all: libstack.a stack_test

libstack.a: stack.o stack.c
	ar -rcs libstack.a stack.o

.PHONY: tests
tests: stack_test
	@echo "Running unit tests"
	@./stack_test
	@echo "All tests passed"

stack_test: stack_test.o stack_test.c libstack.a
	$(CC) $(CFLAGS) -o stack_test stack_test.o -L. -lstack

clean:
	-rm -f stack.o libstack.a stack_test stack_test.o
