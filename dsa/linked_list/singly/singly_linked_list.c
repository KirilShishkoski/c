#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "singly_linked_list.h"

struct Node {
    int value;
    struct Node * next;
};

struct SinglyLinkedList{
    struct Node * head;
    struct Node * tail;
    size_t size;
};


struct SinglyLinkedList * sll_create(){
    struct SinglyLinkedList * tmpSLL = malloc(sizeof(struct SinglyLinkedList));
    
    if(!tmpSLL) return NULL;
    
    tmpSLL->head = NULL;
    tmpSLL->tail = NULL;
    tmpSLL->size = 0;
    
    return tmpSLL;
    
}

struct Node * sll_node_create(int value){
    struct Node * tmpNode = malloc(sizeof(struct Node));
    
    if(!tmpNode) return NULL;
    
    tmpNode->value = value;
    tmpNode->next = NULL;
    
    return tmpNode;
}

bool sll_destroy(struct SinglyLinkedList * sll){
    if(!sll) return false;
    
    struct Node * current = sll->head;
    
    while(current){
        struct Node * nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    free(sll);
    return true;
}

void sll_insert_head(struct Node * node, struct SinglyLinkedList * sll){
    if(!sll || !node) return;
    
    node->next = sll->head;
    
    if(sll->head == NULL){
        sll->tail = node;
    }
    
    sll->head = node;
    sll->size++;
}

void sll_insert_after(struct Node * nodeAfter, struct Node * newNode, struct SinglyLinkedList * sll ){
    
    if(!sll || !nodeAfter || !newNode) return;
    
    newNode->next = nodeAfter->next;
    nodeAfter->next = newNode;
    
    if(newNode->next == NULL){
        
        sll->tail = newNode;
    }
    
    sll->size++;

}

void sll_insert_tail(struct Node * node, struct SinglyLinkedList * sll){
    
    if(!sll || !node) return;
    
    node->next = NULL;
    
    if(sll->size == 0){
        sll->head = node;
        sll->tail = node;
    }else{
        sll->tail->next = node;
        sll->tail = node;
    }
    
    sll->size++;
    
}

void sll_remove_head(struct SinglyLinkedList * sll){
    
    if(!sll || sll->size == 0) return;
    
    struct Node * headToRemove = sll->head;
    
    if(sll->size == 1){
        sll->head = NULL;
        sll->tail = NULL;
    }else{
        sll->head = headToRemove->next;
    }
    
    free(headToRemove);
    sll->size--;
    
}

void sll_remove_tail(struct SinglyLinkedList * sll){
    
    if(!sll || sll->size == 0) return;
    
    if(sll->size == 1){
        free(sll->tail);
        sll->head = NULL;
        sll->tail = NULL;
    }else{
        struct Node * current = sll->head;
        
        while(current->next != sll->tail){
            current = current->next;
        }
        
        free(sll->tail);
        current->next = NULL;
        sll->tail = current;
    }
    
    sll->size--;
    
}

void sll_remove_after(struct Node * nodeAfter, struct SinglyLinkedList * sll){
    if(!sll || !nodeAfter || nodeAfter->next == NULL) return;
    
    struct Node * nodeAfterToRemove = nodeAfter->next;
    
    nodeAfter->next =nodeAfterToRemove->next;
    
    if(nodeAfterToRemove == sll->tail){
        sll->tail = nodeAfter;
    }
    
    free(nodeAfterToRemove);
    sll->size--;
}

void sll_traverse(struct SinglyLinkedList * sll){
    if(!sll) return;
    
    struct Node * tmpNode = sll->head;
    
    while(tmpNode != NULL){
        printf("%d\t", tmpNode->value);
        tmpNode = tmpNode->next;
    }
}

size_t sll_length(struct SinglyLinkedList * sll){
    if(!sll) return 0;
    return sll->size;
}