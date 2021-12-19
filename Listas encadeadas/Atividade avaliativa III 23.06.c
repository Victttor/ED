#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct estoque {
    int codigo;
    char produto[50];
    int qtd;
    struct estoque* prox;
} Estoque;

//Fun��es
Estoque* inserir(Estoque* ini); //pelo que percebi em C, quando faz alguma loca��o dos n�s, se colocar "void", o bicho n�o funciona bem
void buscar(Estoque *ini);
void mostrar_tudo(Estoque* ini);
Estoque* excluir(Estoque* ini);
void alterar(Estoque* ini); // aqui por exemplo, seria apenas modifica��o dos dados do n�, funcionado em Void

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
    char AUX = 'f'; //Auxiliar para verifica��o se h� ou n�o produto existente
	
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
        strcpy(Nproduto->produto, item.produto); //aqui tive que usar um strcpy pois apenas apontar n�o deu certo, devido ser caracter com array
        Nproduto->qtd = item.qtd;
        Nproduto->codigo = item.codigo;
        Nproduto->prox = ini; //ap�s os dados serem armazenados na struct, eles s�o registrados no proximo n� do inicio
        printf("\nItem registrado com sucesso.");
        return Nproduto;
    } else {
        printf("\nRegistro invalido!"); // se o auxiliar manter "f", informara que o registro � invalido
        return ini;
	}
}

void buscar(Estoque *ini) {
	//Fun��es auxiliares
    int cod_01;
    Estoque *node = ini; //node apontando para o inicio
    int aux; //Auxiliar para verifica��o se h� ou n�o produto existente

    printf("Codigo do item a ser buscado: ");
    scanf("%d", &cod_01);

    aux = 0;
    for (node = ini; node != NULL; node = node->prox) { //se o n� no inico for diferente de NULL, ele estar� apontando para o proximo n�
        if (node->codigo == cod_01) { //se o codigo do n� for semalhante a variavel auxiliar, entra no la�o para mostrar os resultados
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

    for (node = ini ; node != NULL; node = node->prox) { //se baseia no codigo anterior o de buscar, s� que ao inves de buscar apenas um, mostrar� todos
        printf("\nCodigo: ");
        printf("%d\n", node->codigo);
        printf("Nome do Produto: ");
        printf("%s\n", node->produto);
        printf("Quantidade: ");
        printf("%d\n", node->qtd);

		printf ("\n");
    }
    if ( ini == NULL) //se n�o houver produtos registrados, voltar� nula.
        printf("Nenhum Produto Registrado.");

}

Estoque* excluir(Estoque* ini) {//j� que os itens n�o tem uma ordem determinada, fica mais facil de se encontrar e excluir um arquivo um dado de um n�

    Estoque *ant = NULL; //ponteiro para a posi��o anterior
    Estoque *node = ini; //ponteiro do n� inicial
    int aux = 0; // auxiliar

    printf("\nCodigo do item a ser excluido: ");
    scanf("%d",&aux);

	//la�o que ir� fazer uma procura na lista
    while( node != NULL && node->codigo != aux) { //Enquanto o n� for diferente de Null e o n� for diferente de auxiliar
        ant = node; //o anterior ser� igual ao node inicial
        node = node->prox; //e o node apontar� para o pr�ximo n�, at� achar a igualdade do aux
    }

	//Se o node inicial j� come�ar sendo null (nada adicionado), j� dar� essa mensagem
    if (node == NULL) {
        printf("\nProduto nao encontrado.");
        return ini;
    }

	//Se o anterior se manter NULL, ou seja, se na fun��o while, o codigo for igual ao aux...
    if (ant == NULL) {
        printf("\nConteudo excluido com sucesso.");
        ini= node->prox; //o n� inicial ser� o proximo n�, removendo o dado anterior
	//Caso o dado n�o estiver no inicio da lista, ser� removido no meio dela.
    } else {
        printf("\nConteudo excluido com sucesso.");
        ant->prox= node->prox;
    }

    free(node); //fun��o que libera o node.
    return ini;
}



void alterar(Estoque *ini) { // linha de comandos semelhante a de Buscar, s� que dessa vez, ao inves de apenas mostrar, ele ir� subtituir os dados 

	//fun��es auxiliares
    int cod_02;
    char Npdt[50];
    int Nqtd;
    int aux;
    Estoque *node = ini;

    //c�digo para ser alterado o nome e a quantidade
    printf("\nCodigo do item a ser alterado: ");
    scanf("%d", &cod_02);

    aux = 0;
    // Busca pelo cadastro
    for (node = ini; node != NULL; node = node->prox) { //se o n� no inico for diferente de NULL, ele estar� apontando para o proximo n�
        if (node->codigo == cod_02) { //se o codigo do n� for semalhante a variavel auxiliar, entra no la�o realizar a troca de dados
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
