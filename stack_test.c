/*
stack_test.c
Written in 2015 by Michael Bosse metiscus@gmail.com

To the extent possible under law, the author(s) have dedicated all copyright
and related and neighboring rights to this software to the public domain
worldwide. This software is distributed without any warranty.
You should have received a copy of the CC0 Public Domain Dedication along with
this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
*/
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int g_fail = 0;

#define BeginTest(msg)                                              \
    do {                                                            \
        printf("[Test %s]\n", msg);
#define TestAssert(cond)                                            \
        {                                                                   \
            int result = (cond);                                            \
            printf("\t[%-30s] : %s\n", #cond, (result) ? "true" : "false"); \
            g_fail += !result;                                              \
        }
#define EndTest()\
    } while(0);



int main(int argc, char** argv)
{
    //Test 1
    BeginTest("Empty Stack Test")
    struct stack_t *theStack = stack_new(0);
    TestAssert(stack_size(theStack) == 0);
    stack_delete(theStack);
    EndTest();

    //Test 2
    BeginTest("Stack Create(5)")
    struct stack_t *theStack = stack_new(5);
    TestAssert(stack_size(theStack)==5)

    StackDataType value = (StackDataType)0;
    TestAssert(stack_depth(theStack) == 0);
    stack_push(theStack, &value);
    TestAssert(stack_depth(theStack) == 1);
    stack_push(theStack, &value);
    TestAssert(stack_depth(theStack) == 2);
    stack_push(theStack, &value);
    TestAssert(stack_depth(theStack) == 3);
    stack_push(theStack, &value);
    TestAssert(stack_depth(theStack) == 4);
    stack_push(theStack, &value);
    TestAssert(stack_depth(theStack) == 5);
    stack_delete(theStack);
    EndTest();

    // Test 3
    BeginTest("Stack Exercise")
    struct stack_t *theStack = stack_new(50);
    int i;
    StackDataType value = 0, top;
    for(i=0; i<103; ++i) {
        if((i / 50) % 2 == 0) {
            value = (StackDataType)i;
            stack_push(theStack, &value);
            stack_top(theStack, &top);
            TestAssert(top == value);
        }
        else {
            stack_pop(theStack);
        }
    }

    TestAssert(stack_depth(theStack) == 3);
    stack_top(theStack, &top);
    TestAssert(top == 102);
    stack_delete(theStack);
    TestAssert(stack_depth(theStack) == 0);
    TestAssert(stack_size(theStack) == 0);
    EndTest();

    return g_fail;
}
