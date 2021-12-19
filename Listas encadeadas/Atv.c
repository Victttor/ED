#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct estoque{ /* estrutura duplamente auto-referenciada */
       
       int codigo;
       int qtd;
       char produto [15];
       
       struct estoque *ant, *prox; 

};

typedef struct estoque NODE; /* definição do tipo NODE a partir do tipo 'struct estoque' */
typedef NODE *NODEPNT; /* definição do tipo *NODEPNT a partir do tipo NODE */

/* insere um nó no início da lista */
void insere_no_inicio(NODEPNT *inicio, int codigo, int qtd, char produto){
     
     NODEPNT novo;
   
     
     
     novo = (NODEPNT) malloc(sizeof(NODE)); /* aloca memória para o novo nó */
     
     	printf("\nDigite um caracetere: ");
     	scanf("%d", &codigo);
    	printf("Nome do produto: ");
    	gets(produto);
   		printf("Quantidade em estoque: ");
    	scanf("%d",&qtd);
     
     if(novo == NULL) /* se não houver memória disponível */ 
         return;      /* sai da função */
     
     if(*inicio == NULL){    /* se a lista estivava vazia */
        
         novo->codigo = codigo; /* insere o valor no novo nó */
         novo->produto[15]=produto;
         novo->qtd=qtd;
         novo->prox = novo->ant = NULL; /* não há próximo nó nem nó ant, pois só há um nó */
         *inicio = novo; /* o novo nó é o primeiro da lista */
     }
     else{   /* se já havia nó na lista */
         novo->codigo = codigo; 
         novo->produto[15]=produto;
         novo->qtd=qtd; /* insere o valor no novo nó */
         novo->ant = NULL; /* não há nó ant */
         novo->prox = *inicio; /* o novo nó aponta para o que está no início */
         (*inicio)->ant = novo; /* o nó atual do início aponta para o novo nó */
         *inicio = novo; /* o novo nó passa a ser o primeiro da lista */
     }
}


/* remove um nó escolhido pelo usuário */
//int retira(NODEPNT *inicio, char valor){
//    
//    NODEPNT temporario, atual;
//    
//    if(*inicio == NULL) 
//        return 0; /* retorna 0 caso a lista esteja vazia */
//    
//    atual = *inicio; /* o nó atual é o do início */
//    
//    if((*inicio)->valor == valor) /* caso o no a ser retirado seja o do inicio */
//        *inicio = (*inicio)->prox; /* o nó inicial passa a ser o próximo da lista */
//    
//    while(atual != NULL && atual->valor != valor) /*se há nó e o valor do mesmo não é o valor que se quer retirar*/
//        atual = atual->prox; /*passa para o próximo*/
//    
//    if(atual == NULL)
//        return 0; /* retorna 0 se não encontrou o valor */
//    /* caso tenha encontrado */
//    else{
//        temporario = atual; /* temporario aponta para o nó encontrado */
//        
//        if(atual->ant != NULL)/* caso haja um nó ant ao enontrado*/
//            atual->ant->prox = atual->prox; /* faz o nó ant apontar para o nó posterior ao encontrado */
//        
//        if(atual->prox != NULL) /* caso haja um nó posterior ao enontrado*/
//            atual->prox->ant = atual->ant; /* faz o nó posterior apontar para o nó ant ao encontrado */
//        
//        free(temporario);/* remove o nó encontrado */
//    }
//    
//    return 1;
//}

/* deleta um nó apartir do início da lista */
//char elimina_no(NODEPNT *inicio){
//    
//    NODEPNT temporario;
//    char c;
//    
//    temporario = *inicio; /* nó do início passa a ser temporário */
//    c = (*inicio)->valor; /* pega o valor que estava no nó */
//    *inicio = (*inicio)->prox; /* o nó seguinte passa a ser o do início */
//    free(temporario); /* deleta o nó temporário */
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
//         while(lista->prox != NULL) /* enquanto não chegar no último nó ...*/
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
//    while(! esta_vazia(lista)){ /* retira todos os nós não apagados para liberar a memória */
//        printf("No %c retirado\n", elimina_no(&lista));
//    }
    printf("\nLista vazia\n");
    
//    getch();
    
    return 0;
}
