#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h>//biblioteca de alocação de espaço de texto por região.
#include <locale.h>//biblioteca de alocações de texto por região.
#include <string.h>//biblioteca responsável pelas strings.


//................................REGISTRO....................................
int registro()//função responsável por cadastrar o usuário no sistema.
    {  
        //inicio criação de varaiáveis/string 
        char arquivo[40];
        char cpf[40];
        char nome[40];
        char sobrenome[40];
        char cargo[40];
        //final criação de variáveis/string.
        
        //....................cpf/novo_arquivo.................
        printf("Digite o cpf a ser digitado: ");//coletando informção do usuário.
        scanf("%s", cpf);////%s refere-se a string.
        
        strcpy(arquivo, cpf);//responsável por copiar os valores das strings.
        
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
        
        
        if(file == NULL)//faz uma validação.
        {
           printf("Não foi possivel localizar o arquivo.\n");         
        }
        
        while(fgets(conteudo, 200, file)!= NULL)//enquanto
        {
           printf("\nEssas são as informações do usuário: ");
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
        
        printf("Digite o cpf do usuário a ser deletado: ");
        scanf("%s", cpf);
        
        remove(cpf);
        
        FILE *file;
        file = fopen(cpf, "r");
        
        
        
         
        if(file == NULL)
        {
                printf("O usuário não se encontra no sistema!\n");
                system("pause");
        }
                   
    }
    
//....................................MAIN.....................................
int main()//função principal.
    {

        int opcao=0;// Definindo variável.
        int laco=1;
    
        for(laco=1; laco=1;)
        {

        setlocale(LC_ALL, "Portuguese");// Definindo a linguagem.  
        system("cls");
        printf("### Cartório da EBAC###\n\n");// Inicio do menu.
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Opção ");// fim do menu.
        
        scanf("%d", &opcao);//Armazenando a escolha do usuário
        system("cls");//responsável por limpar a tela.
        
        switch(opcao)//inicio da seleção do menu.
            {
            case 1:
            registro();//chamada de função.
            break;
            
            case 2:
            consulta();
            break;
            
            case 3:
            deletar();
            break;
            
            default:
            printf("Essa opção não está disponivel!\n");
            system("pause");
            break;
            }//fim da seleção do menu.
        
       }
        
    } 

