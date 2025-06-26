# Sistema de Gerenciamento de Humor Diário
Trabalho Prático 1 - Estruturas de Dados I   
Link repositório: [https://github.com/danicodevs/trabalho1ED1](https://github.com/danicodevs/trabalho1ED1)
## 📁 Estrutura do Projeto

### Arquivos Principais:
1. **`registroDeHumor.h`/`.c`**  
   - Define a estrutura `RegistroDeHumor` com:
     - `id`, `data`, `humor` (enum), `motivo`, `notaDoDia`  
   - Funções:
     - `criarRegistro()`: Aloca e preenche um novo registro
     - `imprimirRegistro()`: Imprime o registro
     - `liberarRegistro()`: Libera memória alocada do registro

2. **`listaDuplamenteEnc.h`/`.c`**  
   - Implementa uma lista duplamente encadeada com:
     - Inserção no fim (`inserirNoFim`) para seguir a ordem de inserção da lista
     - Remoção por ID (`removerPorId`)
     - Consultas:
       - `buscarPorHumor`: Filtra e imprime todos os registros por humor
       - `calcularMediaNotas`: Média das notas dos últimos `x` dias
       - `humorMaisFrequente`: Analisa e imprime o humor mais frequente da lista
       - `mostrarMotivosPorHumor`: Lista motivos para um humor específico

3. **`main.c`**  
   - Menu interativo:
     ```
     1 - Adicionar novo registro
     2 - Remover registro por id
     3 - Buscar por humor
     4 - Imprimir todos os registros
     5 - Mostrar media da notaDoDia
     6 - Mostrar humor mais frequente
     7 - Mostrar os motivos do humor
     8 - Sair
     ```


## 📝 Instruções de uso

### 1. Abra seu terminal e entre nessa pasta ./Daniel-de-Paula-Cardoso-Duplamente-Encadeado/
### 2. Execute o comando ```make```, o programa será compilado e executado automaticamente.

## 🚀 Mais projetos em
<div align="left" style="margin-top: 20px;">
  <a href="https://github.com/danicodevs/"><img src="https://img.shields.io/badge/-GITHUB-black?style=for-the-badge&logo=github&logoColor=white" alt="GitHub Badge"></a>
</div>