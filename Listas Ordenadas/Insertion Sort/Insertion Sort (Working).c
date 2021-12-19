#include <stdio.h>
#include <time.h>

void arquivo (int *num);


main(int argc, char *argv[]) {
	int i;
	int num[101];
	arquivo (&num[0]);
	
   // Calculate the time taken by take_enter()
   clock_t t;
   t = clock();
   printf("Timer starts\n");

   // o cÃ³digo que executa seu algoritmo de ordenaÃ§Ã£o aqui (nao coloque a parte de pegar os dados do arquivo!)
	int j, temp;
	for(i=1;i<100;i++){ //iniciando o laço
      temp=num[i]; //armazena o auxiliar no i
      j=i-1; // j ssendo a posiçao anterior de i
      while((temp<num[j])&&(j>=0)){ //enquanto o j for maior que o auxiliar e maior ou igual a 0...
         num[j+1]=num[j]; //ele passará seu vizinho do lado esquerdo para a direita, caso ele for maior
         j=j-1; //e irá uma posição para a esquerda;
         // caso o temp ficar maior que o num[j], o laço será pulado
      }
      num[j+1]=temp; // e o conteudo é armazenado no auxiliar, fazendo a troca assim que o laço repetir
   }
   
   printf("Order of Sorted elements: ");
   for(i=0;i<100;i++)
		printf(" %d",num[i]);
		

   printf("\n\nTimer ends \n");
   t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
   printf("The program took %f seconds to execute", time_taken);
   
   return 0;
}

void arquivo (int *num){

	int i;

	FILE *file;
	file = fopen("input_100.txt", "r");

	
	for (i=0;i<100;i++){
		fscanf(file,"%d",&num[i]);
		}
	fclose(file);
}
