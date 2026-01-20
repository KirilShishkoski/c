
#include <stdlib.h>
#include "hash_table.h"


struct HashTable{
    uint32_t n;
    float lf;
    size_t size;
    struct Node ** buckets_buffer;
};   

struct Node{
    int key;
    int value;
    struct Node * next;
};


struct HashTable * hash_table_create(uint32_t n, float load_factor){
    
    struct HashTable * tempHT = malloc(sizeof(struct HashTable));
    if(!tempHT) return NULL;
    
    tempHT->n = n;
    tempHT->lf = load_factor;
    tempHT->size=0;
    tempHT->buckets_buffer = calloc(n, sizeof(struct Node *));
    
    return tempHT;
}

struct Node * createNode(int key, int value){
    struct Node * tempNode = malloc(sizeof(struct Node));
    if(!tempNode) return NULL;
    
    tempNode->key = key;
    tempNode->value = value;
    tempNode->next = NULL;
    
    return tempNode;
}


uint32_t hash(int key, uint32_t n){
    
    uint32_t A = 0x9E3779B1; //2654435761 --> Knuths's const.
    uint32_t h = key * A;
    
    return h & (n - 1);
}


void hash_table_put(int key, int value, struct HashTable * ht){
    
    
    //check and make sure the load factor stays the same after next insertion, resize and rehash if necessary
    if(ht->size+1 >= ht->lf * ht->n){
        
        uint32_t old_n = ht->n;
        uint32_t new_n = old_n * 2;
        
        struct Node ** enlarged_buckets_buffer = calloc(new_n, sizeof(struct Node*));
        
        if(!enlarged_buckets_buffer) return;
        
        for(uint32_t i=0; i<old_n; i++){
            
            struct Node * moveNode = ht->buckets_buffer[i];
            
            while(moveNode){
                
                struct Node * nextNode = moveNode->next;
                
                uint32_t newIndex = hash(moveNode->key, new_n);
                moveNode->next = enlarged_buckets_buffer[newIndex];
                enlarged_buckets_buffer[newIndex] = moveNode;
                
                moveNode = nextNode;
                
            }

        }
        
        
        struct Node ** destroy_old_buckets_buffer = ht->buckets_buffer;
        ht->buckets_buffer = enlarged_buckets_buffer;
        free(destroy_old_buckets_buffer);
        ht->n = new_n;
        
    }
    
    uint32_t index = hash(key, ht->n);
    
    struct Node * current = ht->buckets_buffer[index];
    
    while(current){
        if(current->key == key){
            current->value = value;
            return;
        }
        current = current->next;
    }
    
    struct Node * processNode = createNode(key, value);
    if(!processNode) return;
    
    processNode->next = ht->buckets_buffer[index];
    ht->buckets_buffer[index] = processNode;
    ht->size++;
    
}

int * hash_table_get(int key, struct HashTable * ht){
    
    uint32_t index = hash(key, ht->n);
    
    struct Node * initialNode = ht->buckets_buffer[index];
    
    if(!initialNode) return NULL;
    
    while(initialNode){
        if(initialNode->key == key){\
            
            return &initialNode->value;
        }
        initialNode = initialNode->next;
    }
    
    return NULL;
    
}

bool hash_table_destroy(struct HashTable * ht){
    
    if(!ht) return 0;
    
    for(uint32_t i = 0; i<ht->n; i++){
        struct Node * nodeToRemove = ht->buckets_buffer[i];
        
        while(nodeToRemove){
            struct Node * destroyedNode = nodeToRemove;
            nodeToRemove = nodeToRemove->next;
            free(destroyedNode);
        }
        
    }
    
    struct Node ** buckets_to_remove = ht->buckets_buffer;
    free(buckets_to_remove);
    free(ht);
    
    return 1;
}

size_t hash_table_size(struct HashTable * ht){
    return (ht) ? ht->size : 0;
}
