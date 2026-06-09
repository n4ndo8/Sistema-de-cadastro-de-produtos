#include <stdio.h>

void aplicar_desconto(float *ptr_preco, float percentual) {
    *ptr_preco *= (1.0f - percentual / 100.0f);
}

int main() {
    float preco = 100.0f;

    aplicar_desconto(&preco, 10.0f);

    printf("Preço com desconto: %.2f\n", preco);

    return 0;
}