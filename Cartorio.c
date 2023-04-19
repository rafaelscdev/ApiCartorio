#include <stdio.h> //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h>//biblioteca de aloca��o de espa�o de texto por regi�o.
#include <locale.h>//biblioteca de aloca��es de texto por regi�o.
#include <string.h>//biblioteca respons�vel pelas strings.


//................................REGISTRO....................................
int registro()//fun��o respons�vel por cadastrar o usu�rio no sistema.
    {  
        //inicio cria��o de varai�veis/string 
        char arquivo[40];
        char cpf[40];
        char nome[40];
        char sobrenome[40];
        char cargo[40];
        //final cria��o de vari�veis/string.
        
        //....................cpf/novo_arquivo.................
        printf("Digite o cpf a ser digitado: ");//coletando inform��o do usu�rio.
        scanf("%s", cpf);////%s refere-se a string.
        
        strcpy(arquivo, cpf);//respons�vel por copiar os valores das strings.
        
        FILE *file;//cria o arquivo.
        file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever.
        fprintf(file, cpf);//salva o valor da variavel.
        fclose(file);//fecha o arquivo.
        
        file = fopen(arquivo, "a");//"a" atualiza o arquivo anteriormente criado.
        fprintf(file, ",");//salva o valor da variavel.
        fclose(file);//fecha o arquivo.
        
        //....................nome...........................
        printf("Digite o nome a ser cadastrado: ");
        scanf("%s", nome);
        
        file = fopen(arquivo,"a");
        fprintf(file, nome);
        fclose(file);
        
        file = fopen(arquivo, "a");
        fprintf(file, ",");
        fclose(file);
        
        //....................sobrenome.......................
        printf("Digite o sobrenome a ser cadastrado: ");
        scanf("%s", sobrenome);
        
        file = fopen(arquivo, "a");
        fprintf(file, sobrenome);
        fclose(file);
        
        file = fopen(arquivo, "a");
        fprintf(file, ",");
        fclose(file);
       
        //....................cargo..........................
        printf("Digite o cargo a ser cadastrado: ");
        scanf("%s", cargo);
        
        file = fopen(arquivo, "a");
        fprintf(file, cargo);
        fclose(file);
        
        system("pause");       
        
    }
    
//.................................CONSULTA....................................
int consulta()
    {
        setlocale(LC_ALL, "Portuguese");// Definindo a linguagem.
        
        char cpf[40];
        char conteudo[200];
        
        printf("Digite o cpf a ser consultado: ");
        scanf("%s", cpf);
        
        FILE *file;
        file = fopen(cpf, "r");
        
        
        if(file == NULL)//faz uma valida��o.
        {
           printf("N�o foi possivel localizar o arquivo.\n");         
        }
        
        while(fgets(conteudo, 200, file)!= NULL)//enquanto
        {
           printf("\nEssas s�o as informa��es do usu�rio: ");
           printf("%s", conteudo);
           printf("\n\n"); 
        }
        fclose(file);
        system("pause");
    }
    
//...................................DELETAR...................................
int deletar()
    {
        char cpf[40];
        
        printf("Digite o cpf do usu�rio a ser deletado: ");
        scanf("%s", cpf);
        
        remove(cpf);
        
        FILE *file;
        file = fopen(cpf, "r");
        
        
        
         
        if(file == NULL)
        {
                printf("O usu�rio n�o se encontra no sistema!\n");
                system("pause");
        }
                   
    }
    
//....................................MAIN.....................................
int main()//fun��o principal.
    {

        int opcao=0;// Definindo vari�vel.
        int laco=1;
    
        for(laco=1; laco=1;)
        {

        setlocale(LC_ALL, "Portuguese");// Definindo a linguagem.  
        system("cls");
        printf("### Cart�rio da EBAC###\n\n");// Inicio do menu.
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Op��o ");// fim do menu.
        
        scanf("%d", &opcao);//Armazenando a escolha do usu�rio
        system("cls");//respons�vel por limpar a tela.
        
        switch(opcao)//inicio da sele��o do menu.
            {
            case 1:
            registro();//chamada de fun��o.
            break;
            
            case 2:
            consulta();
            break;
            
            case 3:
            deletar();
            break;
            
            default:
            printf("Essa op��o n�o est� disponivel!\n");
            system("pause");
            break;
            }//fim da sele��o do menu.
        
       }
        
    } 

