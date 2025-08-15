#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {FELIZ, TRISTE, ANSIOSO, CANSADO, MOTIVADO, ESTRESSADO, NEUTRO} Humor;
static int ultimo_id = 0;
typedef struct registroDeHumor
{
    int id;
    char data[11];
    Humor humor;
    char motivo[100];
    int notaDoDia;

} RegistroDeHumor;

RegistroDeHumor*criarRegistro(const char data[11],Humor humor, const char motivo[100], int notaDoDia){
    RegistroDeHumor* novo = (RegistroDeHumor*)malloc(sizeof(RegistroDeHumor));
    ultimo_id++;
    novo -> id = ultimo_id;
    strncpy(novo -> data, data, 10);
    novo -> data[10] = '\0';
    novo -> humor = humor;
    strncpy(novo -> motivo, motivo, 99);
    novo -> motivo[99] = '\0';
    novo -> notaDoDia = notaDoDia;
    return novo;
}

void atualizarUltimoId(int novoId) {
    if (novoId > ultimo_id) {
        ultimo_id = novoId;
    }
}

void imprimirRegistro(const RegistroDeHumor* registro) {
    if(registro == NULL) {
        printf("Registro inválido.\n");
        return;
    } else {
        printf("id: %d\n", registro -> id);
        printf("Data: %s\n", registro -> data);
        printf("Humor: ");
        switch (registro -> humor){
        case FELIZ:
            printf("Feliz\n");
            break;
        case TRISTE:
            printf("Triste\n");
            break;
        case ANSIOSO:
            printf("Ansioso\n");
            break;
        case CANSADO:
            printf("Cansado\n");
            break;
        case MOTIVADO:
            printf("Motivado\n");
            break;
        case ESTRESSADO:
            printf("Estressado\n");
            break;
        case NEUTRO:
            printf("Neutro\n");
            break;
        default:
            printf("Humor inválido");
            break;
        }
        printf("Motivo: %s\n", registro -> motivo);
        printf("Nota do dia: %d\n", registro -> notaDoDia);
    }
    
}
void liberarRegistro(RegistroDeHumor* registro){
    if(registro != NULL) {
        free(registro);
    }
}