#include <stdio.h>
#include "queue.h"

int main(void) {

    printf("== Create queue with capacity 5 ==\n");
    struct Queue *queue = queue_create(5);
    if (!queue) {
        fprintf(stderr, "Failed to create queue\n");
        return 1;
    }

    printf("Empty: %s\n", queue_is_empty(queue) ? "YES" : "NO");
    printf("Full : %s\n\n", queue_is_full(queue) ? "YES" : "NO");

    printf("\n== Fill queue ==\n");
    queue_enqueue(1, queue);
    queue_enqueue(2, queue);
    queue_enqueue(3, queue);
    queue_enqueue(4, queue);
    queue_enqueue(5, queue);

    queue_print(queue);

    printf("Empty: %s\n", queue_is_empty(queue) ? "YES" : "NO");
    printf("Full : %s\n\n", queue_is_full(queue) ? "YES" : "NO");

    printf("== Dequeue two elements (free front slots) ==\n");
    printf("Dequeued: %d\n", queue_dequeue(queue));
    printf("Dequeued: %d\n", queue_dequeue(queue));

    queue_print(queue);

    printf("Empty: %s\n", queue_is_empty(queue) ? "YES" : "NO");
    printf("Full : %s\n\n", queue_is_full(queue) ? "YES" : "NO");

    printf("== Enqueue elements again (wrap-around) ==\n");
    queue_enqueue(6, queue);
    queue_enqueue(7, queue);

    queue_print(queue);

    printf("Empty: %s\n", queue_is_empty(queue) ? "YES" : "NO");
    printf("Full : %s\n\n", queue_is_full(queue) ? "YES" : "NO");

    printf("== Dequeue all elements ==\n");
    while (!queue_is_empty(queue)) {
        printf("Dequeued: %d\n", queue_dequeue(queue));
    }

    queue_print(queue);

    printf("Empty: %s\n", queue_is_empty(queue) ? "YES" : "NO");
    printf("Full : %s\n\n", queue_is_full(queue) ? "YES" : "NO");

    /* Clean up */
    if(queue_destroy(queue)) queue=NULL;

    return 0;
}