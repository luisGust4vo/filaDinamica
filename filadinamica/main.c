#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
int dado;
struct NO *prox;
}NO;

typedef struct FILA{
  NO *inicio;
  NO *fim;
}FILA;

void inicializar(FILA *f){
  f -> inicio = NULL;
  f->fim = NULL;
}

void enfileirar(int dado, FILA *f){
  NO *ptr = (NO*)malloc(sizeof(NO));
  if(ptr == NULL){
    printf("ERRO alocacao!!");
  }else{
    ptr -> dado = dado;
    ptr -> prox = NULL;
    if( f -> inicio == NULL){
      f -> inicio = ptr;
    }
    f -> fim = ptr;
  }
  return;
}

int desifileirar(FILA *f){
  NO *ptr = f-> inicio;
  int dado;
  if(ptr != NULL){
    f -> inicio = ptr -> prox;
    ptr -> prox =NULL;
    dado = ptr -> dado;
    free(ptr);
    if(f -> inicio == NULL){
      f-> fim = NULL;
    }
    return dado;
  }else{
   printf("FILA VAZIA!");
    return
  }
};

void imprimeFila(FILA *f){
  NO *ptr = f -> inicio;
  if(ptr != NULL){
    while(ptr!= NULL){
      printf("%d",ptr -> dado);
      ptr=ptr -> prox;
    }
  }else{
    printf("Fila vazia");
    return;
  }
}

int main(void){
  FILA *f1 = (FILA*)malloc(sizeof(FILA));
  if(f1 == NULL){
    printf("ERRO de Alocacao");
    exit(-1);
  }else{
    inicializar(f1);
    enfileirar(10,f1);
    enfileirar(20,f1);
    enfileirar(30,f1);

    imprimeFila(f1);
  }



  return 0;
}
