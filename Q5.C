#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int   id;
    char  nome[30];
    float preco;
} Produto;

void aplicar_desconto(Produto *p, float percentual) {
    p->preco *= (1.0f - percentual / 100.0f);
}

void imprimir_produtos(Produto *ptr, int qtd) {
    printf("%-5s %-20s %s\n", "ID", "Nome", "Preco");
    printf("-------------------------------\n");
    for (int i = 0; i < qtd; i++) {
        printf("%-5d %-20s R$ %.2f\n",
               (ptr + i)->id,
               (ptr + i)->nome,
               (ptr + i)->preco);
    }
}

int main() {
    int qtd;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &qtd);

    /* Aloca na heap espaco para 'qtd' structs Produto */
    Produto *estoque = (Produto *) malloc(qtd * sizeof(Produto));

    if (estoque == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return 1;
    }

    /* Preenche usando aritmetica de ponteiros */
    for (int i = 0; i < qtd; i++) {
        (estoque + i)->id = i + 1;
        printf("\nProduto %d\n", i + 1);
        printf("  Nome:  ");
        scanf(" %29[^\n]", (estoque + i)->nome);
        printf("  Preco: ");
        scanf("%f", &(estoque + i)->preco);
    }

    printf("\n=== Estoque cadastrado ===\n");
    imprimir_produtos(estoque, qtd);

    /* Libera a memoria alocada */
    free(estoque);
    estoque = NULL;

    return 0;
}