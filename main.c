#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registroDeHumor.h"
#include "listaDuplamenteEnc.h"

int main(void)
{
    RegistroDeHumor* reg1 = criarRegistro("01/01/2023", 0, "recebi uma prova boa", 9);
    imprimirRegistro(reg1);
    liberarRegistro(reg1);
}
