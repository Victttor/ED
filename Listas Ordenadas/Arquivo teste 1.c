#include <stdio.h>
#include <stdlib.h>
int main()
{
   char c;
   int number[20], i;
   FILE *arq;


   arq = fopen("input_10.txt", "r"); // read mode

   if (arq  == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

//   printf("The contents of %s file are:\n", file_name);

   while((c = fgetc(arq)) != EOF)
		fscanf(arq,"%d",&number[i]);
      printf("%d", number[i]);

   fclose(arq);
   return 0;
}
