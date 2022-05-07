#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct stack
{
  int distancia;
  struct stack *next;
} Stack;

Stack *start();
Stack *Insertfirst(Stack *stack, int auxTemperature);
Stack *Desempilha(Stack *stackAux);
Stack *insertfinish(Stack * lista, int distPer);
int empty(Stack *stack);
void print(Stack *stack);

int main()
{
  setlocale(LC_ALL, "portuguese");
  Stack *stack;
  int choose, i = 0, qntdistancia, discart;

  stack = (Stack *)malloc(sizeof(Stack) * 1);
  stack = start();
  do
  {

    printf("\n1 Adicionar uma distancia");
    printf("\n2 Remover distancia");
    printf("\n3 sair\n");

    scanf("\n%d", &choose);

    switch (choose)
    {
    case 1:
      printf("\nqual foi a %d distancia? ", ++i);
      scanf("%d", &qntdistancia);
      stack = insertfinish(stack, qntdistancia);
      print(stack);
      break;

    case 2:
      stack = Desempilha(stack);
      printf("Retirado da fila!\n");
      print(stack);
      break;

    case 3:
      printf("saindo.. \n");
      return 0;
      break;

    default:
      printf("Opcao invalida!! \n");
      break;
    }

  } while (choose != 0);

  return 0;
}

Stack *start()
{

  return NULL;
}

Stack *Insertfirst(Stack *stack, int qntdistancia)
{
  Stack *new = (Stack *)malloc(sizeof(Stack));

  new->distancia = qntdistancia;

  if (empty(stack))
  {
    new->next = NULL;
  }
  else
  {
    new->next = stack;
  }
  return new;
}

Stack *Desempilha(Stack *qntdistancia)
{
  Stack *new = (Stack *)malloc(sizeof(Stack));
  if (qntdistancia->next == NULL)
  {
    printf("A fila ja esta vazia\n");
    return NULL;
  }
  else
  {
    Stack *Inicio = qntdistancia->next;
    qntdistancia->next = Inicio->next;
    return Inicio;
  }
}

int empty(Stack *stack)
{
  return (stack == NULL);
}

void print(Stack *stack)
{
  if (stack->next == NULL)
  {
    printf("'%d' ", stack->distancia);
  }
  else
  {
    print(stack->next);
    printf(" '%d' ", stack->distancia);
  }
}
Stack * insertfinish(Stack * lista, int distPer)
{
    Stack * novo = (Stack * ) malloc(sizeof(Stack));

    if (empty(lista))
    {
        return Insertfirst(lista, distPer);
    }
    Stack * primeiro = lista;
    while ((lista -> next != NULL))
    {
        lista = lista -> next;
    }

    novo -> distancia = distPer;
    novo -> next = NULL;

    lista -> next = novo;

    return primeiro;
}
