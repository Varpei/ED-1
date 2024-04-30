#include <iostream>

using namespace std;

// Definição da estrutura do nó da árvore binária
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Erro ao alocar memória!\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Função para calcular a altura de uma árvore
int getHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// Função para verificar se a árvore está balanceada em altura
bool isBalanced(Node* root) {
    if (root == nullptr) {
        return true;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    int diff = <link>abs</link>(leftHeight - rightHeight);
    if (diff <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return true;
    }
    return false;
}

int main() {
    // Criação da árvore de exemplo
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Verificação se a árvore está balanceada
    if (isBalanced(root)) {
        cout << "A árvore está balanceada em altura.\n";
    } else {
        cout << "A árvore não está balanceada em altura.\n";
    }

    return 0;
}