#include <stdio.h>

void swap(int *, int *);

int main(void){
    // automatic storage duration
    // these variables exist until execution leaves the block in which they are defined
    int a = 21;
    int b = 17;

    swap(&a, &b);
    printf("main: a = %d, b = %d\n", a, b);
    return 0;
}

void swap(int *pa, int *pb){
    int t = *pa;
    *pa = *pb;
    *pb = t;
    return;
}