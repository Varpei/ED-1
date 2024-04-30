#include <iostream>

using namespace std;

struct No {
    int dado;
    No* prox = nullptr;
};

No* identificarCiclo(No* inicio) {

    if (inicio == nullptr || inicio->prox == nullptr) {
        return nullptr; // Se a lista estiver vazia ou tiver apenas um elemento, não pode haver um ciclo.
    }

    No* lento = inicio;
    No* rapido = inicio;

    while (rapido != nullptr and rapido->prox != nullptr) {
        lento = lento->prox;         // Iterador lento move-se uma posição
        rapido = rapido->prox->prox;  // Iterador rápido move-se duas posições

        if (lento == rapido) { // Se os iteradores se encontrarem, há um ciclo

            // Encontramos um ciclo, agora vamos encontrar o nó de início do ciclo
            lento = inicio;
            while (lento != rapido) {
                lento = lento->prox;
                rapido = rapido->prox;
            }
            return lento;
        }
    }
    return nullptr;
}

int main() {

    No* inicio = new No{1, nullptr};
    inicio->prox = new No{2, nullptr};
    inicio->prox->prox = new No{3, nullptr};
    inicio->prox->prox->prox = inicio->prox; // Cria um ciclo apontando para o segundo nó

    No* cycleStart = identificarCiclo(inicio);

    if (cycleStart != nullptr) {
        cout << "O ciclo comeca no elemento com valor: " << cycleStart->dado << endl;
    } else {
        cout << "Nao ha ciclo na lista encadeada." << endl;
    }
    return 0;
}
