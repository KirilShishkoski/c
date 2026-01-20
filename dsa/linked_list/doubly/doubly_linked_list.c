
#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

struct Node {
    int value;
    struct Node * prev;
    struct Node * next;
};

struct DoublyLinkedList {
    struct Node * head;
    struct Node * tail;
    size_t size;  
};


struct DoublyLinkedList * dll_create(){
    struct DoublyLinkedList * tempDLL = malloc(sizeof(struct DoublyLinkedList));
    
    if(!tempDLL) return NULL;
    
    tempDLL->head = NULL;
    tempDLL->tail = NULL;
    tempDLL->size = 0;
    
    return tempDLL;
}

bool dll_destroy(struct DoublyLinkedList * dll){
    if(!dll) return 0;
    
    struct Node * current = dll->head;
    
    while(current){
        struct Node * nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    free(dll);
    return 1;
}

struct Node * dll_node_create(int value){
    struct Node * tmpNode = malloc(sizeof(struct Node));
    if(!tmpNode) return NULL;
    
    tmpNode->value = value;
    tmpNode->prev = NULL;
    tmpNode->next = NULL;
    
    return tmpNode;
}

void dll_traverse(const struct DoublyLinkedList * dll){
    
    if(!dll) return;
    
    const struct Node * tmpNode = dll->head;
    
    while(tmpNode != NULL){
        printf("%d\t", tmpNode->value);
        
        tmpNode = tmpNode->next;
    }
    
}

void dll_insert_head(struct Node * node, struct DoublyLinkedList * dll){
        
        if(!dll || !node) return;
        
        node->prev = NULL;
        node->next = dll->head;
        
        if(dll->head != NULL){
            dll->head->prev = node;
        }else{
            dll->tail = node;
        }
        
        dll->head = node;
        dll->size++;

}

void dll_insert_tail(struct Node * node, struct DoublyLinkedList * dll){
    if(!dll || !node) return;
    
    node->next = NULL;
    
    if(dll->size == 0){
        
        node->prev = NULL;
        dll->head = node;
        dll->tail = node;
        
    }else{
         dll->tail->next = node;
        node->prev = dll->tail;
        dll->tail = node;
    }
        dll->size++;
}

void dll_insert_after(struct Node * nodeAfter, struct Node * newNode, struct DoublyLinkedList * dll){
    
    if(!dll || !nodeAfter || !newNode) return;
    
    newNode->prev = nodeAfter;
    newNode->next = nodeAfter->next;
    
    if(nodeAfter->next != NULL){
        nodeAfter->next->prev = newNode;
    }
    else{
        dll->tail = newNode;
    }
    
    nodeAfter->next = newNode;
    dll->size++;
    
}

void dll_remove_head(struct DoublyLinkedList * dll){
    if(!dll || dll->size == 0) return;
    
    struct Node * headToRemove = dll->head;
    
    if(dll->size == 1){
        dll->head = NULL;
        dll->tail = NULL;
    } else{
        dll->head = headToRemove->next;
        dll->head->prev = NULL;
    }
    
    free(headToRemove);
    dll->size--;
    
}

void dll_remove_tail(struct DoublyLinkedList * dll){
    if(!dll || dll->size == 0) return;
    
    struct Node * tailToRemove = dll->tail;
    
    if(dll->size == 1){
        dll->head = NULL;
        dll->tail = NULL;
    }
    else{
        dll->tail = tailToRemove->prev;
        dll->tail->next = NULL;
    }
    
    free(tailToRemove);
    dll->size--;
}

void dll_remove_after(struct Node * nodeAfter, struct DoublyLinkedList * dll){
    
    if(!dll || !nodeAfter || !nodeAfter->next) return;
    
    struct Node * nodeAfterToRemove = nodeAfter->next;
    
    nodeAfter->next = nodeAfterToRemove->next;
    
    if(nodeAfterToRemove->next != NULL){
        nodeAfter->next->prev = nodeAfter;
    }
    else{
        dll->tail = nodeAfter;
    }
    
    free(nodeAfterToRemove);
    dll->size--;
    
}

size_t dll_length(const struct DoublyLinkedList * dll){
    return dll ? dll->size : 0;
}