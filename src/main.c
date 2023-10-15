#include "structures.h"
#include "functions.h"
#include <stdio.h>

void LinkedList_tests(){
    // create a linked list from an array
    int a[5] = {1, 2, 3, 4, 5};
    struct Node* list_from_array = LinkedList_from_array(a, 5);
    printf("\n\n ----- List from array ------ \n");
    printf("expected: 1 -> 2 -> 3 -> 4 -> 5\n");
    printf("actual: ");
    LinkedList_print(list_from_array);

    printf("\n\n ----- reverse ------ \n");
    printf("expected: 5 -> 4 -> 3 -> 2 -> 1\n");
    struct Node* reversed = LinkedList_reverse(list_from_array);
    printf("actual: ");
    LinkedList_print(reversed);

    printf("\n\n ----- append ------ \n");
    printf("expected: 5 -> 4 -> 3 -> 2 -> 1 -> 99\n");
    LinkedList_append(reversed, 99);
    printf("actual: ");
    LinkedList_print(reversed);

    printf("\n\n ----- add ------ \n");
    printf("expected: 99 -> 5 -> 4 -> 3 -> 2 -> 1 -> 99\n");
    struct Node* added = LinkedList_add(reversed, 99);
    printf("actual: ");
    LinkedList_print(added);

    printf("\n\n ----- cycles ------ \n");
    printf("expected: 0\n");
    int has_cycles = LinkedList_has_cycles(added);
    printf("actual: %d\n", has_cycles);
    struct Node* c1 = LinkedList_new();
    struct Node* c2 = LinkedList_new();
    struct Node* c3 = LinkedList_new();
    struct Node* c4 = LinkedList_new();
    c1->n = c2;
    c2->n = c3;
    c3->n = c4;
    c4->n = c1;
    has_cycles = LinkedList_has_cycles(c1);
    printf("expected: 1\n");
    printf("actual: %d\n", has_cycles);
}

void binary_search_tests(){
    const int n = 30;
    const int search = 16;
    int a[n];
    int found;

    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
    found = binary_search(search, a, n);

    printf("\n\n ----- binary search ------ \n");
    printf("expected: %d\n", search);
    printf("actual: %d\n", found);
}

void bubble_sort_tests(){
    int a[5] = {4, 3, 1, 7, 0};

    printf("\n\n ----- bubble sort ------ \n");

    printf("array: \n");
    printf("[");
    for (int i = 0; i < 5; ++i) {
        printf("%d, ", a[i]);
    }
    printf("]\n");

    bubble_sort(a, 5);

    printf("array: \n");
    printf("[");
    for (int i = 0; i < 5; ++i) {
        printf("%d, ", a[i]);
    }
    printf("]");
}

int main() {
    bubble_sort_tests();
    return 0;
}
