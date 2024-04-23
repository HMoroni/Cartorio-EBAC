#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // Biblioteca que cuida das Strings

int Registro()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado:\n");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); //Resposavel por copiar os valores das string
    
    FILE *file; // Cria o arquivo na pasta
    file = fopen(arquivo, "w");
    fprintf(file,cpf);// salvo o valor da  variavel
    fclose(file);//fecha o arquivo depois de salvar

    file=fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o Primeiro Nome a ser cadastrado:\n");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);

    file=fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o Sobrenome a ser cadastrado:\n");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file=fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado:\n");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    file=fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    system("pause");

}

int Consultar()
{
    setlocale(LC_ALL, "portuguese_brazil");
    
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado:\n");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
        printf("não foi possivel encontrar o arquivo selecionado!\n");
    }

    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações de usuário:\n ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}

int Deletar()
{
    char cpf[40];

    printf("Digite o CPF a que deseja deletar: ");
    scanf("%s",cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL);
    {
        printf("O usurio não esta cadastrado no sistema.\n");
        system("pause");   
    }

    
}

int main() //função principal do menu
{
    int opcao=0;// Definindo as variaveis
    int x=1;
    for(x=1;x=1;)
    {
        system("cls");
        setlocale(LC_ALL,"Portuguese");//Definindo a Lingua do codigo

        printf("### Cartório da EBAC ###\n\n"); //inicio do menu
        printf("Escolha a opção desejada do menu\n\n");
        printf("\t1 - Registro nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");//Fim do menu
        printf("\t4 - Sair do menu\n\n");
        printf("Esse Software foi criado por Henrique Moroni\n");

        scanf("%d", &opcao); //Armazenando a escolha do usuario

        system("cls");

        switch(opcao)
        {
            case 1:
            Registro();
            break;

            case 2:
            Consultar();
            break;

            case 3:
            Deletar();
            break;

            case 4:
            printf("Obrigado por utilizar o sistema!");
            return 0;


            default:
            printf("Por favor escolha uma opção valida\n\n");
            system("pause");
            break;
        }

       
    }
}
