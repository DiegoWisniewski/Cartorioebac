#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsãvel por cuidar das strings

int registrar() // Função responsável por cadastras os usuários no sistema
{
	//início da criação de variáveis/string
	
	char arquivo[80]; // char = variavel 
	char cpf[40];
	char nome[40];
	char sobrenome[50];
	char cargo[40];
	
	//final da criação de variáveis
	
	printf("Digete o CPF a ser cadastrado: "); // coletando infção do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo // "w" escrever em ingles // fopen = abrir o arquivo
	fprintf(file, "CPF: "); //  quando o arquivo for aberto, distingue a informação dada
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); // "a" Atuliza as informações dentro da pasta
	fprintf(file,"." "\n"); // pontuação final, e pula linha para a proxima info
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
		printf("Não foi possível abrir o arquivo, não localizado.");
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; // Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	    printf("### Cartótio da EBAC ###\n\n"); // Início do menu
	    printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Regritar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");	
	    printf("Opção: "); // Final do menu
	
	    scanf("%d", &opcao); // Armazenando as escolha do usuário
	
 	    system("cls"); // responsável por limpar a tela
 	    
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
    	    printf("Essa opção não está diponível.\n");
    	    system("pause");
    	    break;
    	} // fim da seleção
	}
}
