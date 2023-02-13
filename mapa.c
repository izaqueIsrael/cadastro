#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 999

// variaveis
int i, acha, posicao;
char busca[15];

struct paciente
{
  int codigo;
  int lote;
  char nome[100];
  char vacina[50];
  char data[11];
  char cpf[12];
};

struct paciente pessoa[TAM];

// cadastro
void cadastro(void)
{
  for (i = 0; i < TAM; i++)
  {
    if (strlen(pessoa[i].data) == 0)
    {
      printf("Digite o nome do paciente: \n");
      scanf("%99s", pessoa[i].nome);
      printf("Digite o nome da vacina: \n");
      scanf("%49s", pessoa[i].vacina);
      printf("Digite o numero do lote: \n");
      scanf("%d", &pessoa[i].lote);
      printf("Digite a data da aplicacao no padrao day/month/year: \n");
      scanf("%10s", pessoa[i].data);
      printf("Digite apenas os digitos do cpf do paciente: \n");
      scanf("%11s", pessoa[i].cpf);
      pessoa[i].codigo = rand() % 1000001;
      break;
    }
  }
}

// Listar
void listar(void)
{
  system("cls");
  int existe = 0;
  for (i = 0; i < TAM; i++)
  {
    if (strlen(pessoa[i].data) == 10)
    {
      existe = 1;
      printf("Codigo: %d\n", pessoa[i].codigo);
      printf("Nome: %s\n", pessoa[i].nome);
      printf("CPF: %s\n", pessoa[i].cpf);
      printf("Vacina: %s\n", pessoa[i].vacina);
      printf("Data da aplicacao: %s\n", pessoa[i].data);
      printf("Numero do lote: %d\n", pessoa[i].lote);
      printf("==================================\n");
    }
  }
  if (!existe)
    printf("Nao ha registros \n");
}

// Consultar
void consultar()
{
  system("cls");
  printf("Digite apenas os digitos do cpf de quem deseja buscar: ");
  scanf("%11s", busca);
  acha = 0;
  for (i = 0; i < TAM; i++)
  {
    if (strcmp(pessoa[i].cpf, busca) == 0)
    {
      acha = 1;
      posicao = i;
      break;
    }
  }
  if (acha == 0)
    printf("Cpf nao encontrado\n");
  else
  {
    printf("Codigo: %d\n", pessoa[posicao].codigo);
    printf("Nome: %s\n", pessoa[posicao].nome);
    printf("CPF: %s\n", pessoa[posicao].cpf);
    printf("Vacina: %s\n", pessoa[posicao].vacina);
    printf("Data da aplicacao: %s\n", pessoa[posicao].data);
    printf("Numero do lote: %d\n", pessoa[posicao].lote);
    printf("==================================\n");
  }
}

// gerenciadora
void gerenciadora(int op)
{
  if (op == 1)
    cadastro();
  if (op == 2)
    listar();
  if (op == 3)
    consultar();
  if (op == 4)
    exit(0);
}

// main
int main(void)
{
  int op = 0;
  srand(time(NULL));

  while (op != 4)
  {
    printf("MAPA\n");
    printf("Escolha uma opcao: \n");
    printf("1 - Cadastrar vacinas \n");
    printf("2 - Listar todas as Aplicacoes \n");
    printf("3 - Consultar usuario por cpf\n");
    printf("4 - Sair \n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &op);
    gerenciadora(op);
  }
  return 0;
}
