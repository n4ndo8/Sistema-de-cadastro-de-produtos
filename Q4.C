#include <stdio.h>

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
    Produto estoque[3] = {
        {1, "Teclado",   250.00f},
        {2, "Mouse",      89.90f},
        {3, "Monitor",  1200.00f}
    };

    printf("=== Estoque original ===\n");
    imprimir_produtos(estoque, 3);

    aplicar_desconto(&estoque[1], 10.0f);

    printf("\n=== Apos desconto de 10%% no Mouse ===\n");
    imprimir_produtos(estoque, 3);

    return 0;
}