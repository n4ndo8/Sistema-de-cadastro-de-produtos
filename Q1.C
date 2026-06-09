#include <stdio.h>

int main() {
    float preco = 100.0f;
    float *ptr = &preco;

    /* Aplica 10% de aumento exclusivamente pelo ponteiro */
    *ptr *= 1.10f;

    /* Imprime a variável original para comprovar a alteração */
    printf("Preço atualizado: %.2f\n", preco);

    return 0;
}