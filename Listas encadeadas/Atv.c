#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct estoque{ /* estrutura duplamente auto-referenciada */
       
       int codigo;
       int qtd;
       char produto [15];
       
       struct estoque *ant, *prox; 

};

typedef struct estoque NODE; /* defini��o do tipo NODE a partir do tipo 'struct estoque' */
typedef NODE *NODEPNT; /* defini��o do tipo *NODEPNT a partir do tipo NODE */

/* insere um n� no in�cio da lista */
void insere_no_inicio(NODEPNT *inicio, int codigo, int qtd, char produto){
     
     NODEPNT novo;
   
     
     
     novo = (NODEPNT) malloc(sizeof(NODE)); /* aloca mem�ria para o novo n� */
     
     	printf("\nDigite um caracetere: ");
     	scanf("%d", &codigo);
    	printf("Nome do produto: ");
    	gets(produto);
   		printf("Quantidade em estoque: ");
    	scanf("%d",&qtd);
     
     if(novo == NULL) /* se n�o houver mem�ria dispon�vel */ 
         return;      /* sai da fun��o */
     
     if(*inicio == NULL){    /* se a lista estivava vazia */
        
         novo->codigo = codigo; /* insere o valor no novo n� */
         novo->produto[15]=produto;
         novo->qtd=qtd;
         novo->prox = novo->ant = NULL; /* n�o h� pr�ximo n� nem n� ant, pois s� h� um n� */
         *inicio = novo; /* o novo n� � o primeiro da lista */
     }
     else{   /* se j� havia n� na lista */
         novo->codigo = codigo; 
         novo->produto[15]=produto;
         novo->qtd=qtd; /* insere o valor no novo n� */
         novo->ant = NULL; /* n�o h� n� ant */
         novo->prox = *inicio; /* o novo n� aponta para o que est� no in�cio */
         (*inicio)->ant = novo; /* o n� atual do in�cio aponta para o novo n� */
         *inicio = novo; /* o novo n� passa a ser o primeiro da lista */
     }
}


/* remove um n� escolhido pelo usu�rio */
//int retira(NODEPNT *inicio, char valor){
//    
//    NODEPNT temporario, atual;
//    
//    if(*inicio == NULL) 
//        return 0; /* retorna 0 caso a lista esteja vazia */
//    
//    atual = *inicio; /* o n� atual � o do in�cio */
//    
//    if((*inicio)->valor == valor) /* caso o no a ser retirado seja o do inicio */
//        *inicio = (*inicio)->prox; /* o n� inicial passa a ser o pr�ximo da lista */
//    
//    while(atual != NULL && atual->valor != valor) /*se h� n� e o valor do mesmo n�o � o valor que se quer retirar*/
//        atual = atual->prox; /*passa para o pr�ximo*/
//    
//    if(atual == NULL)
//        return 0; /* retorna 0 se n�o encontrou o valor */
//    /* caso tenha encontrado */
//    else{
//        temporario = atual; /* temporario aponta para o n� encontrado */
//        
//        if(atual->ant != NULL)/* caso haja um n� ant ao enontrado*/
//            atual->ant->prox = atual->prox; /* faz o n� ant apontar para o n� posterior ao encontrado */
//        
//        if(atual->prox != NULL) /* caso haja um n� posterior ao enontrado*/
//            atual->prox->ant = atual->ant; /* faz o n� posterior apontar para o n� ant ao encontrado */
//        
//        free(temporario);/* remove o n� encontrado */
//    }
//    
//    return 1;
//}

/* deleta um n� apartir do in�cio da lista */
//char elimina_no(NODEPNT *inicio){
//    
//    NODEPNT temporario;
//    char c;
//    
//    temporario = *inicio; /* n� do in�cio passa a ser tempor�rio */
//    c = (*inicio)->valor; /* pega o valor que estava no n� */
//    *inicio = (*inicio)->prox; /* o n� seguinte passa a ser o do in�cio */
//    free(temporario); /* deleta o n� tempor�rio */
//    
//    return c;
//}

int esta_vazia(NODEPNT lista){
    
    return lista == NULL;
    
}

void imprime_lista_ordem_direta(NODEPNT lista){
     
     if(esta_vazia(lista))
         printf("\n\nA lista esta vazia.\n\n");
     else{
         printf("\nA lista eh:\n\n");
         while(lista != NULL){
             printf(" %c", lista->codigo);
             printf(" %c", lista->produto);
        	 printf(" %c", lista->qtd);
             lista = lista->prox;
         }
     }
}

//void imprime_lista_ordem_inversa(NODEPNT lista){
//     
//     if(esta_vazia(lista))
//         printf("\n\nA lista esta vazia.\n\n");
//     else{
//         while(lista->prox != NULL) /* enquanto n�o chegar no �ltimo n� ...*/
//             lista = lista->prox;   /* ... percorre a lista */
//             
//         printf("\nA lista eh:\n\n");
//         while(lista != NULL){
//             printf(" %c", lista->valor);
//             lista = lista->ant;
//         }
//         
//     }
//}

void menu(){
     
     printf("     <------> OPERACOES BASICAS EM UMA LISTA DUPLAMENTE ENCADEADA <------>\n\n");
     printf("\n\n\t\t\t\t  OPCOES\n\n");
     printf("\t\t1 - Inserir um elemento no inicio da lista\n");
     printf("\t\t2 - Inserir um elemento no final da lista\n");
     printf("\t\t3 - Remover um elemento da lista\n");
     printf("\t\t4 - Imprimir a lista na ordem direta\n");
     printf("\t\t5 - Imprimir a lista na ordem inversa\n");
     printf("\t\t6 - sair\n\n");
     
}

int main(){
    
    NODEPNT lista = NULL;
    int opcao;
    int codigo;
    int qtd;
    char produto;

    
    menu();
    printf("Escolha uma das opcoes: ");
    scanf("%d", &opcao);
    
    while(opcao != 6){
        
        switch(opcao){
            
            case 1:
                 insere_no_inicio(&lista, codigo, qtd, produto);
                 getch();
                 system("cls");
                 break;
            
//            case 2:
//                 printf("\nDigite um caracetere: ");
//                 scanf("\n%C", &valor);
//                 insere_no_final(&lista, valor);
//                 system("cls");
//                 break;
            
//            case 3:
//                 printf("\nDigite o valor a ser retirado: ");
//                 scanf("\n%c", &valor);
//                 if(! retira(&lista, valor)){
//                     printf("\nNo inexistente!\n\n");
//                     getch();
//                 }
//                 system("cls");
//                 break;
            
            case 4:
                 imprime_lista_ordem_direta(lista);
                 getch();
                 system("cls");
                 break;
            
//            case 5:
//                 imprime_lista_ordem_inversa(lista);
//                 getch();
//                 system("cls");
//                 break;
            
            default:
                 printf("\nOpcao invalida!!!\n\n");
                 getch();
                 system("cls");
                 break;
        }
        menu();
        printf("Escolha uma das opcoes: ");
        scanf("%d", &opcao);
    }
//    printf("\nLimpando lista ...\n\n");
//    while(! esta_vazia(lista)){ /* retira todos os n�s n�o apagados para liberar a mem�ria */
//        printf("No %c retirado\n", elimina_no(&lista));
//    }
    printf("\nLista vazia\n");
    
//    getch();
    
    return 0;
}
