/*
stack.h
Written in 2015 by Michael Bosse metiscus@gmail.com

To the extent possible under law, the author(s) have dedicated all copyright
and related and neighboring rights to this software to the public domain
worldwide. This software is distributed without any warranty.
You should have received a copy of the CC0 Public Domain Dedication along with
this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
*/
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdint.h>

#ifndef StackDataType
#define StackDataType uint32_t
#endif

struct stack_t;

extern struct stack_t* stack_new(uint32_t size);
extern void stack_delete(struct stack_t* stack);
extern void stack_push(struct stack_t* stack, StackDataType* value);
extern void stack_pop(struct stack_t* stack);
extern void stack_top(struct stack_t* stack, StackDataType* data);
extern uint32_t stack_size(struct stack_t* stack);
extern uint32_t stack_depth(struct stack_t* stack);

#endif // STACK_H_INCLUDED
