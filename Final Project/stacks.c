#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define STACKSIZE 50

typedef struct
{
    char op;
    struct stackNode* next;
} stackNode; //List implementation of stacks

typedef struct
{
    stackNode* top;
} Stack;

stackNode* constructStacksNode(char val)
{
    stackNode* node = (stackNode*)malloc(sizeof(stackNode));
    node->op = val;
    node->next = NULL;
    return node;

}

Stack* initializeStack()
{
    Stack* s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack* stack, char value)
{
    stackNode* node = constructStacksNode(value);
    node->next = stack->top;
    stack->top = node;
}

char pop(Stack* stack)
{
    stackNode* node = stack->top;
    char op = node->op;
    stack->top = node->next;
    free(node);
    return op;
}
