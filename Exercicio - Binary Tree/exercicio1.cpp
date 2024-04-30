#include <iostream>

using namespace std;

// Definição da estrutura do nó da árvore binária
struct No {
    int valor;
    No* esquerda;
    No* direita;
};

// Função auxiliar para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = new No;
    novoNo->valor = valor;
    novoNo->esquerda = nullptr;
    novoNo->direita = nullptr;
    return novoNo;
}

// Função recursiva para calcular a soma dos caminhos raiz-folha
int calcularSomaCaminhos(No* no, int somaAtual) {
    // Se o nó atual for nulo, retorna 0
    if (no == nullptr) {
        return 0;
    }

    // Calcula o valor atualizado da soma
    int novaSoma = somaAtual * 2 + no->valor;

    // Se o nó atual for uma folha, retorna a nova soma
    if (no->esquerda == nullptr && no->direita == nullptr) {
        return novaSoma;
    }

    // Caso contrário, faz a chamada recursiva para os nós filhos
    int somaEsquerda = calcularSomaCaminhos(no->esquerda, novaSoma);
    int somaDireita = calcularSomaCaminhos(no->direita, novaSoma);

    // Retorna a soma dos caminhos da esquerda e da direita
    return somaEsquerda + somaDireita;
}

int main() {
    // Constrói a árvore binária do exemplo
    No* raiz = criarNo(1);
    raiz->esquerda = criarNo(0);
    raiz->direita = criarNo(1);
    raiz->esquerda->esquerda = criarNo(0);
    raiz->esquerda->direita = criarNo(0);
    raiz->direita->esquerda = criarNo(0);
    raiz->direita->direita = criarNo(1);
    raiz->esquerda->esquerda->esquerda = criarNo(1);
    raiz->esquerda->esquerda->direita = criarNo(0);
    raiz->esquerda->direita->esquerda = criarNo(0);
    raiz->esquerda->direita->direita = criarNo(1);
    raiz->direita->direita->esquerda = criarNo(0);
    raiz->direita->direita->direita = criarNo(1);

    // Calcula a soma dos caminhos raiz-folha
    int soma = calcularSomaCaminhos(raiz, 0);

    // Imprime o resultado
    cout << "A soma dos números binários representados pelos caminhos raiz-folha é: " << soma << endl;

    return 0;
}