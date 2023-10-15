#ifndef STRUCTURES_H_   /* Include guard */
#define STRUCTURES_H_

// linked list stuff
struct Node {
    int value;
    struct Node* n;
};

struct Node* LinkedList_new();
void LinkedList_free(struct Node* head);
struct Node* LinkedList_from_array(int* a, int len);
int LinkedList_length(struct Node* head);
struct Node* LinkedList_reverse(struct Node* head);
struct Node* LinkedList_add(struct Node* head, int value);
void LinkedList_append(struct Node* head, int value);
void LinkedList_print(struct Node* head);
int LinkedList_has_cycles(struct Node* head);

// a queue is a linked list where 'head' is the next item in the queue
// last-in last out
struct Queue {
    int length;
    struct Node* head;
};

// a stack is a linked list where 'head' is the next item on the stack
// last-in first out
struct Stack {
    int length;
    struct Node* head;
};


#endif
