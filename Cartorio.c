#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // Biblioteca que cuida das Strings

int Registro()//Inicio da opção de Registro 
{
    char arquivo[40];// Criação de Variaveis
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];// Fim das Variaveis

    printf("Digite o CPF a ser cadastrado:\n");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file; // Cria o arquivo na pasta
    file = fopen(arquivo, "w");
    fprintf(file,cpf);// salvo o valor da  variavel
    fclose(file);//fecha o arquivo depois de salvar

    file=fopen(arquivo, "a");//Abre o arquivo para gravar ou atualizar uma informação
    fprintf(file,",");
    fclose(file);// fecha o arquivo

    printf("Digite o Primeiro Nome a ser cadastrado:\n");//Responsavel pelo Nome do cadastro
    scanf("%s", nome);

    file = fopen(arquivo, "a");// abre o arquivo para atualizar o nome
    fprintf(file,nome);
    fclose(file);// fecha o arquivo

    file=fopen(arquivo, "a");//Abre o arquivo para escrever uma ',' para separar os valores
    fprintf(file,",");
    fclose(file);//fecha o arquivo

    printf("Digite o Sobrenome a ser cadastrado:\n");// Responsavel pelo sobrenome
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");// Atualiza o sobrenome
    fprintf(file,sobrenome);
    fclose(file);

    file=fopen(arquivo, "a");//Separa com uma ','
    fprintf(file,",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado:\n");// Responsavel pelo cargo
    scanf("%s", cargo);

    file = fopen(arquivo, "a");// Atualiza o Cargo
    fprintf(file, cargo);
    fclose(file);

    file=fopen(arquivo, "a");// Adiciona a ',' denovo
    fprintf(file,",");
    fclose(file);

    system("pause");// Fim do registro

}

int Consultar()// Função de Consulta
{
    setlocale(LC_ALL, "portuguese_brazil");// Coloca como Pt-Br
    
    char cpf[40];// Variaveis
    char conteudo[200];

    printf("Digite o CPF a ser consultado:\n");// Inicio da consulta
    scanf("%s", cpf);

    FILE *file; // Procura o arquivo
    file = fopen(cpf,"r");// Procura o arquivo com o cpf = ao Consultado

    if(file == NULL) //Se arquivo = Não exite
    {
        printf("não foi possivel encontrar o arquivo selecionado!\n");// Mostrar mensagem
    }

    while(fgets(conteudo, 200, file) != NULL)// Se arquivo existir então
    {
        printf("\nEssas são as informações de usuário:\n ");//Mostrar as informações
        printf("%s", conteudo);//'%s string que mostra o conteudo do arquivo 
        printf("\n\n");
    }

    system("pause");
}

int Deletar()//Função Deletar
{
    char cpf[40];// Cariavel cpf

    printf("Digite o CPF a que deseja deletar: ");// mensagem
    scanf("%s",cpf);//guarda o cpf digitado

    remove(cpf);// remove arquivo com o cpf digitado

    FILE *file; // consulta de arquivo
    file = fopen(cpf,"r");//'r' ler arquivo conrespondente

    if(file == NULL); // se arquivo = a não exitir
    {
        printf("O usurio não esta cadastrado no sistema.\n");// Mostra essa msg
        system("pause");   
    }

    
}

int main() //função principal do menu
{
    int opcao=0;// Definindo as variaveis
    int x=1;
    int comparacao;

    printf("### Cartório da EBAC ###\n\n");
    printf("Login de Administrador!\n\nDigite a sua senha: ");
    scanf("%s",senhadigitada);

    comparacao = strcmp(senhadigitada, "admin");

    if(comparacao == 0)
    {
        system("cls");
        for(x=1;x=1;)
        {
            system("cls");
            setlocale(LC_ALL,"Portuguese");//Definindo a Lingua do codigo

            printf("### Cartório da EBAC ###\n\n"); //inicio do menu
            printf("Escolha a opção desejada do menu\n\n");
           printf("\t1 - Registro nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n");
            printf("\t4 - Sair do menu\n\n");//Fim do menu
            printf("Esse Software foi criado por Henrique Moroni\n");

            scanf("%d", &opcao); //Armazenando a escolha do usuario

            system("cls");// limpa a tela

            switch(opcao)
            {
                case 1:
                Registro();//chamada de função
                break;

                case 2:
                Consultar();//chamada de função
                break;

                case 3:
                Deletar();//chamada de função
                break;

                case 4:
                printf("Obrigado por utilizar o sistema!");
                return 0;


                default:
                printf("Por favor escolha uma opção valida\n\n");
                system("pause");
                break;
                //Fim da Seleção
            }

       
         }
    }

    else
        printf("Senha Incorreta");
}
