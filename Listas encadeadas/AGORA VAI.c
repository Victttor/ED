#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct estoque {
	int codigo;
    char produto[15];
    int qtd;
    struct estoque* prox;
} Estoque;

//Declaração de funções.
Estoque* inserir(Estoque* ini);
void mostrar(Estoque* ini);
Estoque* remover_item(Estoque* ini);
void alterar_item(Estoque* ini);
void limpa_linha(void); // função para limpar a sujeira no buffer

int main() {

//Declaração de variáveis
    Estoque *ini= NULL;
    int op;

//Artifício para repetir o programa.
    while(op=1)
    {

//Menu de opções
        printf("\n\n=================MENU==================\n\n");
    	setbuf(stdin,NULL);
    	printf("%d\n");
        printf("1.Inserir\n");
        printf("2.Mostrar\n");
        printf("3.Remover\n");
        printf("4.Alterar\n");
        printf("5.Sair\n");
        printf("Selecione a opcao: ");
        scanf("%d", &op);
        setbuf(stdin,NULL);
        printf("\n=======================================\n\n");

//Menu de opções
        switch(op)
        {
        case 1:
            fflush(stdin);
            inserir(ini);
//            system("cls");
            break;
        case 2:
            mostrar(ini);
//            system("cls");
            break;
        case 3:
            remover_item(ini);
//            system("cls");
            break;
        case 4:
			fflush(stdin);
            alterar_item(ini);
//            system("cls");
            break;
        case 5:
			exit(0);
            break;
        default:
//Artifício que previne a situação de um usuário qualquer, digitar uma opcão inexistente no menu.
            break;
        }
    }
}

void limpa_linha() {
    scanf("%*[^\n]");
    scanf("%*c");
}

Estoque* inserir(Estoque* ini) {

    Estoque item;
    Estoque *atual = ini;
    char identificador = 'F';

    //Lendo as informações do cliente.
    printf("  Numero da Conta: ");
    scanf("%d", &item.codigo);
    limpa_linha();
    printf ("\n");
    printf("  Nome: ");
    fgets(item.produto, 15, stdin);
    printf ("\n");
    printf("  Quantidade: ");
    scanf("%d", &item.qtd);
    limpa_linha();

    printf ("\n");

//    Verificando se o cadastro já existe.
    for (atual = ini; atual != NULL; atual = atual->prox) {
        if (atual->codigo == item.codigo) {
            identificador = 'V';
            break;
        }
    }

    if ( identificador != 'V' && (strlen(item.produto) != 1)) {

        //Alocando os espaços e guardando as informações do cliente.
        Estoque* Nproduto = malloc (sizeof(Estoque));
        strcpy(Nproduto->produto, item.produto);
        Nproduto->qtd = item.qtd;
        Nproduto->codigo = item.codigo;
        Nproduto->prox = ini;
        printf("  Cadastro realizado com sucesso.");
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return Nproduto;
    } else {
        printf("  Cadastro invalido!");
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return ini;
    }
}



void mostrar(Estoque* ini) {

    Estoque* node;//Ponteiro para percorrer a lista sem perder a referência do ini elemento da lista.

    //Imprimindo os restaurantes da lista, e suas repectivas informações.
    if (ini != NULL) {
    	printf("Códgio do Produto: %d", ini->codigo);
//    	scanf("%d", node->codigo);
//        printf("\n  Nome do produto: ");
//        printf("%s", node->produto);
//        printf("  Quantidade armazenada: ");
//        printf("%d", node->qtd);
//        printf("\n\n");
    }
    if ( ini == NULL)
        printf("  Nenhum Item Cadastrado.");
//    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}

Estoque* remover_item(Estoque* ini) {

    Estoque *ant = NULL;//Ponteiro para saber o elemento anterior ao elemento node da estoque.
    Estoque *node = ini;//Ponteiro para percorrer a lista sem perder o ini elemento da lista.
    int cod;

//Requisitando e lendo o código do item a ser excluído.
    printf("  Codigo do item a ser excluido: ");
    scanf("%d",&cod);
//    limpa_linha();

//Procurando o item na estoque.
    while( node != NULL && node->codigo != cod) {
        ant = node;
        node = node->prox;
    }

//Mensagem caso o item não seja encontrado.
    if (node == NULL) {
        printf("\n  Produto nao encontrado.");
//        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return ini;
    }

//Excluindo o ini item da lista.
    if (ant == NULL) {
        printf("\n  Conteudo excluido com sucesso.");
        ini= node->prox;
//Excluindo um item do meio da estoque.
    } else {
        printf("\n  Conteudo excluido com sucesso.");
        ant->prox= node->prox;
    }

//Desalocando o espaço da memória.
    free(node);
//    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
    return ini;
}

//Função para alterar cadastros.
void alterar_item(Estoque *ini) {

	int cod_novo;
    char novo_nome [15];
    int qdt01;
    Estoque *node = ini;
    int f;

    //Requisitando e lendo o código do item a ser alterado.
    printf("  Codigo do item a ser alterado: ");
    scanf("%d", &cod_novo);
//    limpa_linha();

    f = 0;
    // Busca pelo cadastro
    for (node = ini; node != NULL; node = node->prox) {
        if (node->produto == novo_nome) {
            f = 1;
            printf("\n  Novo nome: ");
            fgets(novo_nome, 15, stdin);
            strcpy(node->produto, novo_nome);
            printf("\n  Nova Quantidade: ");
            scanf("%d", qdt01);
//            limpa_linha();
            printf ("\n");
            node->qtd = qdt01;
            printf("Dados alterados com sucesso!");
        }
    }
    if (!f) {
        printf("\nCliente nao encontrado!");
    }

//    printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}
