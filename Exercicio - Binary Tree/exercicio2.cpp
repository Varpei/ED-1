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

// Função para verificar se existe um caminho com a soma especificada
bool caminhoComSoma(No* no, int somaAtual, int somaAlvo) {
    // Se o nó atual for nulo, retorna falso
    if (no == nullptr) {
        return false;
    }

    // Calcula o valor atualizado da soma
    int novaSoma = somaAtual + no->valor;

    // Se o nó atual for uma folha e a soma for igual ao alvo, retorna verdadeiro
    if (no->esquerda == nullptr && no->direita == nullptr && novaSoma == somaAlvo) {
        return true;
    }

    // Caso contrário, faz a chamada recursiva para os nós filhos
    bool caminhoEsquerda = caminhoComSoma(no->esquerda, novaSoma, somaAlvo);
    bool caminhoDireita = caminhoComSoma(no->direita, novaSoma, somaAlvo);

    // Retorna verdadeiro se encontrou um caminho com a soma alvo em algum dos nós filhos
    return caminhoEsquerda || caminhoDireita;
}

int main() {
    // Constrói a árvore binária do exemplo
    No* raiz = criarNo(100);
    raiz->esquerda = criarNo(200);
    raiz->direita = criarNo(300);
    raiz->esquerda->esquerda = criarNo(50);
    raiz->esquerda->direita = criarNo(150);
    raiz->direita->esquerda = criarNo(400);
    raiz->direita->direita = criarNo(500);
    raiz->esquerda->direita->esquerda = criarNo(50);
    raiz->esquerda->direita->direita = criarNo(100);
    raiz->direita->esquerda->esquerda = criarNo(200);
    raiz->direita->esquerda->direita = criarNo(200);

    // Soma alvo
    int somaAlvo = 591;

    // Verifica se existe um caminho com a soma alvo
    bool existeCaminho = caminhoComSoma(raiz, 0, somaAlvo);

    // Imprime o resultado
    if (existeCaminho) {
        cout << "Existe um caminho da raiz à folha com a soma " << somaAlvo << endl;
    } else {
        cout << "Não existe um caminho da raiz à folha com a soma " << somaAlvo << endl;
    }

    return 0;
}