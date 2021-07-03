#include <stdio.h>

static unsigned int counter = 0;

void increment(void){
    counter++;
    printf("%d ", counter);
}

unsigned int retrieve(void){
    return counter;
}


int main(void){
    for (int i = 0; i < 5; i++){
        increment();
    }
    puts("");
    printf("counter: %d\n", retrieve());
    return 0;
}

