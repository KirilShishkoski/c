
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue{
    size_t size;
    int * buffer;
    size_t frontIndex;
    size_t backIndex;
    size_t currentSize;
};



struct Queue * queue_create(size_t size){
    
    struct Queue * tempQueue = malloc(sizeof(struct Queue));
    
    if(!tempQueue) return NULL;
    
    tempQueue->size = size;
    tempQueue->buffer = malloc(size * sizeof(int));
    
    if(!tempQueue->buffer){
        free(tempQueue);
        return NULL;
    }
    
    tempQueue->frontIndex = 0;
    tempQueue->backIndex = 0;
    tempQueue->currentSize = 0;
    
    return tempQueue;
    
}

bool queue_destroy(struct Queue * queue){
    if(!queue) return 0;
    free(queue->buffer);
    free(queue);
    return 1;
}

void queue_print(struct Queue * queue){
    
    size_t index = queue->frontIndex;
    
    for(size_t i=0; i<queue->currentSize; i++){
        printf("%d\t", queue->buffer[index]);
        index = (index+1) % queue->size;
    }
    
    printf("\n");
    
}

void queue_enqueue(int element, struct Queue * queue){
    
    if(queue->currentSize == queue->size) return;
    
    queue->buffer[queue->backIndex] = element;
    queue->backIndex = (queue->backIndex+1) % queue->size;
    queue->currentSize++;
}

int queue_dequeue(struct Queue * queue){
    
    if(queue->currentSize == 0) return -1;
    
    int dequeued = queue->buffer[queue->frontIndex];
    queue->frontIndex = (queue->frontIndex+1) % queue->size;
    queue->currentSize--;
    return dequeued;
}

bool queue_is_empty(struct Queue * queue){
    return queue->currentSize == 0;
}

bool queue_is_full(struct Queue * queue){
    return queue->currentSize == queue->size;
}
