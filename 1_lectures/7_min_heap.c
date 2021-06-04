#include <stdlib.h>
#include <stdio.h>

/*
    heap tree struct
    make heap
    insert, remove
    shift up 
*/

#define MAX_SIZE 127 

// 1-1 print 
void show_heap(int *heap, int size){
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

void shift_down(int *heap, int i, int size){
    while(i < size){
        if(heap[i] > heap[2*i+1] && heap[2*i+1] < heap[2*i+2]){
            swap(&heap[i], &heap[2*i+1]);
            shift_down(heap, 2*i+1, size);
        } else if(heap[i] > heap[2*i+2] && heap[2*i+2] < heap[2*i+1]){
            swap(&heap[i], &heap[2*i+2]);
            shift_down(heap, 2*i+2, size);
        } else {
            return;
        }
        show_heap(heap, size);
    }
}

void sift_down2(int heap[], int index, int size)
{
    int min_index = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < size) {
        if(heap[left] < heap[min_index]) {
            min_index = left;
        }
    }

    if(right < size) {
        if(heap[right] < heap[min_index]) {
            min_index = right;
        }
    }

    if(min_index != index){
        swap(&heap[index], &heap[min_index]);
        sift_down2(heap, size, min_index);
        show_heap(heap, size);
    }
}


// 1-4 insert (int heap[], int *size, int val)
void insert(int *heap, int *size, int val){
    heap[*size] = val;
    *size = *size + 1;
    sift_up(heap, *size-1);
}

int* make_heap(int *arr, int size){
    int* out = (int*)malloc(sizeof(int) * MAX_SIZE);
    if(out == NULL){
        fprintf(stderr, "make_heap: fail malloc\n");
        exit(1);
    }
    int len = 0;
    for(int i = 0; i < size; i++){
        insert(out, &len, arr[i]);
        show_heap(out, len);
    }
    return out;
}

int main(){
    int size = 7;
    int arr[MAX_SIZE] = {1,13,3,5,9,11,10};
    shift_down(arr, 1, size);
    // sift_down2(arr, 1, size);
    show_heap(arr, size);

    
}