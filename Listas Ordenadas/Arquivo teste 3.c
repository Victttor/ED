#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
  // nome e local do arquivo que ser� aberto para
  // obtermos a quantidade de linhas
  FILE *arquivo = fopen("c:\\input_100.txt", "r");
  int caractere, existe_linhas = 0;
  int quant_linhas = 0;
   
  while((caractere = fgetc(arquivo)) != EOF){
    existe_linhas = 1; // h� conte�do no arquivo
     
    if(caractere == '\n'){ // � uma quebra de linha?
      // vamos incrementar a quantidade de linhas
      quant_linhas++;             
    } 
  }
 
  // se n�o houver uma quebra de linha na �ltima linha
  // a contagem ser� sempre um a menos. Assim, � melhor
  // incrementar quant_linhas mais uma vez
  if(existe_linhas)
    quant_linhas++;
 
  // vamos exibir o resultado
  printf("O arquivo possui %d linhas.", quant_linhas);
   
  printf("\n\n");
  system("PAUSE");  
  return 0;
}
