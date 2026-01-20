#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"


#define MIN_SIZE 4

struct Array{
  size_t size; 
  int * buffer;
  size_t head;
};

static void check_resize(struct Array * array);

struct Array * array_create(size_t size){
    
    if(size < MIN_SIZE) size = MIN_SIZE;
    
     struct Array * tempArray = malloc(sizeof(struct Array));
     if(!tempArray) return NULL;
     tempArray->buffer = malloc(size * sizeof(int));
     if(!tempArray->buffer){
         free(tempArray);
         return NULL;
     }
     tempArray->head = 0;
     tempArray->size = size;
     return tempArray;
}

bool array_destroy(struct Array * array){
    if(!array) return 0;
    free(array->buffer);
    free(array);
    return 1;
}

void array_print(struct Array * array){
    if(!array || !array->buffer) return;
    
    for(size_t i=0; i<array->head; i++){
        printf("%d\n", array->buffer[i]);
    }
}

void array_push(int element, struct Array * array){
    
    if(!array || !array->buffer) return;
    // if(array->head >= array->size) return; //used for fixed array
    
    check_resize(array);
    
    array->buffer[array->head] = element;
    array->head++;
}

void array_pop(struct Array * array){
    
    if(!array || !array->buffer || array->head == 0) return;
    array->head--;
    check_resize(array);
    
}

void array_insert_at(size_t index, int element, struct Array * array){
    if(!array || !array->buffer) return;
    // if(array->head > array->size-1) return; //used for static
    if(index > array->head) return;
    
    check_resize(array);
    
    size_t shiftingIndex = array->head;
    
    while(shiftingIndex > index){
        
        array->buffer[shiftingIndex] = array->buffer[shiftingIndex-1];
        shiftingIndex--;
    }
    
    array->buffer[index] = element;
    array->head++;

}

void array_remove_at(size_t index, struct Array * array){
    if(!array || !array->buffer) return;
    if(index >= array->head) return;
    
    size_t shiftingIndex = index;
    
    while(shiftingIndex < array->head-1){
        array->buffer[shiftingIndex] = array->buffer[shiftingIndex + 1];
        shiftingIndex++;
    }

    array->head--;
    check_resize(array);
}

int array_element_at(size_t index, struct Array * array){
    if(!array) return -1;
    if(index >= array->head) return -1;
    
    return array->buffer[index];
}

int array_index_of(int element, struct Array * array){
    if(!array) return -1;

    for(size_t i=0; i<array->head; i++){
       if(element == array->buffer[i]){
           return i;
       }
    }
    return -1;

}

size_t array_length(struct Array * array){
    if(!array) return 0;
    return array->head;
}

size_t array_size(struct Array * array){
    if(!array) return 0;
    return array->size;
}

void array_reverse(struct Array * array){
    
    if(!array || array->head < 2) return;
    
    size_t left = 0;
    size_t right = array->head - 1;
    
    while(left < right){
        int tmp = array->buffer[left];
        array->buffer[left] = array->buffer[right];
        array->buffer[right] = tmp;
        left++;
        right--;
    }
}

static void check_resize(struct Array * array){
    
     if(!array || !array->buffer) return;
    
    if(array->head == array->size){
        //array is full
        
        int * new_buffer = realloc(array->buffer, 2*array->size * sizeof(int));
        
        if(!new_buffer) return;
        
        //if use malloc, copy the array to the new buffer
        // for(int i = 0; i<array->head; i++){
        //     new_buffer[i] = array->buffer[i];
        // }
        
        // free(array->buffer);
        array->buffer = new_buffer;
        array->size *= 2;
    }
    
    // else if((float) array->head / array->size <= 0.25 && array->size > 4){
       else if(array->head * 4 <= array->size && array->size > MIN_SIZE){ 
        int * new_buffer = realloc(array->buffer, array->size/2 * sizeof(int));
        
        if(!new_buffer) return;
        array->buffer = new_buffer;
        array->size /= 2;
    }
}