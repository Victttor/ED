#include <stdio.h>
#include <string.h>
#include <stdlib.h>

   
void organizar (int *num);
   

int main(int argc, char *argv[]){
	
	int i;
	int num[100001];
	organizar (&num[0]);
	
	

   printf("Order of Sorted elements: ");
   for(i=0;i<100000;i++)
		printf(" %d",num[i]);
    

   return 0;
}

void organizar (int *num){
	int j, temp;
	int i;
	
	FILE *file;
	file = fopen("input_100000.txt", "r");

	
	for (i=0;i<100000;i++){
		fscanf(file,"%d",&num[i]);
		}
	fclose(file);

 

//    Codigo do insertion sort
   for(i=1;i<100000;i++){
      temp=num[i];
      j=i-1;
      while((temp<num[j])&&(j>=0)){
         num[j+1]=num[j];
         j=j-1;
      }
      num[j+1]=temp;
   }


	
}
