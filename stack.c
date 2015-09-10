/*
stack.c
Written in 2015 by Michael Bosse metiscus@gmail.com

To the extent possible under law, the author(s) have dedicated all copyright
and related and neighboring rights to this software to the public domain
worldwide. This software is distributed without any warranty.
You should have received a copy of the CC0 Public Domain Dedication along with
this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
*/
#include "stack.h"
#include <assert.h>
#include <stdlib.h>

struct stack_t
{
    uint32_t size;
    uint32_t count;
    StackDataType *data;
};

struct stack_t* stack_new(uint32_t size)
{
    struct stack_t* ptr = (struct stack_t*)malloc(sizeof(struct stack_t*));
    if(ptr) {
        ptr->data  = (StackDataType*)malloc(sizeof(StackDataType)*size);
        if(ptr->data) {
            ptr->count = 0;
            ptr->size  = size;
        }
        else {
            ptr->size = 0;
        }
    }

    return ptr;
}

void stack_delete(struct stack_t* stack)
{
    if(stack) {
        free(stack->data);
        stack->data = 0;
        stack->count = 0;
        stack->size = 0;
    }
}

void stack_push(struct stack_t* stack, StackDataType* value)
{
    assert(stack && stack->data);
    assert(value);
    assert(stack->count < stack->size);
    stack->data[++stack->count] = *value;
}

void stack_pop(struct stack_t* stack)
{
    assert(stack && stack->data);
    assert(stack->count > 0);
    --stack->count;
}

void stack_top(struct stack_t* stack, StackDataType* data)
{
    assert(stack && stack->data);
    assert(data);
    assert(stack->count > 0);
    *data = stack->data[stack->count];
}

uint32_t stack_size(struct stack_t* stack)
{
    if(!stack || !stack->data) {
        return 0;
    }
    else {
        return stack->size;
    }
}

uint32_t stack_depth(struct stack_t* stack)
{
    if(!stack || !stack->data) {
        return 0;
    }
    else {
        return stack->count;
    }
}
