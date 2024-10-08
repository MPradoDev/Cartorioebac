#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Fun��o responsavel por cadastrar os usuarios no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Inicio da ccria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da ccria��o de variaveis/string

	printf("Digite o cpf a ser cadastrado: "); //Coletando informa��o do usuario
	scanf("%s", cpf); //%s refere-se as strings

	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das astings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //o "a" significa atualizar o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

}

int consulta()
{

	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}	
	
	system("pause");
	
}
	

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
			printf("O usu�rio n�o se encontra no sistema! \n");
			system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for (laco=1;laco=1;)	
	{

		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do Menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");	
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o:"); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //In�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��o "registro"
			break;
			
			case 2:
			consulta(); //chamada da fun��o "consulta"
			break;
			
			case 3:
			deletar(); //chamada da fun��o "deletar"
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema! \n"); 
			return 0;
			break;
						
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
				
		}//Fim da sele��o	
	}
				
}
