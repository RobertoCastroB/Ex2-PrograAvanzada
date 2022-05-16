#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void funcion(int a, int b);

void call_3_times(int a) {
    int i;

    for(i=0; i<3; i++) {
        printf("Proceso %d, iteracion %d\n", a, i);
        sleep(1);
    }
    exit(-1);
}

int main() {
    int i;
    if (!fork()) call_3_times(0);
    if (!fork()) call_3_times(1);
    if (!fork()) call_3_times(2);
}
