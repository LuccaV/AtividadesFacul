#include <stdio.h>
#define MAX 50

int inserirOrdenado(int v[], int n, int valor) {
    if (n >= MAX) {
        printf("o vetor ja ta cheio! nao e possivel inserir mais\n");
        return n;
    }
    int i = n - 1;
    while (i >= 0 && v[i] > valor) {
        v[i + 1] = v[i];
        i--;
    }
    v[i + 1] = valor;
    return n + 1;
}

void imprimirVetor(int v[], int n) {
    if (n == 0) {
        printf("vetor vazio\n");
        return;
    }
    printf("vetor atual (%d elementos): ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int buscaBinaria(int v[], int n, int valor) {
    int inicio = 0, fim = n - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (v[meio] == valor) return meio;
        else if (v[meio] < valor) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

int removerElemento(int v[], int n, int valor) {
    int pos = buscaBinaria(v, n, valor);
    if (pos == -1) {
        printf("o valor %d não foi encontrado no vetor\n", valor);
        return n;
    }
    for (int i = pos; i < n - 1; i++) {
        v[i] = v[i + 1];
    }
    printf("o valor %d foi removido!\n", valor);
    return n - 1;
}

int main() {
    int vetor[MAX];
    int tamanho, qtd, valor, opcao;

    do {
        printf("digite o tamanho do vetor (minimo 3 - maximo 50): ");
        scanf("%d", &tamanho);
    } while (tamanho < 3 | tamanho > MAX);

    do {
        printf("quantos valores deseja inserir inicialmente (ate %d): ", tamanho);
        scanf("%d", &qtd);
    } while (qtd < 0 | qtd > tamanho);

    int n = 0;
    for (int i = 0; i < qtd; i++) {
        printf("digite o %d valor: ", i + 1);
        scanf("%d", &valor);
        n = inserirOrdenado(vetor, n, valor);
    }

    do {
        printf("\n menu de opcoes:\n");
        printf("1 - imprimir o vetor\n");
        printf("2 - consultar posicao de um elemento\n");
        printf("3 - remover um elemento\n");
        printf("4 - inserir um novo valor\n");
        printf("0 - sair\n");
        printf("escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimirVetor(vetor, n);
                break;
            case 2:
                printf("digite o valor a ser consultado: ");
                scanf("%d", &valor);
                int pos;
                pos = buscaBinaria(vetor, n, valor);
                if (pos == -1) printf("valor %d nao encontrado no vetor\n", valor);
                else printf("valor %d encontrado na posicao %d.\n", valor, pos);
                break;
            case 3:
                printf("digite o valor a ser removido: ");
                scanf("%d", &valor);
                n = removerElemento(vetor, n, valor);
                break;
            case 4:
                printf("digite o valor a ser inserido: ");
                scanf("%d", &valor);
                n = inserirOrdenado(vetor, n, valor);
                printf("valor %d inserido com sucesso!\n", valor);
                break;
            case 0:
                printf("encerrando o programa\n");
                break;
            default:
                printf("opcao invalida! tente novamente\n");
        }
    } while (opcao != 0);

    return 0;
}