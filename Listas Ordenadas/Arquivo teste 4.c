#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<string.h>

int abrir_arquivo(int *num){
    FILE *file;

    file=fopen("input_10.txt", "r");
    //se o arquivo for encontrado

    if(file==NULL){
        printf("erro");
    }
    while((fgetc(file))!=NULL)
        printf("%d",&num);

    fclose(file);

}

int main(){
    int palavraforca;
    abrir_arquivo(&palavraforca);
    return 0;
}
