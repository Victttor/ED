#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct estoque{
	char nome;
	int qtd;
};

typedef struct pont *lista;

struct pont{
	struct pont *ant;
	struct estoque dados;
	struct pont *prox;
};
typedef struct pont elem;

lista *li;

void inserir (lista*li,struct pont,struct estoque);
void remover (lista*li,struct pont,struct estoque);
void buscar (lista*li,struct pont,struct estoque);

main()
{
	

    int op;
    while (1)
    {
    	printf("\n\n=================MENU==================\n\n");
    	setbuf(stdin,NULL);
    	printf("%d\n");
        printf("1.Inserir\n");
        printf("2.Remover\n");
		printf("3.Buscar\n");
        printf("4.Sair\n");
        printf("Selecione a opcao: ");
        scanf("%d", &op);
        setbuf(stdin,NULL);
        printf("\n=======================================\n\n");
        switch (op)
        {
            case 1:
            inserir();
            break;
//            case 2:
//            remover();
//            break;
            case 3:
            buscar();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Escolha incorreta \n");
            
            
        } 
    } 
} 

void inserir (lista*li,struct pont,struct estoque){
	
}


