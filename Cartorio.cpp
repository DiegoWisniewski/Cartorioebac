#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registrar() // Fun��o respons�vel por cadastras os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	
	char arquivo[80]; // char = variavel 
	char cpf[40];
	char nome[40];
	char sobrenome[50];
	char cargo[40];
	
	//final da cria��o de vari�veis
	
	printf("Digete o CPF a ser cadastrado: "); // coletando inf��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo // "w" escrever em ingles // fopen = abrir o arquivo
	fprintf(file, "CPF: "); //  quando o arquivo for aberto, distingue a informa��o dada
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); // "a" Atuliza as informa��es dentro da pasta
	fprintf(file,"." "\n"); // pontua��o final, e pula linha para a proxima info
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"." "\n"); 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"." "\n"); 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,".");
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" ler em ingles (arquivo sera lido)
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado.");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n\n");

	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; // Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	    printf("### Cart�tio da EBAC ###\n\n"); // In�cio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Regritar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");	
	    printf("Op��o: "); // Final do menu
	
	    scanf("%d", &opcao); // Armazenando as escolha do usu�rio
	
 	    system("cls"); // respons�vel por limpar a tela
 	    
 	    switch(opcao)
 	    {
 	    	case 1:
 	    	registrar();
			break;
			
			case 2:
			consultar();
    	    break;
    	    	
    	    case 3:
    	    deletar();
    	    break;
    	    
    	    default:
    	    printf("Essa op��o n�o est� dipon�vel.\n");
    	    system("pause");
    	    break;
    	} // fim da sele��o
	}
}
