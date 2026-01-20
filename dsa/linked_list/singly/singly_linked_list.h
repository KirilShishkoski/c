#ifndef SLL_H
#define SLL_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @file sll.h
 * @brief A singly linked list implementation in C.
 *
 * This module provides a dynamic singly linked list that stores
 * integer values. Nodes are allocated individually on the heap
 * and linked together via pointers.
 *
 * Features:
 *  - O(1) insertion at head and tail
 *  - O(1) removal at head
 *  - O(n) removal at tail
 *  - O(n) traversal
 *  - Explicit memory management
 *
 * The list maintains both head and tail pointers for efficiency.
 *
 * @author Kiril Shishkoski
 * @version 1.0
 * @copyright Copyright (c) 2026 Kiril Shishkoski
 * @license MIT
 */

/* Forward declarations */
typedef struct SinglyLinkedList SinglyLinkedList;
typedef struct Node Node;

/**
 * @brief Create an empty singly linked list.
 *
 * Allocates and initializes a new list with no nodes.
 *
 * @return Pointer to a newly created list, or NULL on allocation failure.
 */
SinglyLinkedList * sll_create(void);

/**
 * @brief Destroy a singly linked list and free all its nodes.
 *
 * Frees every node in the list and the list structure itself.
 *
 * @param sll Pointer to the list to destroy.
 *
 * @return true if the list was destroyed, false if @p sll is NULL.
 */
bool sll_destroy(SinglyLinkedList * sll);

/**
 * @brief Create a new list node with a given value.
 *
 * Allocates a node and initializes its value.
 *
 * @param value Integer value to store in the node.
 *
 * @return Pointer to a newly created node, or NULL on allocation failure.
 */
Node * sll_node_create(int value);

/**
 * @brief Insert a node at the head of the list.
 *
 * @param node Node to insert.
 * @param sll Pointer to the list.
 */
void sll_insert_head(Node * node, SinglyLinkedList * sll);

/**
 * @brief Insert a node at the tail of the list.
 *
 * @param node Node to insert.
 * @param sll Pointer to the list.
 */
void sll_insert_tail(Node * node, SinglyLinkedList * sll);

/**
 * @brief Insert a node after a given node.
 *
 * @param nodeAfter Existing node after which insertion occurs.
 * @param newNode Node to insert.
 * @param sll Pointer to the list.
 */
void sll_insert_after(Node * nodeAfter, Node * newNode, SinglyLinkedList * sll);

/**
 * @brief Remove the head node from the list.
 *
 * Does nothing if the list is empty.
 *
 * @param sll Pointer to the list.
 */
void sll_remove_head(SinglyLinkedList * sll);

/**
 * @brief Remove the tail node from the list.
 *
 * Does nothing if the list is empty.
 *
 * @param sll Pointer to the list.
 */
void sll_remove_tail(SinglyLinkedList * sll);

/**
 * @brief Remove the node after a given node.
 *
 * @param nodeAfter Node preceding the node to remove.
 * @param sll Pointer to the list.
 */
void sll_remove_after(Node * nodeAfter, SinglyLinkedList * sll);

/**
 * @brief Traverse and print the list contents.
 *
 * Prints each node value from head to tail.
 *
 * @param sll Pointer to the list.
 */
void sll_traverse(SinglyLinkedList * sll);

/**
 * @brief Get the number of nodes in the list.
 *
 * @param sll Pointer to the list.
 *
 * @return Number of nodes in the list, or 0 if @p sll is NULL.
 */
size_t sll_length(SinglyLinkedList * sll);

#endif /* SLL_H */