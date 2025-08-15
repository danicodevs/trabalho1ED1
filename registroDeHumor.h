#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef REGISTRO_DE_HUMOR_H
#define REGISTRO_DE_HUMOR_H

typedef enum {FELIZ, TRISTE, ANSIOSO, CANSADO, MOTIVADO, ESTRESSADO, NEUTRO} Humor;

typedef struct registroDeHumor
{
    int id;
    char data[11];
    Humor humor;
    char motivo[100];
    int notaDoDia;

} RegistroDeHumor;

RegistroDeHumor*criarRegistro(const char data[11],Humor humor, const char motivo[100], int notaDoDia);

void imprimirRegistro(const RegistroDeHumor* registro);

void liberarRegistro(RegistroDeHumor* registro);

void atualizarUltimoId(int novoId);

#endif