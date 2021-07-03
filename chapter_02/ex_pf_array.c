#include <stdio.h>

void integer(void){
    puts("integer");
}

void floating_point(void){
    puts("floating_point");
}

void double_point(void){
    puts("double");
}

int main(void){
    void (*arr[3])(void);
    arr[0] = integer;
    arr[1] = floating_point;
    arr[2] = double_point;

    for (int i = 0; i < 3; i++){
        arr[i]();
    }

    return 0;
}