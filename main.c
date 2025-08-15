#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registroDeHumor.h"
#include "listaDuplamenteEnc.h"

int main() {
    NoLista *lista;
    criarLista(&lista);
    int opcao, id, x;
    Humor humor;
    carregarDoArquivo(&lista, "registros.txt");

    do {
        printf("\n---MENU---\n");
        printf("1 - Adicionar novo registro\n");
        printf("2 - Remover registro por id\n");
        printf("3 - Buscar por humor\n");
        printf("4 - Imprimir todos os registros\n");
        printf("5 - Mostrar média da notaDoDia\n");
        printf("6 - Mostrar humor mais frequente\n");
        printf("7 - Mostrar os motivos do humor\n");
        printf("8 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1: {
            char data[11], motivo[100];
            int humorInt, nota;
            printf("Data (DD/MM/AAAA): ");
            scanf("%s", data);
            printf("Humor (0 = FELIZ, 1 = TRISTE, 2 = ANSIOSO, 3 = CANSADO, 4 = MOTIVADO, 5 = ESTRESSADO, 6 = NEUTRO): ");
            scanf("%d", &humorInt);
            printf("Motivo: ");
            scanf(" %[^\n]", motivo);
            printf("Nota (0-10): ");
            scanf("%d", &nota);
            RegistroDeHumor* reg = criarRegistro(data, (Humor)humorInt, motivo, nota);
            inserirNoFim(&lista, reg);
            liberarRegistro(reg);
            break;
        }
        case 2: {
            printf("digite o id do registro que deseja remover:");
            scanf("%d", &id);
            removerPorId(&lista, id);
            break;
        }
        case 3: { // Buscar por humor
            int humorInt;
            printf("Digite o humor para buscar (0 = FELIZ, 1 = TRISTE, 2 = ANSIOSO, 3 = CANSADO, 4 = MOTIVADO, 5 = ESTRESSADO, 6 = NEUTRO): ");
            scanf("%d", &humorInt);
            if (humorInt >= FELIZ && humorInt <= NEUTRO) {
                buscarPorHumor(&lista, (Humor)humorInt);
            }
            else {
                printf("Humor invalido.\n");
            }
            break;
        }
        case 4: {
            imprime(&lista);
            break;
        }
        case 5: {
            int x;
            printf("Digite quantos dos dias deseja calcular a media: ");
            scanf("%d", &x);
            calcularMediaNotas(&lista, x);
            break;
        }
        case 6: {
            int x;
            printf("Digite quantos dias deseja saber o humor mais frequente: ");
            scanf("%d", &x);
            humorMaisFrequente(&lista, x);
            break;
        }
        case 7: {
            int humorInt;
            printf("Digite o humor que deseja ver os motivos(0 = FELIZ, 1 = TRISTE, 2 = ANSIOSO, 3 = CANSADO, 4 = MOTIVADO, 5 = ESTRESSADO, 6 = NEUTRO): ");
            scanf("%d", &humorInt);
            if (humorInt >= FELIZ && humorInt <= NEUTRO) {
                mostrarMotivosPorHumor(&lista, (Humor)humorInt);
            } else {
                printf("Valor invalido.\n");
            }
            break;
        }
        case 8: {
            printf("Saindo...\n");
            salvarEmArquivo(lista, "registros.txt");
            liberarLista(&lista);
            break;
        }
        default: {
            printf("Opção inválida!\n");
        }
        }
    } while (opcao != 8);
    return 0;
}