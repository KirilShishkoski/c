
#include <stdio.h>
#include <stdlib.h>
#include "stack_array.h"

struct Stack{
    size_t size;
    int * buffer;
    size_t topIndex;
};

struct Stack * stack_create(size_t size){
    struct Stack * tempStack = malloc(sizeof(struct Stack));
    
    if(!tempStack) return NULL;
    
    tempStack->buffer = malloc(sizeof(int) * size);
    
    if(!tempStack->buffer){
        free(tempStack);
        return NULL;
    }
    
    tempStack->size = size;
    tempStack->topIndex = 0;
    return tempStack;
}

void printStack(const Stack * stack) {
    if (!stack || stack->topIndex == 0) {
        printf("(stack is empty)\n");
        return;
    }

    for (size_t i = stack->topIndex; i > 0; i--) {
        printf("%d\n", stack->buffer[i - 1]);
    }
}

void stack_push(int element, struct Stack * currentStack){
    if(currentStack->topIndex >= (currentStack->size)){
        //Buffer is full, prevents buffer overflow
        return;
    }
    
        currentStack->buffer[currentStack->topIndex] = element;
        currentStack->topIndex++;
        
        // //new mem address = base + (index * element size)
        // char *baseAddress = (char *)currentStack->buffer;
        // int *nextAddress = (int *)(baseAddress + currentStack->topIndex * sizeof(int));
        // *nextAddress = element;
        // currentStack->topIndex++;
}

void stack_pop(struct Stack * currentStack){
    
    if(currentStack->topIndex == 0){
        return;
    }
    currentStack->topIndex--;
    currentStack->buffer[currentStack->topIndex] = 0;
}

int stack_peek(const struct Stack * currentStack){
    if(currentStack->topIndex == 0){
        return -1;
    }
    return currentStack->buffer[currentStack->topIndex-1];
}

bool stack_is_empty(const Stack * stack){
    if(!stack) return 0;

    return stack->topIndex == 0 ? 1 : 0;
}

bool stack_is_full(const Stack * stack){
    if(!stack) return 0;

    return stack->topIndex == stack->size ? 1 : 0;
}

bool stack_destroy(struct Stack * currentStack){
    if(!currentStack) return 0;
    free(currentStack->buffer);
    free(currentStack);
    return 1;
}