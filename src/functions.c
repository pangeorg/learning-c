#include <stdio.h>
#include <stdlib.h>

int linear_search(int value, int *a, int len) {
  if (a == NULL) {
    return -1;
  }

  for (int i = 0; i < len; ++i) {
    if (a[i] == value)
      return i;
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
    } else if (value < a[i]) {
      left += 1;
    } else if (value > a[i]) {
      right += 1;
    }
  } while (right >= left);
  return -1;
}

void bubble_sort(int *a, int len) {
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

/*
 * Here we have an array lo to hi e.g.
 * [8, 7, 3, 4, 5]
 * if an item is smaller than the pivot value,
 * it is placed at idx, which starts at lo and is incremented
 */
static int quick_sort_partition(int *a, int lo, int hi) {
  int pivot = a[hi];
  int idx = lo - 1;

  for (int i = lo; i < hi; ++i) {
    idx++;
    if (a[i] <= pivot) {
      int tmp = a[i];
      a[i] = a[idx];
      a[idx] = tmp;
    }
  }

  idx++;
  a[hi] = a[idx];
  a[idx] = pivot;
  return idx;
}

static void qs(int* a, int lo, int hi) {
  if (lo >= hi) {
    return;
  }
  int pivotIdx = quick_sort_partition(a, lo, hi);
  qs(a, lo, pivotIdx - 1);
  qs(a, pivotIdx + 1, hi);
}

void quick_sort(int *a, int len) { quick_sort_partition(a, 0, len - 1); }
