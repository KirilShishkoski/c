#ifndef DLL_H
#define DLL_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @file doubly_linked_list.h
 * @brief A doubly linked list implementation in C.
 *
 * This module provides a dynamic doubly linked list storing integer values.
 * Each node maintains pointers to both the previous and next nodes, allowing
 * efficient insertion and removal at both ends and after arbitrary nodes.
 *
 * Features:
 *  - O(1) insertion/removal at head and tail
 *  - O(1) insertion/removal after a known node
 *  - Bidirectional traversal capability
 *  - Explicit memory management
 *
 * The internal structure of the list is opaque to users.
 *
 * @author Kiril Shishkoski
 * @version 1.0
 * @copyright Copyright (c) 2026 Kiril Shishkoski
 * @license MIT
 */

typedef struct DoublyLinkedList DoublyLinkedList;
typedef struct Node Node;



/**
 * @brief Create an empty doubly linked list.
 *
 * Allocates and initializes a new list structure.
 *
 * @return Pointer to a newly created list, or NULL on allocation failure.
 */
DoublyLinkedList * dll_create(void);



/**
 * @brief Destroy a doubly linked list and free all associated memory.
 *
 * Frees all nodes in the list and the list structure itself.
 *
 * @param dll Pointer to the list to destroy.
 *
 * @return true if the list was destroyed, false otherwise.
 */
bool dll_destroy(DoublyLinkedList * dll);



/**
 * @brief Create a new list node with the given value.
 *
 * Allocates a node initialized with the specified value.
 *
 * @param value Integer value to store in the node.
 *
 * @return Pointer to a newly created node, or NULL on allocation failure.
 */
Node * dll_node_create(int value);



/**
 * @brief Traverse the list from head to tail and print elements.
 *
 * @param dll Pointer to the list.
 */
void dll_traverse(const DoublyLinkedList * dll);



/**
 * @brief Insert a node at the beginning of the list.
 *
 * @param node Node to insert.
 * @param dll Pointer to the list.
 */
void dll_insert_head(Node * node, DoublyLinkedList * dll);



/**
 * @brief Insert a node at the end of the list.
 *
 * @param node Node to insert.
 * @param dll Pointer to the list.
 */
void dll_insert_tail(Node * node, DoublyLinkedList * dll);



/**
 * @brief Insert a node after a specified node.
 *
 * @param nodeAfter Node after which the new node will be inserted.
 * @param newNode Node to insert.
 * @param dll Pointer to the list.
 */
void dll_insert_after(Node * nodeAfter, Node * newNode, DoublyLinkedList * dll);



/**
 * @brief Remove the first node from the list.
 *
 * Does nothing if the list is empty.
 *
 * @param dll Pointer to the list.
 */
void dll_remove_head(DoublyLinkedList * dll);



/**
 * @brief Remove the last node from the list.
 *
 * Does nothing if the list is empty.
 *
 * @param dll Pointer to the list.
 */
void dll_remove_tail(DoublyLinkedList * dll);



/**
 * @brief Remove the node immediately following a given node.
 *
 * @param nodeAfter Node after which removal occurs.
 * @param dll Pointer to the list.
 */
void dll_remove_after(Node * nodeAfter, DoublyLinkedList * dll);



/**
 * @brief Get the number of elements currently stored in the list.
 *
 * @param dll Pointer to the list.
 *
 * @return Number of nodes in the list.
 */
size_t dll_length(const DoublyLinkedList * dll);

#endif /* DLL_H */