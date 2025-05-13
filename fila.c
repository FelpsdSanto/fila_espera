#include <stdio.h>
#include <stdlib.h>

#define TAM 10  // Define o tamanho máximo da fila

// Estrutura da fila
typedef struct {
    int dados[TAM]; // Vetor que armazena os pacientes
    int inicio;      // Índice do início da fila
    int fim;         // Índice do fim da fila
} Fila;

// Função para inicializar a fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->inicio == f->fim;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->fim == TAM;
}

// Insere um novo paciente na fila
void enfileirar(Fila *f, int paciente) {
    if (filaCheia(f)) {
        printf("Fila cheia. Não é possível adicionar novo paciente.\n");
    } else {
        f->dados[f->fim] = paciente; // Adiciona no final
        f->fim++;                    // Atualiza a posição do fim
        printf("Paciente %d foi adicionado à fila.\n", paciente);
    }
}

// Remove o paciente do início da fila
void desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia. Nenhum paciente para atender.\n");
    } else {
        int paciente = f->dados[f->inicio]; // Armazena o paciente atual
        f->inicio++; // Avança o início
        printf("Paciente %d foi atendido.\n", paciente);
    }
}

// Exibe a fila atual
void exibirFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
    } else {
        printf("Fila de espera: ");
        for (int i = f->inicio; i < f->fim; i++) {
            printf("%d ", f->dados[i]);
        }
        printf("\n");
    }
}

// Função principal
int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao, paciente, id = 1;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Adicionar paciente\n");
        printf("2. Atender paciente\n");
        printf("3. Exibir fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                enfileirar(&fila, id++); // Pacientes recebem IDs automáticos
                break;
            case 2:
                desenfileirar(&fila);
                break;
            case 3:
                exibirFila(&fila);
                break;
            case 0:
                printf("Encerrando o sistema.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
