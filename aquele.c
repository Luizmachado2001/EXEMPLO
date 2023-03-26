#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAM 4

typedef struct ficha_pessoal
{
    char tarefas[TAM][100];
    bool concluido[TAM];
} TFicha;


/* Função para  ler e salvar a tarefa*/
void tarefas(TFicha * ptr1){
    for (int i = 0; i < TAM; i++) {
        printf("\n[%d] [Digite sua tarefa]\n", i);
        scanf(" %[^\n]", ptr1->tarefas[i]);  // ler uma linha completa de texto
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
void destruir_tarefa(TFicha *ptr1, int indice_tarefa){
    memset(ptr1->tarefas[indice_tarefa], 0, sizeof(tarefas[indice_tarefa]));
    ptr1->concluido[indice_tarefa] = false;
}

/* Função para mostrar tarefa e aonde está dentro do array*/
void imprimir_tarefas(TFicha *ptr1) {
    for (int i = 0; i < TAM; i++) {
        printf("\n[Tarefa %d] %s\n", i, ptr1->tarefas[i]);
        if (ptr1->concluido[i]) {
            printf("(concluída)\n");
        } else {
            printf("não concluída)\n");
        }
    }
}

int main() {
    TFicha *ptr1 = malloc(sizeof(TFicha));  // alocar memória para ptr1

    if (ptr1 == NULL){
        printf("Erro: falha ao alocar memória.\n");
        exit(ptr1);
    }
    int resp = 0, enviar = 0;
    memset(ptr1->concluido, false, sizeof(ptr1->concluido)); // definir valores padrão do array como false
    tarefas(ptr1);

    do{
        printf("\n----SISTEMA----\n\nDeseja imprimir suas tarefas? [2] \nDeseja Sair? [1]\nDeseja Concluir alguma tarefa?[3]\n\n");
        scanf("%d", &resp);   
        switch (resp){
        case 1:
            break;
        case 2:
            imprimir_tarefas(ptr1);
            break;
        case 3:
            imprimir_tarefas(ptr1);
            printf("\nQual voce deseja concluir? [digite numero]: ");
            scanf("%d", &enviar);
            concluir_tarefa(ptr1, enviar);
        default:
            printf("\nResposta incorreta!");
            break;
        }
    }while (resp != 1);

    free(ptr1);  // liberar a memória alocada para ptr1

    return 0;
}
