#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // bilioteca respinsável por cuidar das string

int registro()// Função responsável por cadastrar os usuários no sistema.
{
	setlocale(LC_ALL, "Portuguese");
	// inicio criação de variáveis/string	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando as informações do usuário
	scanf("%s", cpf); //"%s" refere-se a string
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o aquivo e o "w" significa escrever
	fprintf (file, cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" significa atualizar
	fprintf(file, ",");//abre o arquivo e atualiza a variável
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coleta as informações do usuário
	scanf("%s", nome);// scaneia a informação que o usuário envia e "%s" refere-se a string 
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" significa atualizar
	fprintf(file, nome);// salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" significa atualizar
	fprintf(file, " ");//abre o arquivo e atualiza
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coleta a informação do usuário
	scanf("%s", sobrenome);// scaneia a informação que o usuário envia
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" siginifica atualizar
	fprintf(file, sobrenome);//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");// abre o arquivo e "a" significa atualizar
	fprintf(file, ",");//abre o arquivo e atualiza
	fclose(file);// fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coleta informação do usuário
	scanf("%s", cargo); //scaneia a informação enviada pelo usuário
	
	file =fopen(arquivo, "a");//abre o arquivo e "a" atualiza
	fprintf(file, cargo);// salva o valolr da variável
	fclose(file);// fecha o arquivo
		
	
}

int consulta() // Função responsável por consultar os usuários no sistema.
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	//inicio da variavel string
	char cpf[40];
	char conteudo[200];
	// fim da variável string
	
	printf("Digite o CPF a ser consultado: ");// coleta informação do usuário
	scanf("%s", cpf);// scaneia a informação enviada pelo usuário
		
	FILE *file; //busca o arquivo já criado
	file = fopen(cpf, "r");// busca o arquivo e "r" significa ler
	
	if(file == NULL)// estrutura de condição, caso o arquivo não seja localizado 
	{
		printf("Não foi possivel abrir o arquivo. Não localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: \n ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}	

int deletar()// Função responsável por  os usuários no sistema.
{
	//inicio da variavel string
	char cpf [40];
	//fim da variável string
	printf("Digite o CPF do usuário a ser deletado: ");//coletando as informações do usuário
	scanf("%s", cpf);// scanei a informação enviada pelo usuário
	
	remove(cpf);//deleta o arquivo
	
	FILE *file;//busca o arquivo já criado
	file = fopen(cpf, "r");// busca o arquivo e "r" significa ler
	
	
	if(file == NULL)
	{
		printf("O usuário não foi encontrado no sistema!\n");
			system("pause");
	}

}

int main()//função principal
	{ 
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("### Cartório da EBAC ###\n\n");//Início do sistema
	printf("Login de administrador!\n\n Digite a sua senha: ");//tela de inserção de senha
	scanf("%s", senhadigitada); //scaneia a informação enviada pelo usuário
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{

		system("cls"); // responsável por limpar a tela
		
		for(laco=1;laco=1;)
		{
	
			system("cls"); 
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cartório da EBAC ###\n\n"); //início do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1- Resgitrar nomes\n");
			printf("\t2- Consultar os nomes\n");
			printf("\t3- Deletar nomes\n");
			printf("\t4- Sair do sistema\n\n");
			printf("opcao: ");//fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usuário
	
			system("cls");// responsável por limpar a tela
		
			switch (opcao) //inicio da seleção do menu
			{
		
				case 1:
				registro();	//chamada de funções		
				break;
			
				case 2:
				consulta(); //chamada de funções
				break;
			
				case 3:
				deletar(); //chamada de funções
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa opção não está disponivel\n");
				system("pause");
				break;	
				}//fim da seleção
			}
			
		}	
			else
			printf("Senha incorreta!");
	}
	
	
	  
