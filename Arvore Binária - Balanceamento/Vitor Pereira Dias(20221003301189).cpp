#include <iostream>

using namespace std;

// Definição da estrutura do nó da árvore binária
struct No {
    int data;
    No* filhoEsquerda;
    No* filhoDireita;
};

// Função para criar um novo nó
No* createNode(int data) {
    No* newNode = new No();
    if (!newNode) {
        cout << "Erro ao alocar memória!\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->filhoEsquerda = newNode->filhoDireita = nullptr;
    return newNode;
}

// Função para calcular a altura de uma árvore
int getHeight(No* root) {
    if (root == nullptr) {
        return 0;
    }
    int filhoEsquerdaHeight = getHeight(root->filhoEsquerda);
    int filhoDireitaHeight = getHeight(root->filhoDireita);
    return 1 + max(filhoEsquerdaHeight, filhoDireitaHeight);
}

// Função para verificar se a árvore está balanceada em altura
bool isBalanced(No* root) {
    if (root == nullptr) {
        return true;
    }
    int filhoEsquerdaHeight = getHeight(root->filhoEsquerda);
    int filhoDireitaHeight = getHeight(root->filhoDireita);
    int diff = <link>abs</link>(filhoEsquerdaHeight - filhoDireitaHeight);
    if (diff <= 1 && isBalanced(root->filhoEsquerda) && isBalanced(root->filhoDireita)) {
        return true;
    }
    return false;
}

int main() {
    // Criação da árvore de exemplo
    No* raiz;
    raiz = createNode(1);
    raiz->filhoEsquerda = createNode(2);
    raiz->filhoDireita = createNode(3);
    raiz->filhoEsquerda->filhoEsquerda = createNode(4);
    raiz->filhoEsquerda->filhoDireita = createNode(5);

    // Verificação se a árvore está balanceada
    if (isBalanced(raiz)) {
        cout << "A árvore está balanceada em altura.\n";
    } else {
        cout << "A árvore não está balanceada em altura.\n";
    }

    return 0;
}