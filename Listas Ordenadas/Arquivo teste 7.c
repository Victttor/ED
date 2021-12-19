#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int vetor [100];
int i=0;

int main (){


FILE *file;
file = fopen("input_100.txt", "r");

while( ! feof(file)) {
fscanf(file,"%d",&vetor[i]);
printf("%d\n",vetor[i]);
}


return (0);
}
