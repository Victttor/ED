#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//REGISTRO DO ALUNO.
struct aluno{
	
	char nome [15];
	char disciplina [20]; 
	float nota;

}aluno;

//ARQUIVO.
FILE *NOTAS;

//VARIAVEIS DAS OPCOES SELECIONAVEIS NO MENU.
void adicionar_nota();
void buscar_nota_aluno();
void buscar_nota_disciplina();
void mostrar_tudo();


int menu();

//FUNCAO DO MENU E MAIN.
int main(){
	int op;

	do{
		op = menu();
		switch(op){
			case 1:{
				adicionar_nota();
				break;
			}
			case 2:{
				buscar_nota_aluno();
				break;
			}
			case 3:{
				buscar_nota_disciplina();
				break;
			}
			case 4:{
				mostrar_tudo();
				break;
			}
			case 5:{
				printf("\n\n------SAINDO------\n\n");
				break;
			}
			default:{
				printf("Insira uma opcao valida!!"); //CASO O USUARIO INFORMAR NUMEROS ACIMA DE 5 OU O NUMERO 0, APARECERA O AVISO.
				break;
			}	
		}
		
	}while (op != 5);
	
	
	return 0;
}

//INTERFACE DO MENU QUE APARECERÁ AO USUARIO.
int menu(){
	int op;
	printf("\n\n=================MENU==================\n\n");
	printf("1.Adicionar nota do aluno\n");
	printf("2.Buscar nota de um aluno\n");
	printf("3.Buscar notas de uma disciplina\n");
	printf("4.Mostrar dados registrados\n");
	printf("5.Sair  ");
	printf("\n=======================================\n\n");
	printf("Escolha a opcao desejada:");
	scanf("%d",&op);
	setbuf(stdin,NULL); //LIMPEZA DO BUFFER/MEMORIA RESIDUAL.
	printf("\n");
	return(op);
}

//FUNÇÃO DE ADICIONAR NOTA AO ALUNO.
void adicionar_nota(){
	FILE *NOTAS;
	
	NOTAS = fopen("NOTAS.txt", "a"); //ABRIR ARQUIVO EM MODO "A", ONDE IRÁ ADICIONAR OS DADOS NO ARQUIVO JÁ EXISTENTE, CASO NÃO HOUVER O ARQUIVO, ELE CRIA UM NOVO
	if (NOTAS == NULL){
    	printf("ERRO! O arquivo nao foi aberto!\n"); //CASO O ARQUIVO NÃO FOR ABERTO, O AVISO APARECERÁ.
	}else{
	
		printf("\n=============DADOS DO ALUNO============\n");
		printf("NOME: ");
		gets(aluno.nome); //RECEBE A INFORMACAO INSERIDA PELO USUARIO
				
		printf("DISCIPLINA: ");
		gets(aluno.disciplina);
		setbuf(stdin,NULL);
		   
    	printf("NOTAS: ");
		scanf("%f", &aluno.nota);

		
		fwrite(&aluno, sizeof(aluno), 1, NOTAS); //RESPONSAVEL PELA GRAVAÇÃO DOS DADOS INFORMADOS NO ARQUIVO.
		//O FWRITE FOI A VARIAVEL QUE DEU CERTO PARA ADICIONAR OS DADOS NO ARQUIVO PARA DEPOIS SER POSSIVEL BUSCAR AS INFORMAÇÕES NOS ITENS A SEGUIR.
		printf("\nNOTA DE ALUNO CADASTRADO COM SUCESSO");
		printf("\n=======================================\n");
	
	}	
	
	fclose(NOTAS);

}

//FUNÇÃO DE BUSCAR DE NOTA DE ALUNO.
void buscar_nota_aluno(){
	FILE *NOTAS;
	int c=0;
	char nome_aluno [20];
	int cmp; //VARIAVEL DE COMPARAÇÃO.
	
	printf("Informe o nome do aluno: ");
	scanf("%s",nome_aluno);
	
	NOTAS = fopen("NOTAS.txt", "r"); //ARQUIVO ABERTO EM MODO "r" QUE IRÁ LER O ARQUIVO.
	
	while( fread(&aluno, sizeof(aluno), 1, NOTAS) == 1 ){ //LAÇO RESPOSÁVEL PELA LEITURA DO ARQUIVO, ONDE IRA REPETIR ATÉ CHEGAR NO FINAL DO ARQUIVO.
		cmp=strcmp(nome_aluno,aluno.nome); //FUNÇÃO DE COMPARAÇÃO DE STRING, SE OS CARECTERES SÃO SEMELHANTES.
		if((cmp == 0)){ //SE AS STRINGS FOREM SEMELHANTES, O PROGRAMA CONTINUARÁ, CASO CONTRARIO, APARECERÁ UM AVISO.
			c++;
			printf("=======================================\n");
			printf("DISCIPLINA: %s\n",aluno.disciplina); //APARECERA NA TELA A INFORMACAO BUSCADA DO ARQUIVO
    		printf("NOTA: %.2f\n",aluno.nota);
			printf("=======================================\n");
		} 
				
	}	
	printf("=======================================\n");
	if (c==0) printf("\nNOME INFORMADO INCORRETO OU NAO EXISTENTE!"); // O AVISO.
	fclose(NOTAS);
	
}

//FUNÇÃO DE BUSCAR AS NOTAS DE UMA DISCIPLINA.
void buscar_nota_disciplina(){
	FILE *NOTAS;
	
	char materia [20];
	int cmp1; //COMPARAÇÃO.
	int n=0; //NUMERO DE VEZES QUE SE REPETE A MATERIA
	float soma=0;//TOTAL DA SOMA DAS NOTAS
	float media=0;//MEDIA DAS NOTAS
	
	printf("Informe a disciplina: ");
	scanf("%s",materia);
	
	NOTAS = fopen("NOTAS.txt", "r");
	
	while( fread(&aluno, sizeof(aluno), 1, NOTAS) == 1 ){
		cmp1=strcmp(materia,aluno.disciplina); //FUNÇÃO DE COMPARAÇÃO DE STRING, SE OS CARECTERES SÃO SEMELHANTES.
		if((cmp1 == 0)){//SE AS STRINGS FOREM SEMELHANTES, O PROGRAMA CONTINUARÁ, CASO CONTRARIO, APARECERÁ UM AVISO.
			n++;
			soma=soma+aluno.nota; //NAO CONSEGUI FAZER POR RECURSIVIDADE, TENTEI DE VARIAS FORMAS MAS SEM SUCESSO.
			printf("=======================================\n");
			printf("ALUNO: %s\n",aluno.nome);
    		printf("NOTA: %.2f\n",aluno.nota);
			printf("=======================================\n");
		}
		
	}
	media=soma/n;
	if (n!=0) printf("\nA media das notas dessa disciplina eh: %.2f",media);
	
	if (n==0) printf("\nA DISCIPLINA INFORMADA ESTA INCORRETA OU NAO REGISTRADA!");
	
		
	fclose(NOTAS);
}

//COMO EXTRA, FIZ ESSA FUNÇÃO QUE MOSTRA TODOS OS DADOS REGISTRADOS NO ARQUIVO.
void mostrar_tudo(){

	FILE *NOTAS;
	
	
	NOTAS = fopen("input_10.txt", "r");
	printf("\n===========DADOS REGISTRADOS===========\n\n\n");
	while( fread(&aluno, sizeof(aluno), 1, NOTAS) == 1 ){//LOOP SEMELHANTE AOS ANTERIORES.

		printf("=======================================\n");
//		printf("NOME: %s\n",aluno.nome);
//		printf("DISCIPLINA: %s\n",aluno.disciplina);
    	printf("NOTA: %.2f\n",aluno.nota);
		printf("=======================================\n");
	}
		
	fclose(NOTAS);
}
