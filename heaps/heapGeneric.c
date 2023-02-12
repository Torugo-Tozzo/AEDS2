#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

int heap[MAX_ELEMENTS];
int n = 0;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insert(int x) {
    if (n == MAX_ELEMENTS) {
        printf("Heap overflow\n");
        return;
    }

    heap[n] = x;

    int i = n;
    int parent = (i - 1) / 2;

    while (i > 0 && heap[i] > heap[parent]) {
        swap(&heap[i], &heap[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }

    n++;
}

int delete_max() {
    if (n == 0) {
        printf("Heap underflow\n");
        return -1;
    }

    int max = heap[0];
    heap[0] = heap[n - 1];
    n--;

    int i = 0;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    while (left < n) {
        if (heap[left] > heap[i]) {
            largest = left;
        }

        if (right < n && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
            left = 2 * i + 1;
            right = 2 * i + 2;
        } else {
            break;
        }
    }

    return max;
}

void print_heap() {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insert(3);
    insert(2);
    insert(1);
    insert(15);
    insert(5);
    insert(4);
    insert(45);

    printf("Heap: ");
    print_heap();

    printf("Deleted: %d\n", delete_max());
    printf("Deleted: %d\n", delete_max());

    printf("Heap after deletions: ");
    print_heap();

    return 0;
}
