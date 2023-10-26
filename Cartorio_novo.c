#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pela criação de strings


int registrar() //Função responsavel por cadastar os usuários no sistema
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem usada
	//início criação de variáveis/string
	char opcao=0;
	char cpf[40]; 
	char nome[40]; 
	char sobrenome[40];
	char cargo[40];
	char arquivo[40];
	//final da criação de variáveis/string
	
	printf("*** Cartório de EBAC ***\n\n"); //Nome do programa
	printf("Digite o CPF a ser cadastrado: "); //coletando informação de usuário
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

	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", nome);
	printf("\n");

	file = fopen(arquivo, "a"); //editando arquivo, "a" significa editar
	fprintf(file, "Nome: ");
	fprintf(file, nome);
	fprintf(file, " ");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: "); //coletando iformação do usuário
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
	printf("Digite a opção desejada: ");
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

int consultar() //Função responsavel por consultar usuários no sistema
{
	setlocale(LC_ALL, "portuguese");//Definindo a linguagem usada
	//criação de variáveis/strings
	int opcao=0;
	char cpf[40];
	char conteudo[200];
	//final da criação
	
	printf("*** Cartório da EBAC ****\n\n");//Nome do programa
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //lendo o arquivo.
	
	if(file == NULL) //consultando o banco de dados para ver se tem o cpf no sistema
	{
		printf("\nNão achamos esse número de CPF em nosso sistema, tente novamente!\n\n");
		system("pause");
		system("cls");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //pegando os dados do usuário no banco de dados
	{
		printf("\nEssas são as informações do usuário: ");
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
	printf("Digite a opção desejada: ");
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

int deletar() //Função responsavel por deletar usuário no sistema
{
	setlocale(LC_ALL, "portuguese");//Definindo a linguagem usada
	
	int opcao=0;
	char cpf[40]; //criação de variavel/string
	
	printf("*** Cartório da EBAC ***\n\n"); //Nome do programa
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;  //abrindo banco de dados
	file = fopen(cpf, "r"); //lendo o dado
	
	if(file == NULL) //analise para ver se o cpf está no banco do dados
	{
		printf("\nNão achamos esse número de CPF em nosso sistema, tente novamente!\n\n");
		system("pause");
		return; //retorno ao menu caso o cpf informado não esteja no sistema.
	}
	fclose(file);
	
	remove(cpf); //remoção dos dados no sistema
	
	file = fopen(cpf, "r");
	
	if(file == NULL) // analise para ver se o cpf informado foi apagado
	{
		printf("\nCPF excluído com sucesso\n\n");
	}

	system("pause");
	system("cls"); 
	
	printf("O que deseja fazer agora?\n\n");
	printf("\t1 - Deletar outro nome\n");
	printf("\t2 - Registrar nomes\n");
	printf("\t3 - Consultar nomes\n");
	printf("\t4 - Voltar ao Menu\n\n");
	printf("Digite a opção desejada: ");
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

int main() //Função_Principal
{
	int opcao=0; //Definido variáveis
	int loop=1;
	
	for(loop=1;loop=1;)
	{
		system("cls"); //responsavel por limpar a tela
		
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem usada
	
		printf("*** Cartório da EBAC ***\n\n"); //Nome do programa
		printf("Escolha a opção desejada\n\n"); //início do Menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); //Fim do menu
		printf("Esse Software foi criado pelo programador VictorMaterco\n\n"); //assinatura do criador
		printf(" Digite a opção desejada: "); //escolha do usuário
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //início da seleção
		{
			case 1:
				registrar(); //chamada de funções
				break;
			
			case 2:
				consultar();
				break;
			
			case 3:
				deletar();
				break;
				
			case 4:
				printf("*** Cartório da EBAC ***\n\n");
				printf("Obrigado por utilizar nosso sistema!");
				return 0;
				break;
				
			default:
				printf("*** Cartório da EBAC ***\n\n"); //Nome do programa
				printf("Essa opção não está disponível!\n\n");
				system("pause");
				break;		
		} //Fim da seleção
	}
}

