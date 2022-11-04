#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 999

//Aqui estou declarando o array paciente

struct paciente
{
  int  codigo;
  char nome[100];
  char vacina[50];
  int  lote;
  char data[10];
  int  cpf;
};

int main()
{
    //comeco denominando o paciente e logo abaixo declaro mais algumas variaveis,
    //alem de definir logo os codigos de cada paciente
    struct paciente muca[TAM];

    int busca, i, j, acha, op, posicao;
    op=0;

    for(i=0;i<TAM;i++){
        muca[i].codigo=i+1;
    }

    //Essa e a estrutura do menu, ao selecionar qualquer uma das opcoes
    // o programa lera atraves da variavel op e seguira com o andamento do ciclo

    while (op!=4){
    printf("MAPA\n");
    printf("Escolha uma opcao: \n");
    printf("1 - Cadastrar vacinas \n");
    printf("2 - Listar todas as Aplicacoes \n");
    printf("3 - Consultar usuario por cpf\n");
    printf("4 - Sair \n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &op);
    fflush(stdin);

    //Se o usuario selecionar a opcao 1 ira preencher os pacientes 1 por 1 conforme a
    //estrutura abaixo, nesse processo fiz um autenticador bem simples para a data
    
    if (op==1){
            for(i=0;i<=TAM;i++){
            if(strlen(muca[i].data) !=10 && strlen(muca[i+1].data) !=10 || i==TAM){
            system("cls");       
            printf("Digite o nome do paciente:  \n");
            scanf("%s", &muca[i].nome);
            fflush(stdin);
            printf("Digite o nome da vacina: \n");
            scanf("%s", &muca[i].vacina);
            fflush(stdin);
            printf("Digite o numero do lote: \n");
            scanf("%d", &muca[i].lote);
            fflush(stdin);
            printf("Digite a data da aplicacao no padrao day/month/year: \n");
            scanf("%s", &muca[i].data);
            fflush(stdin);
            if(strlen(muca[i].data)!=10){
                printf("Data invalida \n");
                break;
            }
            else{
                printf("Digite apenas os digitos do cpf do paciente: \n");
                scanf("%d", &muca[i].cpf);
                fflush(stdin);
                break;
            }
            break;
            }
            else
                continue;
            }
            
    }
    // Se o usuario selecionar a opcao 2, atraves da data o programa validara 
    // se existem registros salvos, se nao existir, avisara, do contrario ira
    // listar todos os registros salvos
    else{
        if(op==2){
            system("cls");
            if(strlen(muca[0].data) != 10)
                printf("Nao ha registros \n");
            else{
                for(i=0; i<TAM; i++){
                    if(strlen(muca[i].data)==10){
                    printf("Codigo: %d\n", muca[i].codigo);
                    printf("Nome: %s\n", muca[i].nome);
                    printf("CPF: %d\n", muca[i].cpf);
                    printf("Vacina: %s\n", muca[i].vacina);
                    printf("Data da aplicacao: %s\n", muca[i].data);
                    printf("Numero do lote: %d\n", muca[i].lote);
                    printf("==================================\n");
                    }
                    else{
                        continue;
                    }
                }                
            }
            }
    // Se o usuario selecionar a opcao 3 o programa ira pedir o cpf e buscar
    // algum cpf correspondente conforme esta no primeiro "for" desse ciclo
    // se nao existir um cpf correspondente o programa avisara, se houver um 
    //cpf correspondente ele mostrara o usuario correspondente
                else{
                        if (op==3){
                        system("cls");
                        printf("Digite apenas os digitos do cpf de quem deseja buscar: ");
                        scanf ("%d", &busca);
                        acha=0;
                        for (i=0; i<TAM;i++){
                            if(muca[i].cpf==busca){
                                acha =1;
                                posicao =i;
                            }
                        }
                        if(acha==0){
                            printf("Cpf nao encontrado\n");
                        }
                        else{
                                printf("Codigo: %d\n", muca[posicao].codigo);
                                printf("Nome: %s\n", muca[posicao].nome);
                                printf("CPF: %d\n", muca[posicao].cpf);
                                printf("Vacina: %s\n", muca[posicao].vacina);
                                printf("Data da aplicacao: %s\n", muca[posicao].data);
                                printf("Numero do lote: %d\n", muca[posicao].lote);
                                printf("==================================\n");
                        }
                }
           }
       }                  
    }
}


    // Nota: de inicio estava fazendo o menu por switchs e dividindo cada opcao 
    //por funcoes, porem estava dando tanto problema que refiz do 0 dessa forma
    // simplificada, pelo menos para mim é simplificada ...



