#include <stdio.h>

typedef struct {
    int   id;
    float preco;
} Produto;

void aplicar_desconto(Produto *p, float percentual) {
    p->preco *= (1.0f - percentual / 100.0f);
}

int main() {
    Produto item = {1, 100.0f};

    printf("Antes:  id=%d  preco=%.2f\n", item.id, item.preco);
    aplicar_desconto(&item, 10.0f);
    printf("Depois: id=%d  preco=%.2f\n", item.id, item.preco);

    return 0;
}