#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
int c;
FILE *file;
file = fopen("input_10.txt", "r");
if (file) {
    while ((c = getc(file)) != EOF)
        putchar(c);
    fclose(file);
}

return (0);
}
