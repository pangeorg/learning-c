#include <stdlib.h>
#include <stdio.h>

int linear_search(int value, int* a, int len){
    if (a == NULL) {
        return -1;
    }

    for (int i = 0; i < len; ++i) {
        if (a[i] == value) return i;
    }
    return -1;
}

int binary_search(int value, int *a, int len) {
    if (a == NULL) {
        return -1;
    }
    int i;
    int left = 0;
    int right = len - 1;
    do {
        i = (right + left) / 2;
        if (a[i] == value) {
            return i;
        }
        else if (value < a[i]) { 
            left += 1;
        }
        else if (value > a[i]) { 
            right += 1;
        }
    }
    while (right >= left);
    return -1;
}

void bubble_sort(int* a, int len) {
    int tmp;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (a[j + 1] < a[j]) {
                tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}
