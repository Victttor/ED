#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# define TAM 10
# define PG 10

void enqueue();
void mostrar();
int s=0;


struct fila{
	int rga;
	int pag;
	int ini;
	int ult;
	int cont;
}fila;

//struct pilha{
//	int top;
//	
//}pilha;

FILE *pedidos;

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
		printf("3.Exibir\n");
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
            case 2:
            remover();
            break;
            case 3:
            exibir();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Escolha incorreta \n");
            
            
        } 
    } 
} 

void enqueue()
{
	pedidos = fopen("pedidos.csv", "a"); 
	if (pedidos == NULL){
    	printf("ERRO! O arquivo nao foi aberto!\n");
	}else{
//		int *v,b;

		if (fila.ult == TAM - 1)
			printf("Excesso de pedidos\n");
    		else
    			{
				if (fila.ini == - 1)
       
        		fila.ini = 0;
        		printf("informe o rga: ");
				scanf ("%d", &fila.rga);
				setbuf(stdin,NULL);
        		printf("Informe a quantidade das folhas: ");
        		scanf("%d", &fila.pag);
        		setbuf(stdin,NULL);

        		fila.cont++;
        		fwrite(&fila, sizeof(fila), 1, pedidos);
        		
    		}	
	}
	fclose(pedidos);
	s++;
}





void mostrar()
{
    int ctd, i;
    pedidos = fopen("pedidos.csv", "r");
	printf("\n===========DADOS REGISTRADOS===========\n\n\n");
	printf("RGA,PAGINAS\n");
	
    
    if (fila.ini ==-1)
		printf("Nao ha pedidos \n");

    while( fread(&fila, sizeof(fila), 1, pedidos) == 1){

		printf("%d,",fila.rga);
		printf("%d\n",fila.pag);
		i++;
		}
//	}
	fclose(pedidos);
    
//    if (ini == - 1)
//        printf("Nao ha pedidos \n");
//    else
//    {
//        printf("Registro: \n");
//        for ( i = ini; i <= ult; i++)
//            printf("%d ", fila[i]);
//        printf("\n");
//    }
} 












