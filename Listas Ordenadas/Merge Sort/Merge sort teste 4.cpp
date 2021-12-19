#include <stdio.h>
#include <limits.h>



void mostra_vetor(int v[]) {
  int i, j;
  for (j = 0; j <= 4* 10; j++) 
      printf("-");    
  printf("\n");
  printf ("{  %2d", v[0]);
  
  for (i = 1; i < 10; i++) {
    printf (", %2d", v[i]);
  }

  printf ("}\n");
  
}

/* Intercala as seqüências v[p]..v[q-1] e v[q]..v[r] */
void intercala (int p, int q, int r, int v[]) {
  int i, j, k;
  int w[10];

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
	file = fopen("input_10.txt", "r");

	
	for (i=0;i<10;i++){
		fscanf(file,"%d",&num[i]);
	
		}

	fclose(file);
}

int main (int argc, char *argv[]) {
  
  	int num[11];
	arquivo (&num[0]);

  	mostra_vetor(num);
 	mergesort (0, 10 - 1, num);
  	mostra_vetor(num);  
  
  return 0;
}
