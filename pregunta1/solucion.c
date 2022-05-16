#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main() {
    int linea,x;
    char data[51][80];
    srandom(getpid());
    FILE * archivo = fopen("sayings.txt","r");
    x=80;
    for (int i = 0; i <= x ; i++){
        fgets(data[linea],80,archivo);
        linea++;
    }
    printf("%s\n",data[random()%51]);
 exit(0);
}
