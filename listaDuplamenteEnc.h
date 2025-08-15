#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LISTA_DUPLAMENTE_ENC_H
#define LISTA_DUPLAMENTE_ENC_H

#include "registroDeHumor.h"
typedef struct noLista{
  RegistroDeHumor tad;
  struct noLista* ant;
  struct noLista* prox;
}NoLista;

void criarLista(NoLista** l);

int estaVazia(NoLista** l);

void inserirElemento (NoLista** l, RegistroDeHumor* v);

void imprime(NoLista** l);

NoLista* ultimoElemento (NoLista** l);

void inserirNoFim(NoLista** l, RegistroDeHumor* v);

void removerPorId(NoLista** l, int id);

void buscarPorHumor(NoLista**l, Humor humor);

void liberarLista(NoLista** l);

void calcularMediaNotas(NoLista** l, int x);

void humorMaisFrequente(NoLista** l, int x);

void mostrarMotivosPorHumor(NoLista** l, Humor x);

void salvarEmArquivo(NoLista* lista, const char* nomeArquivo);

void carregarDoArquivo(NoLista** lista, const char* nomeArquivo);

#endif