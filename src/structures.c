#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ++++++++++++++ LINKED LIST ++++++++++++++++++
//
struct Node *LinkedList_new() {
  struct Node *node = malloc(sizeof(struct Node));
  // zero init
  node->n = NULL;
  node->value = 0;
  return node;
}

void LinkedList_free(struct Node *head) {
  if (head == NULL)
    return;

  struct Node *tmp;
  while (head != NULL) {
    tmp = head;
    head = head->n;
    tmp->n = NULL;
    free(tmp);
  }
}

struct Node *LinkedList_from_array(int *a, int len) {
  struct Node *head = LinkedList_new();
  head->n = NULL;

  struct Node *current = head;

  for (int i = 0; i < len; i++) {
    current->value = a[i];
    if (i < len - 1) {
      struct Node *next = LinkedList_new();
      current->n = next;
      current = next;
    }
  }
  return head;
}

int LinkedList_length(struct Node *head) {
  if (head == NULL)
    return 0;

  struct Node *current = head;
  int len = 0;
  while (current != NULL) {
    ++len;
  }
  return len;
}

// 1 -> 2 -> 3    to 3 -> 2 -> 1
struct Node *LinkedList_reverse(struct Node *head) {
  if (head == NULL)
    return NULL;

  struct Node *current = head;
  struct Node *reversed = NULL;
  struct Node *next = NULL;
  // the current node will run from
  // the start of the list to the end of the list
  while (current) {
    // store the next pointer here.
    next = current->n;
    //
    current->n = reversed;
    reversed = current;
    current = next;
  }
  return reversed;
}

int LinkedList_has_cycles(struct Node *head) {
  int has_cycles = 0;

  // initialize everything to look at head
  struct Node *current_head = head;
  struct Node *pointer = head;

  while (current_head != NULL) {
    while (pointer != NULL) {
      if (pointer->n == current_head) {
        has_cycles = 1;
        return has_cycles;
      }
      pointer = pointer->n;
    }
    current_head = current_head->n;
  }
  return has_cycles;
}

// add node at the beginning of the list and return new head
struct Node *LinkedList_add(struct Node *head, int value) {
  if (head == NULL) {
    return NULL;
  }

  struct Node *new = LinkedList_new();
  new->value = value;
  new->n = head;
  return new;
}

// append value at the end of the list
void LinkedList_append(struct Node *head, int value) {
  struct Node *current = head;
  struct Node *new = LinkedList_new();
  new->value = value;

  while (current->n != NULL) {
    current = current->n;
  }
  current->n = new;
}

void LinkedList_print(struct Node *head) {
  if (head == NULL) {
    return;
  }
  printf("%d", head->value);
  if (head->n != NULL) {
    printf(" -> ");
  }
  LinkedList_print(head->n);
}

// ++++++++++++++ QUEUE ++++++++++++++++++
struct Queue *Queue_new() {
  struct Queue *q = malloc(sizeof(struct Queue));
  struct Node *head = LinkedList_new();
  q->head = head;
  return q;
}

int Queue_peek(struct Queue *queue) { return queue->head->value; }

// add a new item at the end of the queue
void Queue_queue(struct Queue *queue, int value) {
  return LinkedList_append(queue->head, value);
}

int Queue_dequeue(struct Queue *queue) {
  int value = Queue_peek(queue);
  struct Node *old_head = queue->head;
  queue->head = queue->head->n;
  free(old_head);
  return value;
}

// ++++++++++++++ STACK ++++++++++++++++++

struct Stack *Stack_new() {
  struct Stack *stack = malloc(sizeof(struct Stack));
  struct Node *head = LinkedList_new();
  stack->head = head;
  stack->length = 0;
  return stack;
}

int Stack_peek(struct Stack *stack) { return stack->head->value; }

void Stack_add(struct Stack *stack, int value) {
  stack->length++;
  stack->head = LinkedList_add(stack->head, value);
}

int Stack_pop(struct Stack *stack) {
  stack->length--;
  int value = Stack_peek(stack);
  struct Node *old_head = stack->head;
  stack->head = stack->head->n;
  free(old_head);
  return value;
}

// ++++++++++++++ Trees ++++++++++++++++++
// ++++++++++++++ Binary search tree +++++

struct BSTree *BSTree_new(int value) {
  struct BSTree *tree = malloc(sizeof(struct BSTree));
  tree->value = value;
  return tree;
}

void BSTree_free(struct BSTree *tree) {
  if (tree == NULL) return;
  if (tree->right != NULL) BSTree_free(tree->right);
  if (tree->left != NULL) BSTree_free(tree->left);
  free(tree);
  return;
}

bool BSTree_find(struct BSTree *tree, int value) {
  if (tree == NULL) return false;
  if (value == tree->value) return true;
  if (tree->right != NULL) {
    return BSTree_find(tree->right, value);
  }
  if (tree->left != NULL) {
    return BSTree_find(tree->left, value);
  }
  return false;
}

void BSTree_insert(struct BSTree *tree, int value) {
  if (tree == NULL) return; 

  // larger values on the right
  if (value >= tree->value) {
    if (tree->right == NULL) {
      tree->right = BSTree_new(value);
      return;
    }
    else {
      BSTree_insert(tree->right, value);
    }
  }
  else {
    if (tree->left == NULL) {
      tree->left = BSTree_new(value);
      return;
    }
    else {
      BSTree_insert(tree->left, value);
    }
  }
}
