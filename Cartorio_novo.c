#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pela cria��o de strings


int registrar() //Fun��o responsavel por cadastar os usu�rios no sistema
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem usada
	//in�cio cria��o de vari�veis/string
	char opcao=0;
	char cpf[40]; 
	char nome[40]; 
	char sobrenome[40];
	char cargo[40];
	char arquivo[40];
	//final da cria��o de vari�veis/string
	
	printf("*** Cart�rio de EBAC ***\n\n"); //Nome do programa
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o de usu�rio
	scanf("%s", cpf); //%s refere-se a string
	printf("\n");

	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // informando que o computador tem que acessar arquivo.
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrevar
	fprintf(file, "CPF: ");
	fprintf(file, cpf); //Salvando o valor da variavel
	fclose(file); //fechando o arquivo

	file = fopen(arquivo, "a");//editando arquivo
	fprintf(file, ". "); //salvando o valor da variavel
	fclose(file); //fechando o arquivo

	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", nome);
	printf("\n");

	file = fopen(arquivo, "a"); //editando arquivo, "a" significa editar
	fprintf(file, "Nome: ");
	fprintf(file, nome);
	fprintf(file, " ");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: "); //coletando iforma��o do usu�rio
	scanf("%s", sobrenome);
	printf("\n");
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fprintf(file, ". ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	printf("\n");
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file, cargo);
	fprintf(file, ".");
	fclose(file);
	
	printf("Cadastro feito com sucesso!\n\n");
	
	system("pause");
	system("cls");
	
	printf("O que deseja fazer agora?\n\n");
	printf("\t1 - Registrar novo nome\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("\t4 - Voltar ao Menu\n\n");
	printf("Digite a op��o desejada: ");
	scanf("%d", &opcao);
	
	system("cls");
	
	
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
			main();
			break;	
	} 	
}

int consultar() //Fun��o responsavel por consultar usu�rios no sistema
{
	setlocale(LC_ALL, "portuguese");//Definindo a linguagem usada
	//cria��o de vari�veis/strings
	int opcao=0;
	char cpf[40];
	char conteudo[200];
	//final da cria��o
	
	printf("*** Cart�rio da EBAC ****\n\n");//Nome do programa
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //lendo o arquivo.
	
	if(file == NULL) //consultando o banco de dados para ver se tem o cpf no sistema
	{
		printf("\nN�o achamos esse n�mero de CPF em nosso sistema, tente novamente!\n\n");
		system("pause");
		system("cls");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //pegando os dados do usu�rio no banco de dados
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	system("cls");
	
	printf("O que deseja fazer agora?\n\n");
	printf("\t1 - Consultar novo nome\n");
	printf("\t2 - Registrar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("\t4 - Voltar ao Menu\n\n");
	printf("Digite a op��o desejada: ");
	scanf("%d", &opcao);
	
	system("cls");
	
	switch(opcao)
	{
		case 1:
			consultar();
			break;
		case 2:
			registrar();
			break;
		case 3:
			deletar();
				break;
		
		default:
			main();
			break;	
	} 	
	
	
	
}

int deletar() //Fun��o responsavel por deletar usu�rio no sistema
{
	setlocale(LC_ALL, "portuguese");//Definindo a linguagem usada
	
	int opcao=0;
	char cpf[40]; //cria��o de variavel/string
	
	printf("*** Cart�rio da EBAC ***\n\n"); //Nome do programa
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;  //abrindo banco de dados
	file = fopen(cpf, "r"); //lendo o dado
	
	if(file == NULL) //analise para ver se o cpf est� no banco do dados
	{
		printf("\nN�o achamos esse n�mero de CPF em nosso sistema, tente novamente!\n\n");
		system("pause");
		return; //retorno ao menu caso o cpf informado n�o esteja no sistema.
	}
	fclose(file);
	
	remove(cpf); //remo��o dos dados no sistema
	
	file = fopen(cpf, "r");
	
	if(file == NULL) // analise para ver se o cpf informado foi apagado
	{
		printf("\nCPF exclu�do com sucesso\n\n");
	}

	system("pause");
	system("cls"); 
	
	printf("O que deseja fazer agora?\n\n");
	printf("\t1 - Deletar outro nome\n");
	printf("\t2 - Registrar nomes\n");
	printf("\t3 - Consultar nomes\n");
	printf("\t4 - Voltar ao Menu\n\n");
	printf("Digite a op��o desejada: ");
	scanf("%d", &opcao);
	
	system("cls");
	
	switch(opcao)
	{
		case 1:
			deletar();
			break;
		case 2:
			registrar();
			break;
		case 3:
			consultar();
				break;
		
		default:
			main();
			break;	
	} 	
}

int main() //Fun��o_Principal
{
	int opcao=0; //Definido vari�veis
	int loop=1;
	
	for(loop=1;loop=1;)
	{
		system("cls"); //responsavel por limpar a tela
		
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem usada
	
		printf("*** Cart�rio da EBAC ***\n\n"); //Nome do programa
		printf("Escolha a op��o desejada\n\n"); //in�cio do Menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); //Fim do menu
		printf("Esse Software foi criado pelo programador VictorMaterco\n\n"); //assinatura do criador
		printf(" Digite a op��o desejada: "); //escolha do usu�rio
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //in�cio da sele��o
		{
			case 1:
				registrar(); //chamada de fun��es
				break;
			
			case 2:
				consultar();
				break;
			
			case 3:
				deletar();
				break;
				
			case 4:
				printf("*** Cart�rio da EBAC ***\n\n");
				printf("Obrigado por utilizar nosso sistema!");
				return 0;
				break;
				
			default:
				printf("*** Cart�rio da EBAC ***\n\n"); //Nome do programa
				printf("Essa op��o n�o est� dispon�vel!\n\n");
				system("pause");
				break;		
		} //Fim da sele��o
	}
}

