#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 10

 int arr[11];// array to be sorted

void arquivo (int *num);

int merge(int arr[],int l,int m,int h)
{
int arr1[1000],arr2[1000]; // Two temporary arrays to hold the two arrays to be merged

int n1,n2,i,j,k;
n1=m-l+1;
n2=h-m;

for(i=0; i<n1; i++)
arr1[i]=arr[l+i];
for(j=0; j<n2; j++)
arr2[j]=arr[m+j+1];

arr1[i]=9999; // To mark the end of each temporary array
arr2[j]=9999;

i=0;
j=0;
for(k=l; k<=h; k++) { //process of combining two sorted arrays
if(arr1[i]<=arr2[j])
arr[k]=arr1[i++];
else
arr[k]=arr2[j++];
}
return 0;
}

int merge_sort(int arr[],int low,int high)
{
int mid;
if(low<high) {
mid=(low+high)/2;
// Divide and Conquer
merge_sort(arr,low,mid);
merge_sort(arr,mid+1,high);
// Combine
merge(arr,low,mid,high);
}

return 0;
}

void arquivo (int *num){

	int i, temp;

	FILE *file;
	file = fopen("input_10.txt", "r");

	
	for (i=0;i<10;i++){
		fscanf(file,"%d",&temp);
		num[i]=temp;
		
		}

	fclose(file);
}

int main(int argc, char *argv[])
{
	
	int num[11];
	arquivo (&num[0]);
	int n,i;
	


//printf("Enter the size of array\n"); // input the elements
//scanf("%d",&n);
//printf("Enter the elements:");
	for(i=0; i<10; i++)
		num[i]=arr[i];
		printf("%d",num[i]);

merge_sort(arr,0,10-1); // sort the array

printf("Sorted array:"); // print sorted array
for(i=0; i<10; i++)
printf("%d ",arr[i]);

return 0;
}
