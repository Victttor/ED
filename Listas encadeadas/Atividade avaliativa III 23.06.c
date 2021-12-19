#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct estoque {
    int codigo;
    char produto[50];
    int qtd;
    struct estoque* prox;
} Estoque;

//Funções
Estoque* inserir(Estoque* ini); //pelo que percebi em C, quando faz alguma locação dos nós, se colocar "void", o bicho não funciona bem
void buscar(Estoque *ini);
void mostrar_tudo(Estoque* ini);
Estoque* excluir(Estoque* ini);
void alterar(Estoque* ini); // aqui por exemplo, seria apenas modificação dos dados do nó, funcionado em Void

int main() {
	
	//variaveis da lista
    Estoque *ini= NULL; //inicio do programa, deixando a lista zerada
    int op;
    
    while(op=1)
    {

        printf("\n\n===============ESTOQUE==================\n\n");
        printf("             1.Inserir\n");
        printf("             2.Buscar\n");
        printf("             3.Mostrar Tudo\n");
        printf("             4.Remover\n");
        printf("             5.Alterar\n");
        printf("             6.Sair\n");
        printf("\n=======================================\n\n");
        printf("Selecione a opcao: ");
        scanf("%d", &op);
        printf("\n=======================================\n\n");

        switch(op)
        {
        case 1:
            fflush(stdin); //limpezinha basica do cache
            ini= inserir(ini); //ponteiro apontado ao inicio
            break;
        case 2:
        	buscar(ini);
        	break;
        case 3:	
            mostrar_tudo(ini);
            break;
        case 4:
            ini= excluir(ini);
            break;
        case 5:
            alterar(ini);
            break;
        case 6:
			printf("\n PROGRAMA ENCERRADO! \n\n");
			exit(0);
			break;
        default:
            break;
        }
    }
}

Estoque* inserir(Estoque* ini) {
	
	//variaveis auxiliares da lista
	Estoque item;
    Estoque *node = ini; //apontando o node no inicio da lista
    char AUX = 'f'; //Auxiliar para verificação se há ou não produto existente
	
	//leitura dos dados
    printf("Codigo: ");
    scanf("%d", &item.codigo);
    printf("Produto: ");
    scanf("%s", item.produto);
    printf("Quantidade: ");
    scanf("%d", &item.qtd);

    printf ("\n");

	//ira verificar se o codigo do produto existe
    for (node = ini; node != NULL; node = node->prox) {
        if (node->codigo == item.codigo) {
            AUX = 'v';
            break;
        }
    }
	//	se o codigo existir, ele ira verificar o auxiliar e se o comprimento do nome do produto for diferente de 1
    if ( AUX != 'v' && (strlen(item.produto) != 1)) {
	// verificando a lista e alocando os dados em sua memoria
        Estoque* Nproduto = malloc (sizeof(Estoque));
        strcpy(Nproduto->produto, item.produto); //aqui tive que usar um strcpy pois apenas apontar não deu certo, devido ser caracter com array
        Nproduto->qtd = item.qtd;
        Nproduto->codigo = item.codigo;
        Nproduto->prox = ini; //após os dados serem armazenados na struct, eles são registrados no proximo nó do inicio
        printf("\nItem registrado com sucesso.");
        return Nproduto;
    } else {
        printf("\nRegistro invalido!"); // se o auxiliar manter "f", informara que o registro é invalido
        return ini;
	}
}

void buscar(Estoque *ini) {
	//Funções auxiliares
    int cod_01;
    Estoque *node = ini; //node apontando para o inicio
    int aux; //Auxiliar para verificação se há ou não produto existente

    printf("Codigo do item a ser buscado: ");
    scanf("%d", &cod_01);

    aux = 0;
    for (node = ini; node != NULL; node = node->prox) { //se o nó no inico for diferente de NULL, ele estará apontando para o proximo nó
        if (node->codigo == cod_01) { //se o codigo do nó for semalhante a variavel auxiliar, entra no laço para mostrar os resultados
			printf("\nCodigo: ");
        	printf("%d\n", node->codigo);
        	printf("Nome do Produto: ");
        	printf("%s\n", node->produto);
        	printf("Quantidade: ");
        	printf("%d\n", node->qtd);
        	
        	aux = 1;
        }
    }
    if (aux==0) {
        printf("\nProduto nao encontrado!");
    }

}

void mostrar_tudo(Estoque* ini) { //Adicionei esse bloco de comando apenas para facilitar na pesquisa, mostrando todos os dados registrados

    Estoque* node;

    for (node = ini ; node != NULL; node = node->prox) { //se baseia no codigo anterior o de buscar, só que ao inves de buscar apenas um, mostrará todos
        printf("\nCodigo: ");
        printf("%d\n", node->codigo);
        printf("Nome do Produto: ");
        printf("%s\n", node->produto);
        printf("Quantidade: ");
        printf("%d\n", node->qtd);

		printf ("\n");
    }
    if ( ini == NULL) //se não houver produtos registrados, voltará nula.
        printf("Nenhum Produto Registrado.");

}

Estoque* excluir(Estoque* ini) {//já que os itens não tem uma ordem determinada, fica mais facil de se encontrar e excluir um arquivo um dado de um nó

    Estoque *ant = NULL; //ponteiro para a posição anterior
    Estoque *node = ini; //ponteiro do nó inicial
    int aux = 0; // auxiliar

    printf("\nCodigo do item a ser excluido: ");
    scanf("%d",&aux);

	//laço que irá fazer uma procura na lista
    while( node != NULL && node->codigo != aux) { //Enquanto o nó for diferente de Null e o nó for diferente de auxiliar
        ant = node; //o anterior será igual ao node inicial
        node = node->prox; //e o node apontará para o próximo nó, até achar a igualdade do aux
    }

	//Se o node inicial já começar sendo null (nada adicionado), já dará essa mensagem
    if (node == NULL) {
        printf("\nProduto nao encontrado.");
        return ini;
    }

	//Se o anterior se manter NULL, ou seja, se na função while, o codigo for igual ao aux...
    if (ant == NULL) {
        printf("\nConteudo excluido com sucesso.");
        ini= node->prox; //o nó inicial será o proximo nó, removendo o dado anterior
	//Caso o dado náo estiver no inicio da lista, será removido no meio dela.
    } else {
        printf("\nConteudo excluido com sucesso.");
        ant->prox= node->prox;
    }

    free(node); //função que libera o node.
    return ini;
}



void alterar(Estoque *ini) { // linha de comandos semelhante a de Buscar, só que dessa vez, ao inves de apenas mostrar, ele irá subtituir os dados 

	//funções auxiliares
    int cod_02;
    char Npdt[50];
    int Nqtd;
    int aux;
    Estoque *node = ini;

    //código para ser alterado o nome e a quantidade
    printf("\nCodigo do item a ser alterado: ");
    scanf("%d", &cod_02);

    aux = 0;
    // Busca pelo cadastro
    for (node = ini; node != NULL; node = node->prox) { //se o nó no inico for diferente de NULL, ele estará apontando para o proximo nó
        if (node->codigo == cod_02) { //se o codigo do nó for semalhante a variavel auxiliar, entra no laço realizar a troca de dados
            printf("\nNovo nome: ");
			scanf("%s", Npdt);
            strcpy(node->produto, Npdt);
            printf("Nova Quantidade: ");
            scanf("%d", &Nqtd);
            node->qtd = Nqtd;
            printf("\nDados alterados com sucesso!");
            
            aux = 1;
        }
    }
    if (aux==0) {
        printf("\nProduto nao encontrado!");
    }


}
