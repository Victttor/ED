#include <stdio.h>
#include <time.h>
#include <limits.h>

void mostra_vetor(int v[]);
void arquivo (int *num);
void intercala (int p, int q, int r, int v[]);
void mergesort (int p, int r, int v[]);


int main(int argc, char *argv[]) {
   // Calculate the time taken by take_enter()
	clock_t t;
	t = clock();
	printf("Timer starts\n");

   // o c√≥digo que executa seu algoritmo de ordena√ß√£o aqui (nao coloque a parte de pegar os dados do arquivo!)
	int num[101];
	arquivo (&num[0]);
	
	
	mergesort (0, 100 - 1, num);
	mostra_vetor(num);  
  
  

	printf("Timer ends \n");
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
	printf("The program took %f seconds to execute", time_taken);
   
   return 0;
}

void mostra_vetor(int v[]) {
	int i;
    printf ("{  %2d", v[0]);
	for (i = 1; i < 100; i++) {
    	printf (", %2d", v[i]);
	}

	printf ("}\n");
  
}

/* Intercala as seq¸Íncias v[p]..v[q-1] e v[q]..v[r] */
void intercala (int p, int q, int r, int v[]) {
	int i, j, k;
	int w[100];

	i = p; 
	j = q;
	k = 0;

	while (i < q && j <= r) {
		if (v[i] <= v[j])  
			w[k++] = v[i++];
    else  
		w[k++] = v[j++];
	}
  
	while (i < q)  
		w[k++] = v[i++];

	while (j <= r)  
		w[k++] = v[j++];

	for (i = p; i <= r; i++)  
		v[i] = w[i-p];
}

void mergesort (int p, int r, int v[]) {
	if (p < r) {
    	int q = (p + r)/2;
    	mergesort (p, q, v);
    	mergesort (q+1, r, v);
    	intercala (p, q+1, r, v);
    	mostra_vetor(v);
  }
}

void arquivo (int *num){

	int i, temp;

	FILE *file;
	file = fopen("input_100.txt", "r");

	
	for (i=0;i<100;i++){
		fscanf(file,"%d",&num[i]);
	
	}

	fclose(file);
}
