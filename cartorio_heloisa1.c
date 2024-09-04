#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // bilioteca respins�vel por cuidar das string

int registro()// Fun��o respons�vel por cadastrar os usu�rios no sistema.
{
	setlocale(LC_ALL, "Portuguese");
	// inicio cria��o de vari�veis/string	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando as informa��es do usu�rio
	scanf("%s", cpf); //"%s" refere-se a string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o aquivo e o "w" significa escrever
	fprintf (file, cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" significa atualizar
	fprintf(file, ",");//abre o arquivo e atualiza a vari�vel
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coleta as informa��es do usu�rio
	scanf("%s", nome);// scaneia a informa��o que o usu�rio envia e "%s" refere-se a string 
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" significa atualizar
	fprintf(file, nome);// salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" significa atualizar
	fprintf(file, " ");//abre o arquivo e atualiza
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coleta a informa��o do usu�rio
	scanf("%s", sobrenome);// scaneia a informa��o que o usu�rio envia
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" siginifica atualizar
	fprintf(file, sobrenome);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");// abre o arquivo e "a" significa atualizar
	fprintf(file, ",");//abre o arquivo e atualiza
	fclose(file);// fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coleta informa��o do usu�rio
	scanf("%s", cargo); //scaneia a informa��o enviada pelo usu�rio
	
	file =fopen(arquivo, "a");//abre o arquivo e "a" atualiza
	fprintf(file, cargo);// salva o valolr da vari�vel
	fclose(file);// fecha o arquivo
		
	
}

int consulta() // Fun��o respons�vel por consultar os usu�rios no sistema.
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	//inicio da variavel string
	char cpf[40];
	char conteudo[200];
	// fim da vari�vel string
	
	printf("Digite o CPF a ser consultado: ");// coleta informa��o do usu�rio
	scanf("%s", cpf);// scaneia a informa��o enviada pelo usu�rio
		
	FILE *file; //busca o arquivo j� criado
	file = fopen(cpf, "r");// busca o arquivo e "r" significa ler
	
	if(file == NULL)// estrutura de condi��o, caso o arquivo n�o seja localizado 
	{
		printf("N�o foi possivel abrir o arquivo. N�o localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}	

int deletar()// Fun��o respons�vel por  os usu�rios no sistema.
{
	//inicio da variavel string
	char cpf [40];
	//fim da vari�vel string
	printf("Digite o CPF do usu�rio a ser deletado: ");//coletando as informa��es do usu�rio
	scanf("%s", cpf);// scanei a informa��o enviada pelo usu�rio
	
	remove(cpf);//deleta o arquivo
	
	FILE *file;//busca o arquivo j� criado
	file = fopen(cpf, "r");// busca o arquivo e "r" significa ler
	
	
	if(file == NULL)
	{
		printf("O usu�rio n�o foi encontrado no sistema!\n");
			system("pause");
	}

}

int main()//fun��o principal
	{ 
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("### Cart�rio da EBAC ###\n\n");//In�cio do sistema
	printf("Login de administrador!\n\n Digite a sua senha: ");//tela de inser��o de senha
	scanf("%s", senhadigitada); //scaneia a informa��o enviada pelo usu�rio
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{

		system("cls"); // respons�vel por limpar a tela
		
		for(laco=1;laco=1;)
		{
	
			system("cls"); 
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1- Resgitrar nomes\n");
			printf("\t2- Consultar os nomes\n");
			printf("\t3- Deletar nomes\n");
			printf("\t4- Sair do sistema\n\n");
			printf("opcao: ");//fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
			system("cls");// respons�vel por limpar a tela
		
			switch (opcao) //inicio da sele��o do menu
			{
		
				case 1:
				registro();	//chamada de fun��es		
				break;
			
				case 2:
				consulta(); //chamada de fun��es
				break;
			
				case 3:
				deletar(); //chamada de fun��es
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa op��o n�o est� disponivel\n");
				system("pause");
				break;	
				}//fim da sele��o
			}
			
		}	
			else
			printf("Senha incorreta!");
	}
	
	
	  
