# 🧭 Ponteiros em C — Do Básico à Alocação Dinâmica

> Série de atividades práticas que constroem, passo a passo, um sistema de gerenciamento de estoque usando os fundamentos de ponteiros em C.

---

## 📋 Sobre o projeto

Este repositório acompanha uma trilha de aprendizado progressiva sobre **ponteiros em C**. Cada atividade incrementa a anterior, partindo de uma simples variável com ponteiro até um sistema completo com alocação dinâmica de memória.

Ao final da série, o programa é capaz de:

- Gerenciar um estoque de produtos com número variável de itens
- Aplicar descontos via funções que recebem ponteiros
- Navegar por arrays usando aritmética de ponteiros
- Alocar e liberar memória na heap com `malloc` e `free`

---

## 🗂️ Estrutura do repositório

```
📦 ponteiros-em-c/
├── ativ1.c   # Ponteiro para float e modificação direta
├── ativ2.c   # Passagem por referência com função void
├── ativ3.c   # Ponteiros para structs e operador ->
├── ativ4.c   # Aritmética de ponteiros em arrays
└── ativ5.c   # Alocação dinâmica com malloc e free
```

---

## 📚 Atividades

### Atividade 1 — Fundamentos de Ponteiros

Declara uma variável `float` para o preço de um produto e a modifica **exclusivamente através de um ponteiro**.

**Conceitos:** declaração de ponteiro, operador `&` (endereço), operador `*` (desreferenciamento).

```c
float preco = 100.0f;
float *ptr = &preco;
*ptr *= 1.10f;  // aplica 10% de aumento
```

---

### Atividade 2 — Passagem por Referência

Encapsula a lógica em uma função `aplicar_desconto` que recebe um ponteiro e altera o valor original na memória, sem retornar nada.

**Conceitos:** funções `void`, passagem por referência, modificação de variável externa via ponteiro.

```c
void aplicar_desconto(float *ptr_preco, float percentual) {
    *ptr_preco *= (1.0f - percentual / 100.0f);
}
```

---

### Atividade 3 — Ponteiros para Structs

Introduz a `struct Produto` com campos `id` e `preco`. A função `aplicar_desconto` é atualizada para receber um ponteiro para a struct e usa o operador `->` para acessar seus campos.

**Conceitos:** `typedef struct`, ponteiro para struct, operador `->`.

```c
typedef struct {
    int   id;
    float preco;
} Produto;

void aplicar_desconto(Produto *p, float percentual) {
    p->preco *= (1.0f - percentual / 100.0f);
}
```

---

### Atividade 4 — Aritmética de Ponteiros em Arrays

Cria um array estático de 3 produtos e introduz a função `imprimir_produtos`, que percorre o array **sem usar colchetes** — apenas aritmética de ponteiros.

**Conceitos:** arrays e ponteiros, decaimento de array, `(ptr + i)->campo`.

```c
void imprimir_produtos(Produto *ptr, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("%d  %s  R$ %.2f\n",
            (ptr + i)->id,
            (ptr + i)->nome,
            (ptr + i)->preco);
    }
}
```

---

### Atividade 5 — Alocação Dinâmica *(pesquisa extra)*

Remove o limite fixo de produtos. O usuário informa a quantidade em tempo de execução, e a memória é alocada dinamicamente na heap com `malloc`. Ao final, liberada com `free`.

**Conceitos:** `malloc`, `free`, heap vs stack, ponteiro nulo, dangling pointer.

```c
Produto *estoque = (Produto *) malloc(qtd * sizeof(Produto));

if (estoque == NULL) {
    printf("Erro: memoria insuficiente.\n");
    return 1;
}

// ... uso do estoque ...

free(estoque);
estoque = NULL;
```

| | Array estático (Ativ. 4) | `malloc` (Ativ. 5) |
|---|---|---|
| Onde vive | Stack | Heap |
| Tamanho | Fixo em compilação | Definido em execução |
| Liberação | Automática | Manual (`free`) |
| Risco | Stack overflow | Memory leak / dangling pointer |

---

## ▶️ Como compilar e executar

Você precisará do **GCC** instalado. Em Linux, macOS ou WSL:

```bash
# Verificar se o GCC está disponível
gcc --version

# Compilar e executar qualquer atividade
gcc ativ1.c -o ativ1 && ./ativ1
gcc ativ2.c -o ativ2 && ./ativ2
gcc ativ3.c -o ativ3 && ./ativ3
gcc ativ4.c -o ativ4 && ./ativ4
gcc ativ5.c -o ativ5 && ./ativ5
```

Prefere testar online? Use o [OnlineGDB](https://www.onlinegdb.com) — selecione **C** como linguagem, cole o código e clique em **Run**.

---

## 🧠 Mapa de conceitos

```
Atividade 1 ──► declaração de ponteiro · & · *
     │
     ▼
Atividade 2 ──► funções void · passagem por referência
     │
     ▼
Atividade 3 ──► struct · typedef · operador ->
     │
     ▼
Atividade 4 ──► arrays · aritmética de ponteiros · (ptr+i)->campo
     │
     ▼
Atividade 5 ──► malloc · free · heap · NULL check
```

---

## 📖 Referências

- [Documentação C — cppreference.com](https://en.cppreference.com/w/c)
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/)
- [CS50 — Ponteiros (Harvard)](https://cs50.harvard.edu/x/)

---

<p align="center">
  Feito com 💙 para aprender C do jeito certo — entendendo a memória.
</p>
