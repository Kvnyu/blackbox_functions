#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int index;
    int value;
} Tuple;

int cmpfunc (const void* a, const void* b){
    Tuple* aTuple = (Tuple*) a;
    Tuple* bTuple = (Tuple*) b;
    return aTuple->value - bTuple->value;
}

// personal notes:
// median doesn't know sizeof int* here, sizeof only knows in the context where the array was declared
void median(int nums[], int length, int* out) {
    Tuple temp[length];

    for (int i=0; i < length; i++){
        temp[i].index = i;
        temp[i].value = nums[i];
    }

    qsort(temp, length, sizeof(Tuple), cmpfunc);
    Tuple resTuple = temp[(length/2)];

    out[0] = resTuple.value;
    out[1] = resTuple.index;
};

void run_function(int* in, int in_length, int* out, int out_length) {
    median(in, in_length, out);
}

int main()
{
    // int arr[] = {1,1,1,3,3,3,2};
    int arr[] = {3,-2,2};
    int out[2];
    median(arr, 4, out);
    printf("Value: %d\t Index: %d\n", out[0], out[1]);
    return 0;
}