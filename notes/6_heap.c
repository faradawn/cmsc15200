#include <stdlib.h>
#include <stdio.h>


#define MAX_SIZE 127

// 1-1 print 
void show_heap(int heap[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// 1-2 swap
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 1-3 sift_up (heap, size, index)
void sift_up(int heap[], int i){
    while(i > 0){
        if(heap[i] < heap[(i-1)/2]){
            swap(&heap[i], &heap[(i-1)/2]);
            sift_up(heap, (i-1)/2);            
        } else{
            return;
        }
    }
}

// 1-4 sift_down

// 1-5 build heap

// 1-4 insert (int heap[], int *size, int val)
void insert(int heap[], int *size, int val){
    heap[*size] = val;
    *size = *size + 1;
    sift_up(heap, *size-1);
}

int main(){
    int size = 8;
    int heap[MAX_SIZE] = {1,4,3,5,8,6,7,9};
    show_heap(heap, size);
    // insert 2
    insert(heap, &size, 2);
    show_heap(heap, size);

    // build heap
    // int b[MAX_SIZE] = {12,11,13,2,5,6,7,4};
    // build_heap(b, heap, size);
    // show_heap(heap, size);
}