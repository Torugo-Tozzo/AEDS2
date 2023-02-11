#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

struct Heap
{
    int size;
    int elements[MAX_ELEMENTS];
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_down(struct Heap *heap, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heap->size && heap->elements[left] < heap->elements[index])
        smallest = left;

    if (right < heap->size && heap->elements[right] < heap->elements[smallest])
        smallest = right;

    if (smallest != index)
    {
        swap(&heap->elements[index], &heap->elements[smallest]);
        heapify_down(heap, smallest);
    }
}

void heapify_up(struct Heap *heap, int index)
{
    int parent = (index - 1) / 2;

    if (index && heap->elements[index] < heap->elements[parent])
    {
        swap(&heap->elements[index], &heap->elements[parent]);
        heapify_up(heap, parent);
    }
}

void insert(struct Heap *heap, int element)
{
    heap->elements[heap->size] = element;
    heap->size++;

    heapify_up(heap, heap->size - 1);
}

int extract_min(struct Heap *heap)
{
    int min = heap->elements[0];

    heap->elements[0] = heap->elements[heap->size - 1];
    heap->size--;

    heapify_down(heap, 0);

    return min;
}

void print(struct Heap *heap)
{
    int i;
    for (i = 0; i < heap->size; i++)
        printf("%d ", heap->elements[i]);
}

int main()
{
    struct Heap *heap = (struct Heap *)malloc(sizeof(struct Heap));
    heap->size = 0;

    insert(heap, 3);
    insert(heap, 2);
    insert(heap, 1);

    printf("Heap: ");
    print(heap);

    printf("\nExtracted min: %d", extract_min(heap));

    printf("\nHeap after extraction: ");
    print(heap);

    return 0;
}