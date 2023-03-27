#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAM 4

typedef struct ficha_pessoal
{
    char tarefas[TAM][100];
    bool concluido[TAM];
    bool deletado[TAM];
} TFicha;


/* Função para  ler e salvar a tarefa*/
void tarefas(TFicha * ptr1){
    for (int i = 0; i < TAM; i++) {
        printf("\n[%d] [Digite sua tarefa]\n", i);
        scanf(" %[^\n]", ptr1->tarefas[i]);  // ler uma linha completa de texto
        if (strcmp(ptr1->tarefas[i], "") == 0){ // compara a string com uma string vazia
            i--; // decrementa o contador para inserir novamente na mesma posição
            printf("\nValor invalido\n");
        }
    }
}

// Função para concluir tarefa ou colocar como n concluida novamente
void concluir_tarefa(TFicha *ptr1, int indice_tarefa){
    if (ptr1->concluido[indice_tarefa] == true){
        ptr1->concluido[indice_tarefa] = false;
    }else{
        ptr1->concluido[indice_tarefa] = true;
    }
}

// Função para deletar tarefa
void deletar_tarefa(TFicha *ptr1, int indice_tarefa){
    ptr1->deletado[indice_tarefa] = true;
    ptr1->concluido[indice_tarefa] = false;
}

// Função para imprimir tarefa.
void imprimir_tarefas(TFicha *ptr1) {
    for (int i = 0; i < TAM; i++) {
        if (ptr1->deletado[i]) {
            printf("\n[Tarefa %d] (tarefa deletada)\n", i);
        } else {
            printf("\n[Tarefa %d] %s ", i, ptr1->tarefas[i]);
            if (ptr1->concluido[i]) {
                printf("(concluída)\n");
            } else {
                printf("(não concluída)\n");
            }
        }
    }
}

// Função para deixar todos como não concluido  e não deletado.
void inicializar_tudo(TFicha * ptr1){
    for (int i = 0; i < TAM; i++) {
        ptr1->concluido[i] = false;
        ptr1->deletado[i] = false;
    }
}

int main() {
    TFicha *ptr1 = malloc(sizeof(TFicha));  // alocar memória para ptr1

    if (ptr1 == NULL){
        printf("Erro: falha ao alocar memória.\n");
        exit(ptr1);
    }
    inicializar_tudo(ptr1); // função para deixar todos como não concluido e não deletados.
    int resp[2];

    tarefas(ptr1);

    do{
        printf("\n----SISTEMA----\n\nDeseja imprimir suas tarefas? [2] \nDeseja Sair? [1]\nDeseja Concluir alguma tarefa?[3]\nDeletar tarefa[4]\n\n");
        scanf("%d", &resp[0]);   
        switch (resp[0]){
        case 1:
            break;
        case 2:
            imprimir_tarefas(ptr1);
            break;
        case 3:
            imprimir_tarefas(ptr1);
            printf("\nQual voce deseja concluir? [digite numero]: ");
            scanf("%d", &resp[1]);
            concluir_tarefa(ptr1, resp[1]);
            break;
        case 4:
            imprimir_tarefas(ptr1);
            printf("\nQual tarefa voce deseja deletar? [digite numero]: ");
            scanf("%d", &resp[1]);  // corrigir índice para resp[1]
            deletar_tarefa(ptr1, resp[1]);
            break;
        default:
            printf("\nResposta incorreta!");
            break;
        }
    }while (resp[0] != 1);

    free(ptr1);  // liberar a memória alocada para ptr1

    return 0;
}


