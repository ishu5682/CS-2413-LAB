#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int front, rear, size, capacity;
} Queue;

// Function to create a queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// Check if queue is empty
bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Enqueue (push to back)
void enqueue(Queue* queue, int item) {
    if (queue->size == queue->capacity) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size++;
}

// Dequeue (pop from front)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1;
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Get front element
int front(Queue* queue) {
    return isEmpty(queue) ? -1 : queue->data[queue->front];
}

// Stack structure using two queues
typedef struct {
    Queue *q1, *q2;
} MyStack;

// Create stack
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue(100);
    stack->q2 = createQueue(100);
    return stack;
}

// Push operation (O(n) time complexity)
void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q2, x); // Push to q2

    // Move all elements from q1 to q2
    while (!isEmpty(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }

    // Swap names of q1 and q2
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

// Pop operation (O(1) time complexity)
int myStackPop(MyStack* obj) {
    return dequeue(obj->q1);
}

// Top operation (O(1) time complexity)
int myStackTop(MyStack* obj) {
    return front(obj->q1);
}

// Empty check
bool myStackEmpty(MyStack* obj) {
    return isEmpty(obj->q1);
}

// Free memory
void myStackFree(MyStack* obj) {
    free(obj->q1->data);
    free(obj->q2->data);
    free(obj->q1);
    free(obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */
