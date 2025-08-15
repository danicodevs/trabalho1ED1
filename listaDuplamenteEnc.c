#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registroDeHumor.h"

typedef struct noLista{
  RegistroDeHumor tad;
  struct noLista* ant;
  struct noLista* prox;
}NoLista;

void criarLista(NoLista** l){
  *l = NULL;
}

int estaVazia(NoLista** l){
  return (*l == NULL);
}

void inserirElemento (NoLista** l, RegistroDeHumor* v) {
	NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
	if (novo != NULL) {
		novo -> tad = *v;
		novo -> ant = NULL;
	  if (!estaVazia(l)) {
		  novo -> prox = *l;
		  (*l) -> ant = novo;
		  *l = novo;
    } else {
      *l = novo; 
      (*l) -> prox = NULL;
    }
  } else {
    printf("nao foi possivel alocar memoria");
  }
}

void imprime(NoLista** l) {
  if(!estaVazia(l)){
    for (NoLista* p = *l;p != NULL; p = p -> prox) {
      imprimirRegistro(&(p -> tad));
      printf("\n");
    }
  } else {
    printf("Lista vazia!\n");
  }
}

NoLista* ultimoElemento (NoLista** l) {
	NoLista* p = *l;
  if (!estaVazia(l)) {
    while (p -> prox != NULL) {
      p = p -> prox;
    }
    return p;
  }else {
    printf("Lista vazia!");
  }
  return NULL;
}

void liberarLista(NoLista** l) {
    NoLista* atual = *l;
    while (atual != NULL) {
        NoLista* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *l = NULL;
}

void inserirNoFim(NoLista** l, RegistroDeHumor* v) {
	NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
	if (novo != NULL) {
		novo -> tad = *v;
		novo -> prox = NULL;
	  if (estaVazia(l)) {
		  novo -> ant = NULL;
      *l = novo;
    } else {
      NoLista* ultimo = ultimoElemento(l);
      ultimo -> prox = novo;
      novo -> ant = ultimo;
    }
  } else {
    printf("nao foi possivel alocar memoria");
  }
}
void removerPorId(NoLista** l, int id) {
  NoLista* p = *l;
  for(p; p != NULL; p = p -> prox) {
    if (p -> tad.id == id) {
      if(p -> ant != NULL) {
        p -> ant -> prox = p -> prox;
      } else {
        *l = p -> prox;
      }
      if(p -> prox != NULL) {
        p -> prox -> ant = p -> ant;
      }
      free(p);
    }
  }
}

void buscarPorHumor(NoLista**l, Humor humor) {
  if(estaVazia(l)) {
    printf("Lista vazia\n");
    return;
  }
  int encontrou = 0;
  NoLista*p = *l;
  printf("\n === Registro(s) com humor: ");
  switch (humor) {
    case FELIZ: printf("FELIZ ===\n"); break;
    case TRISTE:printf("TRISTE ===\n"); break;
    case ANSIOSO: printf("ANSIOSO ===\n"); break;
    case CANSADO: printf("CANSADO ===\n"); break;
    case MOTIVADO: printf("MOTIVADO ===\n"); break;
    case ESTRESSADO: printf("ESTRESSADO ===\n"); break;
    case NEUTRO: printf("NEUTRO ===\n"); break;
    default: printf("DESCONHECIDO ===\n"); break;
  }
  for (p; p != NULL; p = p-> prox) {
    if(p -> tad.humor == humor) {
      imprimirRegistro(&(p -> tad));
      printf("----------------\n");
      encontrou = 1;
    }
  }
  if(!encontrou) {
    printf("Nenhum registro encontrado com esse humor. \n");
  }  
}

void calcularMediaNotas(NoLista** l, int x) {
  if(estaVazia(l)) {
    printf("Lista vazia!\n");
    return;
  } 
  NoLista* p = ultimoElemento(l);
  int cont = 0;
  float soma = 0.0;
  for (p, cont; p != NULL && cont < x; p = p -> ant, cont++) {
    soma += p -> tad.notaDoDia;
  }
  if (cont == 0) {
    printf("Nenhum registro encontrado");
  }
  float media = soma/cont;
  printf("Media da nota dos ultimos %d dias e: %.2f\n", cont, media);  
  return;
}

void humorMaisFrequente(NoLista** l, int x) {
  if(estaVazia(l)) {
    printf("Lista Vazia\n");
    return;
  }
  int humor[7] = {0};
  const char* nomesHumor[] = {"Feliz", "Triste", "Ansioso", "Cansado", "Motivado", "Estressado", "Neutro"};
  NoLista* p = ultimoElemento(l);
  int cont = 0;
  for (p, cont; p != NULL && cont < x; p = p -> ant, cont++) {
    humor[p -> tad.humor]++;
  }
  int maisFreq = 0;
  for (int i = 1; i < 7; i++){
    if (humor[i] > humor[maisFreq]) {
      maisFreq = i;
    }
  }
  printf("o humor mais frequente nos ultimos %d dias e: %s, aparencendo %d vezes\n", cont, nomesHumor[maisFreq], humor[maisFreq]);
}

void mostrarMotivosPorHumor(NoLista** l, Humor x) {
  if(estaVazia(l)) {
    printf("Lista vazia!");
    return;
  }
  const char* nomesHumor[] = {"Feliz", "Triste", "Ansioso", "Cansado", "Motivado", "Estressado", "Neutro"};
  int encontrou = 0;
  printf("\n=== Motivos para o humor: %s ===\n", nomesHumor[x]);
  NoLista* p = *l;
  for (p; p != NULL; p = p -> prox) {
    if (p -> tad.humor == x) {
      printf("Data: %s | Motivo: %s\n", p ->tad.data,p->tad.motivo);
      encontrou = 1;
    }
  }
  if (encontrou == 0) {
    printf("Nao ha registros com esse humor. \n");
  }
}

void salvarEmArquivo(NoLista* lista, const char* nomeArquivo) {
    FILE* fp = fopen(nomeArquivo, "w");
    if (!fp) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return;
    }
    for (NoLista* p = lista; p != NULL; p = p->prox) {
        fprintf(fp, "%d;%s;%d;%s;%d\n",
            p->tad.id,
            p->tad.data,
            p->tad.humor,
            p->tad.motivo,
            p->tad.notaDoDia);
    }
    fclose(fp);
}

void carregarDoArquivo(NoLista** lista, const char* nomeArquivo) {
    FILE* fp = fopen(nomeArquivo, "r");
    if (!fp) {
        // Se não existir, apenas ignora
        return;
    }
    char linha[256];
    while (fgets(linha, sizeof(linha), fp)) {
        RegistroDeHumor reg;
        char humorStr[10], motivo[100];
        if (sscanf(linha, "%d;%10[^;];%d;%99[^;];%d",
                   &reg.id,
                   reg.data,
                   (int*)&reg.humor,
                   reg.motivo,
                   &reg.notaDoDia) == 5) {
            atualizarUltimoId(reg.id);
            inserirNoFim(lista, &reg);
        }
    }
    fclose(fp);
}
