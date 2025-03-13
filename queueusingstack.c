
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int stack1[MAX]; // Primary stack for push operations
    int stack2[MAX]; // Secondary stack for pop/peek operations
    int top1; // Top index of stack1
    int top2; // Top index of stack2
} MyQueue;

/** Initialize the queue */
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->top1 = -1; // Stack1 starts empty
    queue->top2 = -1; // Stack2 starts empty
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if (obj->top1 < MAX - 1) {
        obj->stack1[++obj->top1] = x; // Push onto stack1
    } else {
        printf("Queue overflow\n");
    }
}

/** Removes the element from the front of queue and returns it. */
int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) { // If stack2 is empty, move elements from stack1
        while (obj->top1 != -1) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    
    if (obj->top2 == -1) {
        printf("Queue underflow\n");
        return -1;
    }
    
    return obj->stack2[obj->top2--]; // Pop from stack2 (front of queue)
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) { // If stack2 is empty, move elements from stack1
        while (obj->top1 != -1) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    
    if (obj->top2 == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    
    return obj->stack2[obj->top2]; // Peek front element
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

/** Free the queue memory */
void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */
